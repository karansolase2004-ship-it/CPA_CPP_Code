#include <iostream> 

class node{
    friend class list; 
    private:
        int data; 
        node* prev; 
        node* next; 
        node(int _data = 0) : data(_data), prev(0), next(0){} 
};

class list{
    private: 
        node* head_node; 
    public: 
        list() : head_node(new node){
        }

        
        list(const list& rhs_list) = delete; 

        // copy assignment 
        list& operator=(const list& rhs_list){
            // destroy lhs list pointed by this 
            // clone rhs list to an lhs list (ctrl+c on rhs_list)
            // pointed by this (ctrl+v on existing object pointed by this)
        }

        // move constructor 
        list(list&& rhs_list){
            // ctrl+X on rhs_list 
            // ctrl+V on newly allocated object pointed by this 
        }

        // move assignment operator 
        list& operator=(list&& rhs_list){
            // ctrl+X on rhs_list 
            // ctrl+V on existing object pointed by this 
           
        }

        // destructor 
        ~list(){
            // destroy list pointed by this 
        }
}; 

int main(void){
    list L1; 
    list L2(L1);    // copy constructor 
                    // ctrl+c on L1, ctrl+v on L2
                    
    list L3; 

    L1 = L3;        // copy assignment operator 
                    // ctrl+c on L3, ctrl+v on L1 

    list L4(std::move(L1)); // ctrl+X on L1 and ctrl+v on L4 

    list L5; 

    L5 = std::move(L3);     // ctrl+X on L3 and ctrl+v on L5 

    return (0); 
}

// disable both copy and move semantics (DELETE copy constructor, move constructor, copy assignment operator
// and move assignment opeartor & KEEP destructor  ) 1 
// enable copy and disable move (DELETE move constructor, move assignment operator, 
// KEEP copy constructor, copy assignment operator and destructor) 3 
// disable copy and enable move (DELETE copy constructor and copy assignment operator 
//  KEEP move constructor, move assignment operator and destructor) 3 
// enable both copy and move (KEEP copy constructor, move constructor, copy assignment operator
// and move assignment opeartor & KEEP destructor  ) 5 