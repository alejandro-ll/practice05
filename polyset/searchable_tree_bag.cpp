

#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag() : tree_bag(){

}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag &other) : tree_bag(other) {}

searchable_tree_bag &searchable_tree_bag::operator=(const searchable_tree_bag &other){
    if(this == &other)
    {
        return *this;
    }
    tree_bag::operator=(other);
    return *this;
}

bool searchable_tree_bag::has(int value) const {
    return has_recursive(tree, value);
}

bool searchable_tree_bag::has_recursive(tree_bag::node *current, int value) const {
    if(!current)
    {
        return false;
    }
    if(current->value == value){
        return true;
    }
    if(value < current->value)
        return has_recursive(current->l, value);
    return has_recursive(current->r, value);
}

searchable_tree_bag::~searchable_tree_bag(){}