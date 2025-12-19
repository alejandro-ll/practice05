#include "bigint.hpp"

std::ostream& operator<<(std::ostream& os, const bigint& bi) {
    return bi.print(os);
}