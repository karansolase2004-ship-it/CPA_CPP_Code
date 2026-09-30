#include <cstdio> 

class Base{
    public: 
        void base_specific_function(){
            puts("Base::base_specific_function():I am defined only in Base"); 
        }

        void f1(){
            puts("In Base::f1():base version"); 
        }

        virtual void f2(){
            puts("In Base::f2():base version"); 
        }
}; 

class Derived : public Base{
    public: 
        void f1(){
            puts("Derived::f1():overridden by derived version"); 
        }

        void f2(){
            puts("Derived::f2():overridden by derived version"); 
        }

        void derived_specific_function(){
            puts("Derived::derived_specific_function()"); 
        }
}; 

int main(void){
    Derived D; 

    Base* pB = &D; 

    // TRADITIONAL MODEL (without virtual qualifier )
    pB->base_specific_function();       // ok 
    pB->f1();                           // ok, Base::f1() 
    pB->f2();                           // ok, Base::f2() 
    // pB->derived_specific_function();    // Error 

    pB->base_specific_function(); 
    pB->f1();   // Base::f1() DESIRED 
    pB->f2();   // Derived::f2(): desired 
}