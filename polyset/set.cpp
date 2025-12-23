
#include "set.hpp"
#include "searchable_array_bag.hpp"
#include "searchable_tree_bag.hpp"

set::set() {
    _bag = new searchable_array_bag();
}

set::set(const searchable_bag &other){
    _bag = duplicate_bag(&other);
}

set::set(const set &other){
    _bag = duplicate_bag(other._bag);
}

set &set::operator=(const set &other){
    if(this == &other)
        return *this;
    if(_bag != NULL)
        delete_bag_aux();
    _bag = duplicate_bag(other._bag);
    return *this;
}

set::~set(){
    delete_bag_aux();
}

searchable_bag* set::duplicate_bag(const searchable_bag* other){
    if(!other)
    {
        return NULL;
    }

    const searchable_array_bag* arr = dynamic_cast<const searchable_array_bag*>(other);
    if(arr)
    {
        return new searchable_array_bag(*arr);
    }
    const searchable_tree_bag* tree = dynamic_cast<const searchable_tree_bag*>(other);
    if(tree)
    {
        return new searchable_tree_bag(*tree);
    }
    return NULL;
}

void set::delete_bag_aux(){
    
    if(_bag == NULL)
        return;
    searchable_array_bag* arr = dynamic_cast<searchable_array_bag*>(_bag);
    if(arr != NULL) 
    {
        delete arr;
        _bag = NULL;
        return;
    }
    searchable_tree_bag* tree = dynamic_cast<searchable_tree_bag*>(_bag);
    if(tree != NULL)
    {
        delete tree;
        _bag = NULL;
        return;
    }
    _bag = NULL;
    return;
}


