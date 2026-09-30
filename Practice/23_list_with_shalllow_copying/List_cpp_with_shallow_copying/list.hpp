#ifndef _LIST_HPP
#define _LIST_HPP

#include <iostream>

// Symbolic Constant
const int SUCCESS = 1;
const int LIST_EMPTY = 2;
const int LIST_INVALID_DATA = 3;

//Typedefs 
typedef int data_t;
typedef int status_t;
typedef unsigned int len_t;

class node{

    friend class list;
    friend std::ostream& operator<<(std::ostream& os, const list& list_object);

    private :
       data_t data;
       node* prev;
       node* next;
       node(data_t _data = 0);
};

class list_info{

   friend class list;

   private :
      size_t list_size;
      unsigned int ref_count;
      list_info(); 
};

class list{

   friend class list_info;

    private :
       node* head_node;
       list_info* p_list_info;
       static void generic_insert(node* p_start, node* p_mid, node* p_end);
       static void generic_delete(node* p_delete_node);
       node* search_node(data_t search_data);

    public :
    class iterator;
       list();
       ~list(); // Destructor

       list(const list& other); // Copy constructor 
       list& operator=(const list& other); // Copy Assignment operator

       status_t insert_start(data_t new_data);
       status_t insert_end(data_t new_data);
       status_t insert_after(data_t existing_data, data_t new_data);
       status_t insert_before(data_t existing_data, data_t new_data);
       status_t get_start(data_t* p_start_data) const;
       status_t get_end(data_t* p_end_data) const;
       status_t pop_start(data_t* p_start_data);
       status_t pop_end(data_t* p_end_data);

       status_t remove_data(data_t r_data);
       status_t remove_start();
       status_t remove_end();
       bool is_empty() const;
       bool find(data_t f_data);
       len_t length()const;
       friend std::ostream& operator<<(std::ostream& os, const list& list_object);
       void print_refcount_listsize();

       iterator begin() const;
       iterator end() const;

       class iterator{
         private :
         node* current_node;
         public :
           iterator(node* _node);
           int& operator*()const;
           iterator& operator++();
           iterator operator++(int);
           iterator& operator--();
           iterator operator--(int);
           bool operator==(const iterator& rhs);
           bool operator!=(const iterator& rhs);
       };
};

#endif /* _LIST_HPP */