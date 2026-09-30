#include "list.hpp"

list::iterator list::begin() const{
    list::iterator iter(head_node->next);
    return iter;
}

list::iterator::iterator(node* _node): current_node(_node){

};

int& list::iterator::operator*(){
    return current_node->data;
}

list::iterator& list::iterator::operator++(){
    current_node = current_node->next;
    return *this;
}

list::iterator list::iterator::operator++(int){
    list::iterator iter(current_node);
    current_node = current_node -> next;
    return iter;
}

list::iterator& list::iterator::operator--(){
    current_node = current_node->prev;
    return *this;
}

list::iterator list::iterator::operator--(int){
    list::iterator iter(current_node);
    current_node = current_node->prev;
    return iter;
}

bool list::iterator::operator==(const iterator& rhs){
    return current_node == rhs.current_node;
}

bool list::iterator::operator!=(const iterator& rhs){
    return current_node != rhs.current_node;
}

list::const_iterator list::cbegin() const{
    list::const_iterator iter(head_node->next);
    return iter;
}

list::const_iterator list::end() const{
    list::const_iterator iter(head_node);
    return iter;
}

list::const_iterator::const_iterator(node* _node): current_node(_node){

};

int list::const_iterator::operator*(){
    current_node->data;
}

list::const_iterator& list::const_iterator::operator++(){
    current_node = current_node->next;
    return *this;
}

list::const_iterator list::const_iterator::operator++(int){
    list::const_iterator iter(current_node->next);
    current_node = current_node -> next;
    return iter;
}

list::const_iterator& list::const_iterator::operator--(){
    current_node = current_node->prev;
    return *this;
}

list::const_iterator list::const_iterator::operator--(int){
    list::const_iterator iter(current_node->prev);
    current_node = current_node -> prev;
    return iter;
}

bool list::const_iterator::operator==(const const_iterator& rhs){
    return current_node == rhs.current_node;
}

bool list::const_iterator::operator!=(const const_iterator& rhs){
    return current_node != rhs.current_node;
}

list::reverse_iterator list::rbegin() const{
    list::reverse_iterator iter(head_node->prev);
    return iter;
}

list::reverse_iterator list::rend() const{
    list::reverse_iterator iter(head_node);
    return iter;
}

list::reverse_iterator::reverse_iterator(node* _node) : current_node(_node){

}

int& list::reverse_iterator::operator*(){
    return current_node->data;
}

list::reverse_iterator& list::reverse_iterator::operator++(){
    current_node = current_node->prev;
    return *this;
}

list::reverse_iterator list::reverse_iterator::operator++(int){
    list::reverse_iterator iter(current_node->prev);
    current_node = current_node->prev;
    return iter;
}

list::reverse_iterator list::reverse_iterator::operator--(){
    current_node = current_node->next;
    return *this;
}

list::reverse_iterator list::reverse_iterator::operator--(){
    list::reverse_iterator iter(current_node->next);
    current_node = current_node->prev;
    return iter;
}

bool list::reverse_iterator::operator==(const reverse_iterator& rhs){
    return current_node == rhs.current_node;
}

bool list::reverse_iterator::operator!=(const reverse_iterator& rhs){
    return current_node != rhs.current_node;
}