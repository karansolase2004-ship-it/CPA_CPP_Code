#include <iostream> 
#include <cstdlib> 

void use_case_1(void); 
void use_case_2(void); 

int main(void){
    use_case_1(); 
    use_case_2(); 

    return EXIT_SUCCESS; 
}

void use_case_1(void){
    std::cout << "In use_case_1():" << std::endl; 

    float f_num_1 = 3.1415; 
    float f_num_2 = 6.45321;
    int integral_part= f_num_1; 
    std::cout << "Integral Part :" << integral_part << std::endl;

    integral_part = static_cast<int>(f_num_2); 
    std::cout << "integral part:" << integral_part << std::endl;  
}

void use_case_2(void){
    int* ptr = NULL; 

    ptr = static_cast<int*>(malloc(sizeof(int)));   // type casting 
                                                    // by static_cast is mandatory 
    free((ptr));  // here type casting is optional 
                                    // T* to void* comes under legal implicit 
                                    // type coversions 
    ptr = NULL; 
}

