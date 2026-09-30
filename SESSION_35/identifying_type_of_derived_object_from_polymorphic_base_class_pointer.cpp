#include <iostream> 
#include <cmath> 
#include <ctime> 
#include <typeinfo>

class B{
    public: 
        virtual void f(){
            std::cout << "In B::f()" << std::endl; 
        }
}; 

class D1 : public B{
    public: 
        void f(){
            std::cout << "D1::f()" << std::endl; 
        }
}; 

class D2 : public B{
    public: 
        void f(){
            std::cout << "D2::f()" << std::endl; 
        }
}; 

class D3 : public B{
    public: 
        void f(){
            std::cout << "D3::f()" << std::endl; 
        }
}; 

int main(void){
    B* pB = 0; 

    srand(time(0)); 

    switch(rand() % 3){
        case 0: 
            pB = new D1; 
            puts("In case 0"); 
            break; 
        case 1: 
            pB = new D2; 
            puts("In case 1"); 
            break; 
        case 2: 
            pB = new D3; 
            puts("In case 2:"); 
            break; 
    }

    std::cout << "typeid(*pB).name() -> " << typeid(*pB).name() << std::endl; 

    return 0; 
}

