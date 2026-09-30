#include <iostream> 

namespace cpa{
    namespace dsa{
        class node{
            friend class list; 
            friend std::ostream& operator<<(std::ostream& os, 
                    const list& list_object);
            
            private: 
                int data; 
                node* prev; 
                node* next; 
                node(int _data); 
        }; 
        
        class list{
            private: 
                node* head_node; 
                static void generic_insert(node* beg, node* mid, node* end); 
                static void generic_delete(node* delete_node); 
                node* search(int f_data); 
            public: 
                list(); 
                ~list(); 
                void insert_start(int data);
                void insert_end(int data); 
                void insert_after(int e_data, int new_data); 
                void insert_before(int e_data, int new_data); 
                int get_start() const;
                int get_end() const;
                int pop_start(); 
                int pop_end(); 
                void remove_start(); 
                void remove_end(); 
                void remove_data(int r_data); 
                bool find(int f_data) const; 
                bool empty() const; 
                std::size_t size() const; 
                friend std::ostream& operator<<(
                        std::ostream& os, 
                        const list& list_object
                    ); 
        };

        
    }
}