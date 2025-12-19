#include <iostream>
#include <vector>
#include <string>
#include <cstddef>
#include <algorithm>

class bigint {
    private:
        std::vector<int> _digits;
        void normalize() {
            while (_digits.size() > 1 && _digits.back() == 0) {
                _digits.pop_back();
            }
        }
        unsigned long long to_uint() const {
            size_t multiplier = 1;
            size_t result = 0;

            for (size_t i = 0; i < _digits.size(); ++i) {
                result += _digits[i] * multiplier;
                multiplier *= 10;
            }
            return result;
        }
        int compare_to(const bigint& other) const {
            if (_digits.size() != other._digits.size()) {
                if (_digits.size() < other._digits.size())
                    return -1;
                else
                    return 1;
            }
            for (size_t i = _digits.size(); i-- > 0;) {
                if (_digits[i] != other._digits[i]) {
                    if (_digits[i] < other._digits[i])
                        return -1;
                    else
                        return 1;
                }
            }
            return 0;
        }
    public:
        bigint() : _digits(1, 0) {}
        bigint(unsigned long long n) {
            if (n == 0) {
                _digits.push_back(0);
            } else {
                while (n > 0) {
                    _digits.push_back(n % 10);
                    n /= 10;
                }
            }
        }
        bigint(const bigint& other) : _digits(other._digits) {}
        bigint& operator=(const bigint& other) {
            if (this != &other) {
                _digits = other._digits;
            }
            return *this;
        }

        bigint operator+(const bigint& other) const {
            bigint tmp = *this;
            tmp += other;
            return tmp;
        }
        bigint& operator+=(const bigint& other) {
            size_t max_size = std::max(_digits.size(), other._digits.size());
            _digits.resize(max_size, 0);

            unsigned int carry = 0;
            for (size_t i = 0; i < max_size; ++i) {
                unsigned long long sum = _digits[i] + (i < other._digits.size() ? other._digits[i] : 0) + carry;
                _digits[i] = sum % 10;
                carry = sum / 10;
            }
            if (carry > 0) {
                _digits.push_back(carry);
            }
            return *this;
        }

        // shift operators
        bigint operator<<(const bigint& other) const {
            return *this << other.to_uint();
        }
        bigint operator<<(unsigned long long n) const {
            bigint tmp = *this;
            tmp <<= n;
            return tmp;
        }
        bigint& operator<<=(const bigint& other) {
            return *this <<= other.to_uint();
        }
        bigint& operator<<=(unsigned long long n) {
            _digits.insert(_digits.begin(), n, 0);
            return *this;
        }

        bigint operator>>(const bigint& other) const {
            return *this >> other.to_uint();
        }
        bigint operator>>(unsigned long long n) const {
            bigint tmp = *this;
            tmp >>= n;
            return tmp;
        }
        bigint& operator>>=(const bigint& other) {
            return *this >>= other.to_uint();
        }
        bigint& operator>>=(unsigned long long n) {
            if (n >= _digits.size()) {
                _digits.clear();
                _digits.push_back(0);
            } else {
                _digits.erase(_digits.begin(), _digits.begin() + n);
            }
            normalize();
            return *this;
        }

        // comparison operators
        bool operator<(const bigint& other) const {
            return compare_to(other) == -1;
        }
        bool operator>(const bigint& other) const {
            return compare_to(other) == 1;
        }
        bool operator==(const bigint& other) const {
            return compare_to(other) == 0;
        }
        bool operator!=(const bigint& other) const {
            return compare_to(other) != 0;
        }
        bool operator<=(const bigint& other) const {
            return compare_to(other) != 1;
        }
        bool operator>=(const bigint& other) const {
            return compare_to(other) != -1;
        }

        // increment operators
        bigint& operator++() {
            *this += bigint(1);
            return *this;
        }
        bigint operator++(int) {
            bigint tmp = *this;
            ++(*this);
            return tmp;
        }

        std::ostream& print(std::ostream& os) const {
            std::vector<int>::const_reverse_iterator rit;
            for (rit = _digits.rbegin(); rit != _digits.rend(); ++rit) {
                os << *rit;
            }
            return os;
        }
};

std::ostream& operator<<(std::ostream& os, const bigint& bi);