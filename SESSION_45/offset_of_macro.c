#include <stdio.h> 
#include <stdlib.h> 

#define OFFSET_OF(type, member) ((unsigned long long int)(&((type*)0)->member))

struct A{
    int a; 
    char b; 
    float c; 
}; 

void compute_offset_1(void); 
void compute_offset_2(void); 
void compute_offset_3(void); 
void compute_offset_4(void); 
void compute_offset_5(void); 

int main(void){
    compute_offset_1(); 
    compute_offset_2(); 
    compute_offset_3();
    compute_offset_4(); 
    compute_offset_5(); 

    return 0; 
}


void compute_offset_1(void){
    struct A inA; 
    unsigned long long int offset_c; 

    offset_c = (unsigned long long int)&inA.c - (unsigned long long int)&inA; 
    printf("co1:offset_c = %llu\n", offset_c); 
}

void compute_offset_2(void){
    struct A* pA = NULL; 
    unsigned long long int offset_c; 

    pA = (struct A*)malloc(sizeof(struct A)); 
    if(pA == NULL){
        fprintf(stderr, "fatal:malloc():out of memory\n"); 
        exit(EXIT_FAILURE); 
    }

    offset_c = (unsigned long long int)&pA->c - (unsigned long long int)pA;      
    printf("co2:offset_c = %llu\n", offset_c); 

    free(pA); 
    pA = NULL; 
}

void compute_offset_3(void){
    struct A* pA = 0; 
    unsigned long long int offset_c; 

    offset_c = (unsigned long long int)&pA->c - (unsigned long long int)pA; 
    printf("co3:offset_c = %llu\n", offset_c); 
}

void compute_offset_4(void){
    printf(
            "co4:offset_c = %llu\n", 
            (unsigned long long int)(&((struct A*)0)->c)
        ); 
}

/* 
    type(0) == int                      ... by type inference 
    type((struct A*)0) == struct A*     ... by definition of type casting 
    type(((struct A*)0)->c) == float    ... type annotation of member c in struct A
    type(&((struct A*)0)->c) == float*  ... by definition of &
*/

void compute_offset_5(void){
    unsigned long long int offset_a, offset_b, offset_c; 

    offset_a = OFFSET_OF(struct A, a); 
    offset_b = OFFSET_OF(struct A, b); 
    offset_c = OFFSET_OF(struct A, c); 

    printf("co5:offset_a=%llu, offset_b=%llu, offset_c=%llu\n", 
        offset_a, offset_b, offset_c); 
}
