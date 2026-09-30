#include <iostream> 
#include <typeinfo> 

class C1{

}; 

class Date{

}; 

class Book{

};  

template <typename T> 
void test(){
    T v; 
    std::cout << "type(v):" << typeid(v).name() << std::endl; 
}

int main(void){
    test<int>(); 
    test<float>(); 
    test<C1>(); 
    test<Date>(); 
    test<Book>(); 
    return 0; 
}

/* 
This is a result of instantiation process. 
AS A PROGRAMMER YOU NEED NOT WRITE THIS 
ONLY FOR EXPLANATION PURPOSE:

void test(){
    int v; 
    std::cout << "type(v):" << typeid(v).name() << std::endl; 
}

void test(){
    float v; 
    std::cout << "type(v):" << typeid(v).name() << std::endl; 
}

void test(){
    C1 v; 
    std::cout << "type(v):" << typeid(v).name() << std::endl; 
}

void test(){
    Book v; 
    std::cout << "type(v):" << typeid(v).name() << std::endl; 
}

void test(){
    Date v; 
    std::cout << "type(v):" << typeid(v).name() << std::endl; 
}

*/ 