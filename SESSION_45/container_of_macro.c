#include <stdio.h> 
#include <stdlib.h> 

#ifndef OFFSET_OF 
#define OFFSET_OF(type, member)     ((size_t)(&((type*)0)->member))
#endif 

#ifndef CONTAINER_OF 
#define CONTAINER_OF(addr, type, member)  ((type*)((size_t)addr - OFFSET_OF(type, member)))
#endif 

struct A{
    int a; 
    char b; 
    float c; 
}; 

void test_function(float* pf); 
void test_contaner_of(float* pf); 

int main(void){
    struct A inA1 = {10, 'A', 1.1f}; 
    struct A inA2 = {20, 'B', 2.2f}; 
    struct A inA3 = {30, 'C', 3.3f}; 

    test_function(&inA1.c); 
    test_function(&inA2.c); 
    test_function(&inA3.c); 

    test_contaner_of(&inA1.c);
    test_contaner_of(&inA2.c);
    test_contaner_of(&inA3.c);

    return 0; 
}

void test_function(float* pf){
    struct A* pA = (struct A*)((size_t)pf - (size_t)(&((struct A*)0)->c)); 

    printf("pA->a = %d, pA->b = %c, pA->c = %.1f\n", pA->a, pA->b, pA->c); 

    if(&pA->c == pf)
        puts("VERIFIED"); 
}

void test_contaner_of(float* pf){
    puts("In test_container_of:"); 
    
    struct A* pA = CONTAINER_OF(pf, struct A, b); 
    printf("pA->a = %d, pA->b = %c, pA->c = %.1f\n", pA->a, pA->b, pA->c); 

    if(&pA->c == pf)
        puts("VERIFIED");  
}