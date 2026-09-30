#include <iostream>
#include <typeinfo>

class CPAint{
    private :
       int n;
};

int main (void){
    CPAint x;
    int m = 100;

    std::cout   << "sizeof(x):" << sizeof(x) << std::endl
                << "sizeof(m):" << sizeof(m) << std::endl;

    std::cout   << "typeof(x):"  << typeid(x).name() << std::endl
                << "typeof(m):"  << typeid(m).name() << std::endl;

    int result  = m + 5;

    CPAint y;

    // CPAint Summation  = x + y;  // CTE : binary + is not defined for objects of CPAint

    return(0); 
}