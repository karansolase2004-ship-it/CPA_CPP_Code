#include <cstdio>

int* test();

int main (void){
    int* p = test();
    printf("%d\n", *p);
}

int* test(){
    int a;
    
    return &a;
}