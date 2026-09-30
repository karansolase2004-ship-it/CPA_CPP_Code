#include <iostream> 
#include <stdexcept> 
#include <cstdio>
#include <cstring> 

const int ARR_SIZE = 8; 

int a[ARR_SIZE] = {10, 20, -30, 40, -50, 60, 70, -80}; 

void f1(int i, int n); 
void f2(int i, int n); 
void f3(int i, int n); 

int main(void){
    int i; 

    for(i = 0; i < ARR_SIZE; ++i){
        try{
            std::cout << "main():try block start" << std::endl; 
            f1(i, a[i]); 
            std::cout << "----main():try block end for index"
                        << i << "----" << std::endl; 
        }catch(std::domain_error& exc){
            std::cout << exc.what() << std::endl; 
        }
    } 

    return EXIT_SUCCESS; 
}

void f1(int i, int n){
    std::cout << "f1():Entered" << std::endl; 
    f2(i, n); 
    std::cout << "f1():CODE of f1() after returning from f2()" << std::endl; 
}

void f2(int i, int n){
    std::cout << "f2():Entered" << std::endl; 
    f3(i, n); 
    std::cout << "f2():CODE of f2() after returning from f3()" << std::endl; 
}

void f3(int i, int n){
    const int BUFFER_SIZE = 64;
    static char fmt_msg[] = "Value for n is negative for the current index %d\n"; 
    static char err_msg[BUFFER_SIZE]; 
    
    std::cout << "f3():entered" << std::endl; 

    if(n < 0){
        memset(reinterpret_cast<void*>(err_msg), 0, BUFFER_SIZE); 
        snprintf(err_msg, BUFFER_SIZE, fmt_msg, i); 
        throw std::domain_error(err_msg);
    }
    else 
        std::cout << "f3():n:" << n << std::endl; 
}
