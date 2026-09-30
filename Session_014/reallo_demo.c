#include <stdio.h> 
#include <stdlib.h> 

int main(void){
    int* ptr = NULL; 
    size_t N = 0; 
    size_t i; 
    int data; 

    printf("Enter integer val:"); 
    scanf("%d", &data); 

    ptr = (int*)realloc(ptr, (N+1) * sizeof(int));
    if(ptr == NULL){
        puts("Error"); 
        exit(-1); 
    } 
    N = N + 1; 
    ptr[N-1] = data; 

    printf("Enter integer val:"); 
    scanf("%d", &data); 

    ptr = (int*)realloc(ptr, (N+1)*sizeof(int)); 
    if(ptr == NULL){
        puts("Error"); 
        exit(-1); 
    } 
    N = N + 1; 
    ptr[N-1] = data; 

    printf("Enter integer val:"); 
    scanf("%d",&data); 

    ptr = (int*)realloc(ptr, (N+1)*sizeof(int)); 
    if(ptr == NULL){
        puts("Error"); 
        exit(-1); 
    } 
    N = N + 1; 
    ptr[N-1] = data; 

    for(i = 0; i < N; ++i)
        printf("ptr[%llu]:%d\n", i, ptr[i]); 

    free(ptr); 
    ptr = NULL; 

    return (0); 
}