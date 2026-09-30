#include <iostream>

// Symbolic constants:
// -----------------------

//Typedefs
// -----------------------

// Class Node Definitions :
class node{
    friend class list; 
    friend std::ostream& operator<<(std::ostream& os, const list& list_object); 
    private: 
        data_t data; 
        node* prev; 
        node* next; 
        node(data_t _data = 0); 
}; 


//List CLass Definitions 
class list{
   private :
      int current_n;
   public :
      class iterator;
      class const_iterator;
      class reverse_iterator;
      // Public Members;

      iterator begin() const;
      iterator end() const;

      class iterator{
         private :
            node* current_node;
         public :
            iterator(node* _node);
            int& operator*();
            iterator& operator++();
            iterator operator++(int);
            iterator& operator--();
            iterator operator--(int);
            bool operator==(const iterator& rhs);
            bool operator!=(const iterator& rhs); 
      };

      const_iterator cbegin() const;
      const_iterator cend() const;

      class const_iterator{
         private :
            node* current_node;
         public :
            const_iterator(node* _node);
            int operator*();
            const_iterator& operator++();
            const_iterator operator++(int);
            const_iterator& operator--();
            const_iterator operator--(int);
            bool operator==(const const_iterator& rhs);
            bool operator!=(const const_iterator& rhs);
      };

      reverse_iterator rbegin() const;
      reverse_iterator rend() const;

      class reverse_iterator{
         private :
            node* current_node;
         public :
            reverse_iterator(node* _node);
            int& operator*();
            reverse_iterator& operator++();
            reverse_iterator operator++(int);
            reverse_iterator& operator--();
            reverse_iterator operator--(int);
            bool operator==(const reverse_iterator& rhs);
            bool operator!=(const reverse_iterator& rhs);
      };
};