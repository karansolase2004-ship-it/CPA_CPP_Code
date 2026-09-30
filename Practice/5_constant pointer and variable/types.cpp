#include <cstdio>
#include <cstdlib>

void types();

const int g_num = 700;

int main(void){
    types();
}

void types(void){
    const int l_num = 400;
    int m1 = 2, a, m2;

    //1)
    int * p1 = &m1; // int *  = int *
    a = *p1;
    printf("%d\n", a);
    *p1 = 4;
    
    // 2) 
    int const* p2 = &m1; // const int* = int* // equivalent to const int* p
    a = *p2;
    printf("%d\n", a);
    // *p2 = 4; 

    // 3) 
    int * const p3 = &m1; // int* const = int
    a = *p3;
    printf("%d\n", a);
    // p3  = &m2; 

    // 4) 
    const int* const p4 = &m1;
    a = *p4;
    printf("%d\n", a);
    // p4  = &m2; 
    // *p4 = 8; 
}