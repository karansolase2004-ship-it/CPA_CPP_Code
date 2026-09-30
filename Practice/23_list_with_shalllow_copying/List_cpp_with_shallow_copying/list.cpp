#include "list.hpp"
 
node::node(data_t _data): data(_data), prev(0), next(0){
}

list_info::list_info(): list_size(0), ref_count(1){
}

list::list(): head_node(new node), p_list_info(new list_info){
    head_node->prev = head_node;
    head_node->next = head_node;
};

list::~list(){
    this->p_list_info->ref_count -= 1;
    if(this->p_list_info->ref_count == 0){
    node* run = 0;
    node* run_next = 0;

    for(
        run = head_node->next;
        run != head_node;
        run = run_next 
    )
    {
        run_next = run->next;
        delete run;
    }

    delete head_node;
    delete p_list_info;
    }
};

list::list(const list& other){
    this->p_list_info = other.p_list_info;
    this->head_node = other.head_node;
    this->p_list_info->ref_count += 1;
}

list& list::operator=(const list& other){
    if(this != &other){
        this->p_list_info->ref_count -= 1;
         if(this->p_list_info->ref_count == 0){
    node* run = 0;
    node* run_next = 0;

    for(
        run = head_node->next;
        run != head_node;
        run = run_next 
    )
    {
        run_next = run->next;
        delete run;
    }

    delete head_node;
    delete p_list_info;
    }

    this->p_list_info = other.p_list_info;
    this->head_node = other.head_node;
    this->p_list_info->ref_count += 1;
}

return *this;
}

/* Auxillary Function */

void list::generic_insert(node* p_start, node* p_mid, node* p_end){
    p_start->next = p_mid;
    p_end->prev = p_mid;
    p_mid->prev = p_start;
    p_mid->next = p_end;
};

void list::generic_delete(node* p_delete_node){
    p_delete_node->prev->next = p_delete_node->next;
    p_delete_node->next->prev = p_delete_node->prev;

    delete p_delete_node;
};

node* list::search_node(data_t search_data){
    node* run = 0;

    for(
        run = head_node->next;
        run != head_node;
        run = run->next
    ){
        if(run->data == search_data){
            return run;
        }
    }

    return 0;
}

status_t list::insert_start(data_t new_data){
    generic_insert(head_node, new node(new_data), head_node->next);
    this->p_list_info->list_size += 1;
    return SUCCESS;
}

status_t list::insert_end(data_t new_data){
    generic_insert(head_node->prev, new node(new_data), head_node);
    this->p_list_info->list_size += 1;
    return SUCCESS;
}

status_t list::insert_after(data_t existing_data, data_t new_data){
    node* t_node = 0;

    t_node = search_node(existing_data);
    if(t_node == 0){
        return LIST_INVALID_DATA;
    }

    generic_insert(t_node, new node(new_data), t_node->next);
    // this->p_list_info->list_size += 1;
    return SUCCESS;
}

status_t list::insert_before(data_t existing_data, data_t new_data){
    node* t_node = 0;

    t_node = search_node(new_data);
    if(t_node == 0){
        return LIST_INVALID_DATA;
    }
    
    generic_insert(t_node->prev, new node(new_data), t_node);
    this->p_list_info->list_size += 1;
    return SUCCESS;
}

status_t list::get_start(data_t* p_start_data) const{
    if(is_empty()){
        return LIST_EMPTY;
    }

    *p_start_data = head_node->next->data;
    return SUCCESS;
}

status_t list::get_end(data_t* p_end_data) const{
    if(is_empty()){
        return LIST_EMPTY;
    }

    *p_end_data = head_node->prev->data;
    return SUCCESS;
}

status_t list::pop_start(data_t* p_start_data){
    if(is_empty()){
        return LIST_EMPTY;
    }

    *p_start_data = head_node->next->data;
    generic_delete(head_node->next);
    this->p_list_info->list_size -= 1;
    return SUCCESS;
}

status_t list::pop_end(data_t* p_end_data){
    if(is_empty()){
        return LIST_EMPTY;
    }

    *p_end_data = head_node->prev->data;
    generic_delete(head_node->prev);
    this->p_list_info->list_size -= 1;
    return SUCCESS;
}

status_t list::remove_data(data_t r_data){
    if(is_empty()){
        return LIST_EMPTY;
    }
    node* t_node = 0;

    t_node = search_node(r_data);
    if(t_node == 0){
        return LIST_INVALID_DATA;
    }

    generic_delete(t_node);
    this->p_list_info->list_size -= 1;
    return SUCCESS;
}

status_t list::remove_start(){
    if(is_empty()){
        return LIST_EMPTY;
    }

    generic_delete(head_node->next);
    this->p_list_info->list_size -= 1;
    return SUCCESS;
}

status_t list::remove_end(){
    if(is_empty()){
        return LIST_EMPTY;
    }
    generic_delete(head_node->prev);
    this->p_list_info->list_size -= 1;
    return SUCCESS;
}

bool list::is_empty() const{
    return head_node->next == head_node && head_node->prev == head_node;
}

bool list::find(data_t f_data){
    node* t_node = 0;

    t_node = search_node(f_data);
    return (t_node != 0);
}

len_t list::length() const{
    len_t L = 0;

    for(
        node* run = head_node->next;
        run != head_node;
        run = run->next
    ){
        ++L;
    }

    return L;
}

std::ostream& operator<<(std::ostream& os, const list& list_object){
    os << "[START] <->";

    for(
        node* run = list_object.head_node->next;
        run != list_object.head_node;
        run = run->next
    ){
        os << " [" << run->data << "] <->";
    }

    os << " [END]";

    return os;
}

void list::print_refcount_listsize(){
    std::cout << "list Size :" << this->p_list_info->list_size << std::endl;
    std::cout << "Ref Count :" << this->p_list_info->ref_count << std::endl;
}

/* -----------iterator------------ */

list::iterator list::begin() const{
    iterator iter(head_node->next);
    return iter;
}

list::iterator list::end() const{
    iterator iter(head_node);
    return iter;
}

list::iterator::iterator(node* _node):
current_node(_node){

};

int& list::iterator::operator*() const{
    return current_node->data;
}

list::iterator& list::iterator::operator++(){
    current_node = current_node->next;
    return *this; 
}

list::iterator list::iterator::operator++(int){
    list::iterator iter(current_node);
    current_node = current_node->next;
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
    return current_node==rhs.current_node;
}

bool list::iterator::operator!=(const iterator& rhs){
    return current_node!=rhs.current_node;
}



















