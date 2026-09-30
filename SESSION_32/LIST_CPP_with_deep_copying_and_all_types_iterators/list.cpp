#include "list.hpp"

// ---------------- class node ----------------//

// get_node(data) == new node(data) + node::node(data)
node::node(int _data) : data(_data), prev(0), next(0){

}

// ---------------- class list ----------------//

// create_list() == get_node(0) + list::list()
list::list() : head_node(new node){
    head_node->prev = head_node; 
    head_node->next = head_node; 
} 

list::list(const list& other) : head_node(new node){
    head_node->prev = head_node; 
    head_node->next = head_node; 

    for(
        node* run = other.head_node->next; 
        run != other.head_node; 
        run = run->next 
    )    
        this->insert_end(run->data); 
}

list& list::operator=(const list& other){
    node* run = 0; 
    node* run_next = 0;

    for(
        run = this->head_node->next;
        run != this->head_node;
        run = run_next
        ){
            run_next = run->next;
            delete run;
        }

    /* run = this->head_node->next; 
    while(run != this->head_node)
    {
        run_next = run->next; 
        delete run; 
        run = run_next; 
    }
 */
    this->head_node->prev = this->head_node; 
    this->head_node->next = this->head_node; 

    for(
        node* run = other.head_node->next; 
        run != other.head_node; 
        run = run->next
    )
        this->insert_end(run->data); 

    return *this; 
}

list::~list(){
    node* run = 0; 
    node* run_next = 0; 

    for(run = head_node->next; run != head_node; run = run_next){
        run_next = run->next; 
        delete run; 
    }

    delete head_node; 
}

status_t list::insert_start(data_t new_data){
    generic_insert(head_node, new node(new_data), head_node->next); 
    return SUCCESS; 
}

status_t list::insert_end(data_t new_data){
    generic_insert(head_node->prev, new node(new_data), head_node); 
    return SUCCESS;        
}

status_t list::insert_after(data_t existing_data, data_t new_data){
    node* e_node = 0; 

    e_node = search_node(existing_data); 
    if(e_node == 0)
        return LIST_INVALID_DATA; 

    generic_insert(e_node, new node(new_data), e_node->next); 
    return SUCCESS; 
}

status_t list::insert_before(data_t existing_data, data_t new_data){
    node* e_node = 0; 

    e_node = search_node(existing_data); 
    if(e_node == 0)
        return LIST_INVALID_DATA; 

    generic_insert(e_node->prev, new node(new_data), e_node); 
    return SUCCESS; 
}

status_t list::get_start(data_t* p_start_data){
    if(is_empty())
        return LIST_EMPTY; 
    *p_start_data = head_node->next->data; 
    return SUCCESS; 
}

status_t list::get_end(data_t* p_end_data){
    if(is_empty())
        return LIST_EMPTY;
    *p_end_data = head_node->prev->data; 
    return SUCCESS;
}

status_t list::pop_start(data_t* p_start_data){
    if(is_empty())
        return LIST_EMPTY;
    *p_start_data = head_node->next->data; 
    generic_delete(head_node->next); 
    return SUCCESS; 
}

status_t list::pop_end(data_t* p_end_data){
    if(is_empty())
        return LIST_EMPTY;
    *p_end_data = head_node->prev->data; 
    generic_delete(head_node->prev); 
    return SUCCESS;
}

status_t list::remove_start(){
    if(is_empty())
        return LIST_EMPTY;
    generic_delete(head_node->next); 
    return SUCCESS; 
}

status_t list::remove_end(){
    if(is_empty())
        return LIST_EMPTY;
    generic_delete(head_node->prev); 
    return SUCCESS; 
}

status_t list::remove_data(data_t r_data){
    node* e_node = 0; 

    e_node = search_node(r_data); 
    if(e_node == 0)
        return LIST_INVALID_DATA; 

    generic_delete(e_node); 
    return SUCCESS; 
}

bool list::is_empty() const{
    return head_node->prev == head_node && head_node->next == head_node; 
}

bool list::find(data_t f_data) const{
    node* f_node = 0;

    f_node = search_node(f_data); 
    return (f_node != 0); 
}

len_t list::length() const{
    len_t L = 0; 

    for(node* run = head_node->next; run != head_node; run = run->next)
        L += 1; 
    return L; 
}

std::ostream& operator<<(std::ostream& os, const list& list_object){
    os << "[START]<->"; 
    for(
        node* run = list_object.head_node->next; 
        run != list_object.head_node; 
        run = run->next
    )
        os << "[" << run->data << "]<->"; 

    os << "[END]" << std::endl; 
    return os; 
}

// ---------------- Auxillary Function ----------------//

void list::generic_insert(node* p_start, node* p_mid, node* p_end){
    p_mid->next = p_end; 
    p_mid->prev = p_start; 
    p_start->next = p_mid; 
    p_end->prev = p_mid; 
    
}

void list::generic_delete(node* p_delete_node){
    p_delete_node->prev->next = p_delete_node->next; 
    p_delete_node->next->prev = p_delete_node->prev; 
    delete p_delete_node; 
}

node* list::search_node(data_t search_data) const{
    for(node* run = head_node->next; run != head_node; run = run->next)
        if(run->data == search_data)
            return run; 
    return 0; 
}

// ---------------- iterator ----------------//

list::iterator list::begin() const {
    list::iterator iter(head_node->next); 
    return iter; 
}

list::iterator list::end() const {
    list::iterator iter(head_node); 
    return iter; 
}

list::iterator::iterator(node* _node) : current_node(_node){

}

list::iterator& list::iterator::operator++(){
    current_node = current_node->next; 
    return *this;
}

list::iterator list::iterator::operator++(int){
    list::iterator tmp(current_node); 
    current_node = current_node->next; 
    return tmp; 
}

list::iterator& list::iterator::operator--(){
    current_node = current_node->prev; 
    return *this;
}

list::iterator list::iterator::operator--(int){
    list::iterator tmp(current_node); 
    current_node = current_node->prev; 
    return tmp; 
}

int& list::iterator::operator*(){
    return current_node->data; 
}

bool list::iterator::operator==(const list::iterator& rhs){
    return current_node == rhs.current_node; 
}

bool list::iterator::operator!=(const list::iterator& rhs){
    return current_node != rhs.current_node; 
}

// ---------------- const iterator ----------------//

list::const_iterator list::cbegin() const{
    list::const_iterator iter(head_node->next);
    return iter;
}

list::const_iterator list::cend() const{
    list::const_iterator iter(head_node);
    return iter;
}

list::const_iterator::const_iterator(node* _node) : current_node(_node)
{

}

list::const_iterator& list::const_iterator::operator++(){
    current_node = current_node->next;
    return *this;
}

list::const_iterator list::const_iterator::operator++(int){
    const_iterator tmp(current_node);
    current_node = current_node->next;
    return tmp;
}

list::const_iterator& list::const_iterator::operator--(){
    current_node = current_node->prev;
    return *this;
}

list::const_iterator list::const_iterator::operator--(int){
    const_iterator tmp(current_node);
    current_node = current_node->prev;
    return tmp;
}

int list::const_iterator::operator*(){
    return current_node->data;
}

bool list::const_iterator::operator==(const const_iterator& rhs){
    return current_node==rhs.current_node;
}

bool list::const_iterator::operator!=(const const_iterator& rhs){
    return current_node!=rhs.current_node;
}

// ---------------- reverse iterator ----------------//

list::reverse_iterator list::rbegin() const{
    list::reverse_iterator iter(head_node->prev);
    return iter;
}

list::reverse_iterator list::rend() const{
    list::reverse_iterator iter(head_node);
    return iter;
}

list::reverse_iterator::reverse_iterator(node* _node)
: current_node(_node) 
{

};

list::reverse_iterator& list::reverse_iterator::operator++(){
    current_node = current_node->prev;
    return *this;
}

list::reverse_iterator list::reverse_iterator::operator++(int){
    list::reverse_iterator iter(current_node);
    current_node = current_node->prev;
    return iter;
}

list::reverse_iterator& list::reverse_iterator::operator--(){
    current_node = current_node->next;
    return *this;
}

list::reverse_iterator list::reverse_iterator::operator--(int){
    list::reverse_iterator iter(current_node);
    current_node = current_node->next;
    return iter;
}

int& list::reverse_iterator::operator*(){
    return current_node->data;
}

bool list::reverse_iterator::operator==(const reverse_iterator& rhs){
    return current_node==rhs.current_node;
}

bool list::reverse_iterator::operator!=(const reverse_iterator& rhs){
    return current_node!=rhs.current_node;
}

// ---------------- const reverse iterator ----------------//

list::const_reverse_iterator list::rcbegin()const{
    list::const_reverse_iterator iter(head_node->prev);
    return iter;
}

list::const_reverse_iterator list::rcend() const{
    list::const_reverse_iterator iter(head_node);
    return iter;
}

list::const_reverse_iterator::const_reverse_iterator(node* _node)
: current_node(_node){

}

list::const_reverse_iterator& list::const_reverse_iterator::operator++(){
    current_node = current_node->prev;
    return *this;
}

list::const_reverse_iterator list::const_reverse_iterator::operator++(int){
    list::const_reverse_iterator iter(current_node);
    current_node = current_node->prev;
    return iter;
}

list::const_reverse_iterator& list::const_reverse_iterator::operator--(){
    current_node = current_node->next;
    return *this;
}

list::const_reverse_iterator list::const_reverse_iterator::operator--(int){
    list::const_reverse_iterator iter(current_node);
    current_node = current_node->next;
    return iter;
}

int& list::const_reverse_iterator::operator*(){
    return current_node->data;
}

bool list::const_reverse_iterator::operator==
(const const_reverse_iterator& rhs){
    return current_node==rhs.current_node;
}

bool list::const_reverse_iterator::operator!=
(const const_reverse_iterator& rhs){
    return current_node!=rhs.current_node;
}