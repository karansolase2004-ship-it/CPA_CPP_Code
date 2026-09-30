#include <stdio.h> 

int main(void){
    int* ptr = NULL; 
    float* ptr_1 = ((void*)0);

    ptr = (int*)malloc(sizeof(int));
    assert(ptr != NULL); 

    // use *ptr; 

    free(ptr); 
    ptr = NULL; 

    float* ptr_1 = ((void*)1);

    return (0); 
}

