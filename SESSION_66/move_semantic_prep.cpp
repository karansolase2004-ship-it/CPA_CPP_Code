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

        // copy constructor 
        list(const list& rhs_list){
            // clone rhs list into a new list object (ctrl+c on rhs list)
            // pointed by this (ctrl+v on newly allocated object pointed by this)
        }

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

}

//  instance variable (dedicated syntax)                T var_name; 
//  pointer variable (raw pointer) (dedicated syntax)   T ptr_name; 
//  lvalue reference variable (dedicated syntax)        T& ref_name = expr; 
//  rvalue reference variable (dedicated syntax)        T&& ref_name = expr; 
//  shared pointer  (class template)                    std::shared_ptr<T> sp_ptr_name; 
//  unique pointer  (class template)                    std::unique_ptr<T> up_ptr_name; 
//  weak pointer    (class template)                    std::weak_ptr<T> wp_ptr_name; 

/* 

template <typename T> 
T&& move(T obj){
    return reinterpret_cast<T&&>(obj); 
}
*/