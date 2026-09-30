#ifndef _STACK_HPP 
#define _STACK_HPP 

typedef long long ssize_t; 
const int SUCCESS       = 1; 
const int STACK_FULL    = 2; 
const int STACK_EMPTY   = 3; 

template <ssize_t N> 
class Stack{
    private: 
        int* a; 
        int top_index; 
    public: 
        Stack() : a(new int[N]), top_index(-1){
        }

        int push(int new_data){
            if((top_index + 1) == N)
                return STACK_FULL; 
            top_index = top_index + 1; 
            a[top_index] = new_data; 
            return SUCCESS;
        }

        int top(int* p_data) const {
            if(top_index == -1)
                return STACK_EMPTY;
            *p_data = a[top_index]; 
            return SUCCESS; 
        }

        int pop(int* p_data) {
            if(top_index == -1)
                return STACK_EMPTY;
            *p_data = a[top_index]; 
            top_index = top_index - 1; 
            return SUCCESS; 
        }

        bool empty() const {
            return (top_index == -1); 
        }

        ~Stack(){
            delete[] a; 
        }
}; 

#endif 