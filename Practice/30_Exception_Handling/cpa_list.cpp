#include <iostream>
#include "cpa_list_exceptions.cpp"

namespace cpa{
    namespace dsa{

        template <typename T>
        class list;

        template <typename T>
        class list_info{
            friend class list<T>;
            friend std::ostream& operator<<(std::ostream& os, const list<T>& list_object);

            private :
            size_t list_size;
            unsigned int ref_count;
            
            list_info() : list_size(0), ref_count(1)
            {

            }
        };

        template <typename T>
        class node{
            friend class list<T>;

            friend std::ostream& operator<<(
                std::ostream& os, const list<T>& list_object);

            public :
            T data;
            node* prev;
            node* next;

            node(const T& _data) : 
            data(_data), prev(0), next(0)
            {

            }
            node() : data(0), prev(0), next(0)
            {

            }

        };

        template <typename T>
        class list{
            private :
            node<T>* head_node;
            list_info<T>* p_list_info;
            
            static void generic_insert(
                node<T>* start,
                node<T>* mid, 
                node<T>* end){
                    mid->next = end;
                    mid->prev = start;
                    start->next = mid;
                    end->prev = mid;
                }

            static void generic_delete(
                node<T>* delete_node){
                    delete_node->prev->next = delete_node->next;
                    delete_node->next->prev = delete_node->prev;
                    delete delete_node;
                }

            node<T>* search_node(T search_data){
                for(
                    node<T>* run = head_node->next;
                    run != head_node;
                    run = run->next
                )
                {
                    if(run->data == search_data)
                    {
                        return run;
                    }
                }
                return nullptr;
            }

            public :
            list() : head_node(new node<T>), p_list_info(new list_info<T>)
            {
                head_node->prev = head_node;
                head_node->next = head_node;
            }

            ~list()
            {
                this->p_list_info->ref_count -= 1;
                if(this->p_list_info->ref_count == 0)
                {
                node<T>* run = 0;
                node<T>* run_next = 0;

                for(
                    run = head_node->next;
                    run != head_node;
                    run = run_next
                ){
                    run_next = run->next;
                    delete run;
                }

                delete head_node;
                delete p_list_info;
                }
            }

            list(const list<T>& other)
            {
                this->p_list_info = other.p_list_info;
                this->head_node = other.head_node;
                this->p_list_info->ref_count += 1;
            }

            list<T>& operator=(const list<T>& other)
            {
                if(this != &other)
                {
                    this->p_list_info->ref_count -= 1;
                    if(this->p_list_info->ref_count == 0)
                    {
                        node* run = 0;
                        node* run_next = 0;

                        for(
                            run = head_node->next;
                            run != head_node;
                            run = run_next;
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

            void insert_start(const T& new_data){
                generic_insert(head_node, new node<T>(new_data), head_node->next);
                this->p_list_info->list_size += 1;
            }

            void insert_end(const T& new_data){
                generic_insert(head_node->prev, new node<T>(new_data), head_node);
                this->p_list_info->list_size += 1;
            }

            void insert_after(const T& e_data, const T& new_data){
                node<T>* e_node = search_node(e_data);
                if(e_node == nullptr){
                    throw list_invalid_data("insert_after: Existing data does not Exist");
                }
                generic_insert(e_node, new node<T>(new_data), e_node->next);
                this->p_list_info->list_size += 1;
            }

            void insert_before(const T& e_data, const T& new_data)
            {
                node<T>* e_node = search_node(e_data);
                if(e_node == 0)
                {
                    throw list_invalid_data("insert_before : Existing data does not Exist");
                }
                generic_insert(e_node->prev, new node<T>(new_data), e_node);
                this->p_list_info->list_size += 1;
            }

            T get_start() const{
                if(empty()){
                    throw list_empty("get_start():cannot get start of empty list");
                }
                return head_node->next->data;
            }

            T get_end() const{
                if(empty())
                {
                    throw list_empty("Get_end() : cannot get end of the empty list");
                }
                return head_node->prev->data;
            }

            T pop_start() const{
                if(empty())
                {
                    throw list_empty("pop_start() : cannot pop start of the empty list");
                }
            T data = head_node->next->data;
            generic_delete(head_node->next);
            return data;
            }

            T pop_end() const{
                if(empty())
                {
                    throw list_empty("pop_end() : Cannot pop end of the empty list");
                }
            T data = head_node->prev->data;
            generic_delete(head_node->prev);
            return data;
            }

            void remove_start(){
                if (empty())
                {
                    throw list_empty("remove start : Cannot remove start of the empty list");
                }
                generic_delete(head_node->next);
            }

            void remove_end(){
                if(empty())
                {
                    throw list_empty("remove end : Cannot remove end of the empty list");
                }
                generic_delete(head_node->prev);
            }

            void remove_data(int r_data){
            node<T>* temp_node = search_node(r_data);
            if(temp_node == 0){
                throw list_invalid_data("remove_data : data Not Found");
            }
            generic_delete(temp_node);
            }

            bool find(int f_data) const{
                node<T>* temp_node = search_node(f_data);
                return temp_node != 0;
            }

            bool empty() const{
                return head_node->prev == head_node && head_node->next == head_node;
            }

            std::size_t size() const{
                std::size_t n = 0;
                for(
                    node<T>* run = head_node->next;
                    run != head_node;
                    run = run->next
                ){
                    n += 1;
                }
                return n;
            }

            friend std::ostream& operator<<(
                std::ostream& os, const list<T>& list_object)
            {
                os << "[START]<->";
                for(
                    cpa::dsa::node<T>* run = list_object.head_node->next;
                    run != list_object.head_node;
                    run = run->next
                )
                {
                    os << "[" << run->data << "]<->";
                }

                os << "[END]" << std::endl;

                return os;
            }

        class iterator;

        iterator begin(){
            return iterator(head_node->next);
        }

        iterator end(){
            return iterator(head_node);
        }


        class iterator{
            private :
            node<T>* current_node;
            public :
            iterator(typename node<T>* _node = 0): current_node(_node){

            }

            iterator operator++(){
                current_node = current_node->next;
                return *this;
            }

            iterator operator--(){
                current_node = current_node->prev;
                return *this;
            }

            iterator operator++(int){
                iterator tmp(current_node);
                current_node = current_node->next;
                return tmp;
            }

            iterator operator--(int){
                iterator tmp(current_node);
                current_node = current_node->prev;
                return tmp;
            }

            T& operator*(){
                return current_node->data;
            }

            bool operator==(const iterator& other) const{
                return (current_node == other.current_node);
            }

            bool operator!=(const iterator& other) const{
                return (current_node != other.current_node);
            }
        };
        };
    }
}

