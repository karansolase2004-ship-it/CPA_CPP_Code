#include <iostream>

class hasptr{
    private :
       int n;
       int* ptr;
    public :
       hasptr(int _n, int _val) : n(_n), ptr(new int(_val)){

       }

       ~hasptr(){
        delete ptr;
       }

       hasptr(const hasptr& other) : n(other.n), ptr(new int(*other.ptr)){

       }

       hasptr& operator=(const hasptr& other){
        if(this != &other)
        {
            n = other.n;
            *this->ptr = *other.ptr;
        }

        return *this;
       }

       int getn() const {
        return n;
       }

       void setn(int new_n){
        n = new_n;
       }

       int getptr_val() const{
        return *ptr;
       }

       void setptr_val(int new_val){
        *this->ptr = new_val;
       }

};