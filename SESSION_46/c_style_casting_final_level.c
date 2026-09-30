#include <stdio.h> 
#include <stdlib.h> 

struct A{
    int a, b; 
    double x, y; 
}; 

struct B{
    int p, q; 
    unsigned long long arr[5]; 
} 
inB = {
    100, 200, 
    {
        0x112233440a0b0c0d, 
        0xa0b0c0d019283746, 
        0x1234567887654321, 
        0x1992883774665550, 
        0x1020304050607080
    }
}; 

void showB(struct B* pB, const char* msg); 

int main(void){
    showB(&inB, "Before casting:"); 

    *(unsigned short*)(((char*)&((struct A*)&inB)->y) + 2) = 0xFFFF; 
    // -> arrow operator has higher precedence than &  ampersand operator

    showB(&inB, "After casting:"); 

    return (0); 
}

void showB(struct B* pB, const char* msg){
    int i; 

    if(msg)
        puts(msg); 

    printf("pB->p = %x, pB->q = %x\n", pB->p, pB->q); 
    for(i = 0; i < 5; ++i)
        printf("pB->arr[%d]:%llx\n", i, pB->arr[i]); 
}

