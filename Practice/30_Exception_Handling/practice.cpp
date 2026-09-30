#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <stdexcept>

class Negative_num_in_array : public std::runtime_error{
    public :
    Negative_num_in_array(const char* msg) : std::runtime_error(msg){

    }
};

#define ARR_SIZE 8
#define ERROR_NEGATIVE_DATA 1

int a[ARR_SIZE] = {10, 20, -30, 40, -50, 60, 70, -80};

void f1(int i, int n);
void f2(int i, int n);
void f3(int i, int n);

int main(void)
{
    int ret;
    int i = 0;

    while(i < ARR_SIZE)
    {
        try{
            f1(i, a[i]);
        }
        catch(const Negative_num_in_array& exc){
            std::cout << exc.what() << std::endl;
        }
        i = i + 1;
    }
}

void f1(int i, int n){
    // some code 
    f2(i, n); 
    puts("f1():CODE of f1() after call to f2()"); 
}

void f2(int i, int n){
    // some code 
    f3(i, n); 
    puts("f2():CODE OF f2() after call to f3()"); 
 }

void f3(int i, int n){
    // some code 
    if(n < 0){
        std::cout << "Above Index : a[" << i << "]" << std::endl;
        throw Negative_num_in_array("main():Apologies for the negative number at Above Index"); 
    }else{
        printf("f3():a[%d]:%d\n", i, a[i]); 
    }
    // some code 
}