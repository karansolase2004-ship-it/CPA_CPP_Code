#include <iostream> 
#include "max.hpp"

int main(void){
    int a = 300; 
    int m1 = max<int>(a, 600); 

    std::cout << "max in " << a << " and 600 is:"  << m1 << std::endl; 

    float f_num1 = 3.2, f_num2 = 5.4;
    float f_max = max<float>(f_num1, f_num2); 
    std::cout << "max in " << f_num1 << " and " << f_num2 << " is " << f_max << std::endl; 

    return EXIT_SUCCESS; 
}