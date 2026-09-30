#include <cstdio>

class hasptr{
    private :
       int n;
       int * ptr;

    public :
       hasptr(int n, int val): n(n), ptr(new int(val)){

       }

       ~hasptr(){
        delete ptr;
       }

       hasptr(const hasptr& other) : n(other.n), ptr(other.ptr){

       }

       hasptr& operator=(const hasptr& other){
        if(this != &other){
            n = other.n;
            *this->ptr = *other.ptr;
        }

        return *this;
       }

       int get_n() const{
        return n;
       }

       int get_ptr_val() const{
        return *this->ptr;
       }

       void set_n(int new_val){
        this->n = new_val;
       }

       void set_ptr_val(int new_val){
        *this->ptr = new_val;
       }
};