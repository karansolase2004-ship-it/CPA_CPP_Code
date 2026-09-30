#include <iostream> 

class A{
    private: 
        int a; 
        char b; 
        float c;
}; 

class B{
    private: 
        double x, y; 
}; 

int main(void){
    B objB; 
    const int n = 100; 
    volatile int j = 8500;
    int g = 0;
    A* pA = reinterpret_cast<A*>(&objB);

    int* ptr = reinterpret_cast<int*>(&n);
    int* ptr = static_cast<int*>(&n);
    int* ptr_1 = (int*)(&n);
    int* ptr_2 = reinterpret_cast<int*>(&j);

    return (0); 
}