#pragma once
#include "searchable_array_bag.hpp"
#include "searchable_tree_bag.hpp"

class set {
    public:
        set();
        set(const searchable_bag &other);
        set(const set &other);
        set &operator=(const set &other);

        ~set();

        bool has(int value) const{
            return _bag->has(value);
        }
        void insert(int value) {
            if(!has(value))
                _bag->insert(value);
        }

        void insert(int *value, int size) {
            for(int i=0; i < size; ++i)
            {
                insert(value[i]);
            }
        }

        void print() const{
            _bag->print();
        }

        void clear(){
            _bag->clear();
        }

        const searchable_bag& get_bag() const {
            return *_bag;
        }

    private:
        searchable_bag *_bag;
        searchable_bag* duplicate_bag(const searchable_bag* other);
        void delete_bag_aux();
};