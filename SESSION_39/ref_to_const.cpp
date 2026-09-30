#include <iostream> 

int main(void){
    int m; 
    int a = 0;
    int* p1;                    // non-const pointer to non-const int 
    const int* p2;              // non-const pointer to const int 
    int * const p3 = &m;        // const pointer to non-const int 
    const int* const p4 = &m;   // const pointer to const int 

    int& ref = m;
    int b = 9;
    ref = a;
    ref = 100; 
    ref = 200; 

    const int& cref = m; // It is a constant reference to a const int
    m = 580;
    // cref = 250; // i.e cref is only allowed to read value not write 
    // cref = b; // cref cannot be modified once it is initialized.
    const int& ref1 = 400; 
    // ref1 = 500; 

    // int& ref2 = 200;

    return EXIT_SUCCESS; 
}
