#include "range_interface.hpp"
#include <iostream>

int main (void){
    range R(10, 20);

    std::cout << "By Using While loop :" << std::endl;

    range::iterator iter = R.begin();

    while (iter != R.end()){
        std::cout << "*iter :" << *iter << std::endl;
        ++iter;
    }

    std::cout << "By using For loop :" << std::endl;

    for(
        range::iterator iter = R.begin();
        iter != R.end();
        ++iter
    ){
        std::cout << "*iter :" << *iter << std::endl; 
    }

    std::cout << "END" << std::endl;
}