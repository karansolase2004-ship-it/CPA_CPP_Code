#include "range_interface.hpp"
#include <iostream>

range::range(int start, int end): n_start(start), n_end(end){
    if(n_start >= n_end){
        std::cout << "Start Must be Less than End" << std::endl;
        exit(EXIT_FAILURE);
    }
}

range::iterator range::begin() const{
    iterator iter(n_start);
    return iter;
}

range::iterator range::end() const{
    iterator iter(n_end);
    return iter;
}

range::iterator::iterator(int current) : current_n(current){
}

int& range::iterator::operator*(){
    return current_n;
}

range::iterator range::iterator::operator++(){
    current_n += 1;
    return *this;
}

range::iterator range::iterator::operator++(int){
    iterator iter(current_n);
    current_n += 1;
    return iter;
}

range::iterator range::iterator::operator--(){
    current_n -= 1;
    return *this;
}

range::iterator range::iterator::operator--(int){
    iterator iter(current_n);
    current_n -= 1;
    return iter;
}

bool range::iterator::operator==(const iterator& rhs){
    return current_n==rhs.current_n;
}

bool range::iterator::operator!=(const iterator& rhs){
    return current_n!=rhs.current_n;
}

