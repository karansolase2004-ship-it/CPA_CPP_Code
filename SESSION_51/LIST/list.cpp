#include <iostream> 
#include "cpa_list.hpp"
#include "cpa_list_exceptions.hpp"

cpa::dsa::node::node(int _data) : data(_data), prev(0), next(0){
}

void cpa::dsa::list::generic_insert(cpa::dsa::node* start, cpa::dsa::node* mid, 
    cpa::dsa::node* end){
        mid->next = end;
        mid->prev = start; 
        start->next = mid; 
        end->prev = mid; 
}

void cpa::dsa::list::generic_delete(cpa::dsa::node* delete_node){
    delete_node->prev->next = delete_node->next; 
    delete_node->next->prev = delete_node->prev; 
    delete delete_node; 
}

cpa::dsa::node* cpa::dsa::list::search(int search_data){
    for(node* run = head_node->next; run != head_node; run = run->next)
        if(run->data == search_data)
            return run; 
    return 0; 
}

cpa::dsa::list::list() : head_node(new node(0)){
    head_node->prev = head_node; 
    head_node->next = head_node; 
}

cpa::dsa::list::~list(){
    node* run = 0; 
    node* run_next = 0; 

    for(run = head_node->next; run != head_node; run = run_next){
        run_next = run->next; 
        delete run; 
    }
}

void cpa::dsa::list::insert_start(int data){
    generic_insert(head_node, new node(data), head_node->next); 
}

void cpa::dsa::list::insert_end(int data){
    generic_insert(head_node->prev, new node(data), head_node); 
}

void cpa::dsa::list::insert_after(int e_data, int new_data){
    node* e_node = search(e_data);
    if(e_node == 0)
        throw list_invalid_data("insert_after:existing data does not exist");
    generic_insert(e_node, new node(new_data), e_node->next); 
}

void cpa::dsa::list::insert_before(int e_data, int new_data){
    node* e_node = search(e_data);
    if(e_node == 0)
        throw list_invalid_data("insert_after:existing data does not exist");
    generic_insert(e_node->prev, new node(new_data), e_node);
}

int cpa::dsa::list::get_start() const{
    if(empty())
        throw list_empty("get_start():cannot get start of the empty list"); 
    return head_node->next->data; 
}

int cpa::dsa::list::get_end() const {
    if(empty())
        throw list_empty("get_end():cannot get end of the empty list"); 
    return head_node->prev->data; 
}

int cpa::dsa::list::pop_start(){
    if(empty())
        throw list_empty("pop_start():cannot pop start of the empty list"); 
    int data = head_node->next->data; 
    generic_delete(head_node->next); 
    return data; 
}

int cpa::dsa::list::pop_end(){
    if(empty())
        throw list_empty("pop_end():cannot pop end of the empty list"); 
    int data =  head_node->prev->data; 
    generic_delete(head_node->prev); 
    return data; 
}

void cpa::dsa::list::remove_start(){
    if(empty())
        throw list_empty("remove_start():cannot remove start of the empty list"); 
    generic_delete(head_node->next);
}

void cpa::dsa::list::remove_end(){
    if(empty())
        throw list_empty("remove_end():cannot remove end of the empty list");
    generic_delete(head_node->prev);  
}

void cpa::dsa::list::remove_data(int r_data){
    node* d_node = search(r_data); 
    if(d_node == 0)
        throw list_invalid_data("remove_data():data not found"); 
    generic_delete(d_node); 
}

bool cpa::dsa::list::find(int f_data) const {
    node* f_node = const_cast<cpa::dsa::list*>(this)->search(f_data);
    return f_node != 0; 
}

bool cpa::dsa::list::empty() const {
    return head_node->prev == head_node && head_node->next == head_node; 
}

std::size_t cpa::dsa::list::size() const {
    std::size_t n = 0; 
    for(node* run = head_node->next; run != head_node; run = run->next)
        n += 1; 
    return n;
}

std::ostream& cpa::dsa::operator<<(std::ostream& os, const list& list_object){
    os << "[START]<->"; 
    for(
        cpa::dsa::node* run = list_object.head_node->next; 
        run != list_object.head_node; 
        run = run->next 
    )
        os << "[" << run->data << "]<->"; 

    os << "[END]" << std::endl; 

    return os; 
}


