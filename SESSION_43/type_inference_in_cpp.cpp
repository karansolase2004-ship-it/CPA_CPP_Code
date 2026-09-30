#include <iostream> 
#include <typeinfo>

int main(void){
    int a=10; 
    int b=20; 

    std::cout << "type(a):"  << typeid(a).name() << std::endl; 
    std::cout << "type(b):"  << typeid(b).name() << std::endl; 
    std::cout << "type(a*b):"  << typeid(a*b).name() << std::endl; 

    return 0; 
}