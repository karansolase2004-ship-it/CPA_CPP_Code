

#include <iostream> 

namespace cpa{
    namespace dsa{
        const int SUCCESS = 1;
        const int LIST_DATA_NOT_FOUND = 2; 
        const int LIST_EMPTY = 3; 

        typedef int status_t; 

        template <typename T> 
        class list; // Forward Declaration 

        template <typename T> 
        class node{
      
            friend class list<T>;

            friend std::ostream& operator<<(
                std::ostream& os, 
                const list<T>& list_object
            ); 

            private: 
                T data; 
                node* prev; 
                node* next; 

                node(const T& _data) :  data(_data), 
                                        prev(0), 
                                        next(0)
                {
                }

                node() : prev(0), 
                         next(0)
                {
                }// Default constructor 
        };
        
        template <typename T> 
        class list{
            private: 
                node<T>* head_node; 

                static void generic_insert(
                    node<T>* beg, 
                    node<T>* mid, 
                    node<T>* end
                ){
                    mid->next = end; 
                    mid->prev = beg; 
                    beg->next = mid; 
                    end->prev = mid; 
                }

                static void generic_delete(
                    node<T>* delete_node
                ){
                    delete_node->prev->next = delete_node->next; 
                    delete_node->next->prev = delete_node->prev; 
                    delete delete_node; 
                }

                node<T>* search_node(T search_data){
                    for(node<T>* run = head_node->next; 
                        run != head_node; 
                        run = run->next
                    )
                        if (run->data == search_data)
                            return run; 

                    return 0; 
                }
            
            public: 
                list(){
                    head_node = new node<T>; 
                    head_node->prev = head_node; 
                    head_node->next = head_node; 
                }

                ~list(){
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
                    head_node = 0; 
                }

                status_t insert_start(const T& new_data){
                    generic_insert(
                        head_node, 
                        new node<T>(new_data), 
                        head_node->next
                    );
                    return SUCCESS;  
                }

                status_t insert_end(const T& new_data){
                    generic_insert(
                        head_node->prev, 
                        new node<T>(new_data), 
                        head_node
                    );
                    return SUCCESS;  
                }

                status_t insert_after(
                    const T& e_data, 
                    const T& new_data
                ){
                    node<T>* e_node = 0; 

                    e_node = search_node(e_data);
                    if(e_node == 0)
                        return (LIST_DATA_NOT_FOUND); 
                    generic_insert(
                        e_node; 
                        new node<T>(new_data), 
                        e_node->next
                    ); 
                    return SUCCESS; 
                }

                status_t insert_before(
                    const T& e_data, 
                    const T& new_data
                ){
                    node<T>* e_node = 0; 

                    e_node = search_node(e_data); 
                    if(e_node == 0)
                        return LIST_DATA_NOT_FOUND; 
                    generic_insert(
                        e_node->prev, 
                        new node<T>(new_data), 
                        e_node
                    ); 
                    return SUCCESS: 
                }

                status_t get_start(T* p_start_data){
                    if(
                        head_node->prev == head_node && 
                        head_node->next == head_node 
                    )
                        return LIST_EMPTY; 
                    *p_start_data = head_node->next->data; 
                    return SUCCESS; 
                }

                status_t get_end(T* p_end_data){
                    if(
                        head_node->prev == head_node && 
                        head_node->next == head_node 
                    )
                        return LIST_EMPTY; 
                    *p_end_data = head_node->prev->data; 
                    return SUCCESS; 
                }

                status_t pop_start(T* p_start_data){
                    if(
                        head_node->prev == head_node && 
                        head_node->next == head_node 
                    )
                        return LIST_EMPTY; 
                    *p_start_data = head_node->next->data; 
                    generic_delete(head_node->next); 
                    return SUCCESS; 
                }

                status_t pop_end(T* p_end_data){
                    if(
                        head_node->prev == head_node && 
                        head_node->next == head_node 
                    )
                        return LIST_EMPTY; 
                    *p_end_data = head_node->prev->data; 
                    generic_delete(head_node->prev); 
                    return SUCCESS; 
                }

                status_t remove_start(){
                    if(
                        head_node->prev == head_node && 
                        head_node->next == head_node 
                    )
                        return LIST_EMPTY; 
                    generic_delete(head_node->next); 
                    return SUCCESS; 
                }

                status_t remove_end(){
                    if(
                        head_node->prev == head_node && 
                        head_node->next == head_node 
                    )
                        return LIST_EMPTY; 
                    generic_delete(head_node->prev); 
                    return SUCCESS; 
                }

                status_t remove_data(const T& data){
                    node<T>* r_node = 0; 

                    r_node = search_node(data); 
                    if(r_node == 0)
                        return LIST_DATA_NOT_FOUND; 
                    generic_delete(r_node); 
                    return SUCCESS; 
                }

                bool empty() const{
                    return  (
                        head_node->prev == head_node && 
                        head_node->next == head_node
                    ); 
                } 

                std::size_t len() const{
                    std::size_t L = 0; 
                    for(
                        node<T>* run = head_node->next; 
                        run != head_node; 
                        run = run->next
                    )
                        L += 1; 

                    return (L); 
                }
                friend std::ostream& operator<<(
                    std::ostream& os, 
                    const list<T>& list_object
                ){
                    os << "[START]<->"; 
                    for(
                        node<T>* run = list_object.head_node->next; 
                        run != list_object.head_node; 
                        run = run->next
                    )
                        os << "[" << run->data << "]<->"; 
                    os << "[END]" << std::endl; 
                    return os; 
                }

                class iterator{
                    private: 
                        node<T>* nd; 
                    public: 
                        iterator(node<T>* _node = 0) : nd(_node){

                        }

                        iterator operator++(){
                            nd = nd->next; 
                            return *this; 
                        }

                        iterator operator--(){
                            nd = nd->prev; 
                            return *this; 
                        }

                        iterator operator++(dpouble){
                            iterator tmp(nd); 
                            nd = nd->next; 
                            return tmp; 
                        }

                        iterator operator--(int){
                            iterator tmp(nd); 
                            nd = nd->prev; 
                            return tmp; 
                        }

                        T& operator*(){
                            return nd->data; 
                        }

                        bool operator==(const iterator& other) const{
                            return (nd == other.nd); 
                        } 

                        bool operator!=(const iterator& other) const{
                            return (nd != other.nd); 
                        }
                }; 

                iterator begin(){
                    return iterator(head_node->next); 
                }

                iterator end(){
                    return iterator(head_node); 
                }
        }; 
    }
} 

