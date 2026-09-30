#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void resize_dynamic_array(void);

int main(void){
    resize_dynamic_array();
    return 0;
}

void resize_dynamic_array(void){
    int* p_array = NULL;
    size_t N = 5;
    size_t i;

    p_array = (int*)malloc(N * sizeof(int));
    if (NULL == p_array){
        fprintf(stderr, "allocation error\n");
        exit(EXIT_FAILURE);
    }

    memset(p_array, 0, 5*sizeof(int));

    for (i = 0; i < N; ++i)
        p_array[i] = (i + 1) * 100;

    for (i = 0; i < N; ++i)
        printf("p_array[%llu] : %d\n", i, p_array[i]);

    N = 8;

    p_array = (int*)realloc(p_array, N * sizeof(int));
    if(NULL == p_array){
        puts("Error in allocating memory");
        exit(EXIT_FAILURE);
    } 

    for(i = 0; i < N; ++i)
         printf("p_array[%llu] : %d\n", i, p_array[i]);

    p_array[5] = 1000;
    p_array[6] = 2000;
    p_array[7] = 3000;

    for (i = 0; i < N; ++i)
         printf("p_array[%llu] : %d\n", i, p_array[i]);

    free(p_array);
    p_array = NULL; 
}


/* 
    void* realloc(void* old_ptr, size_t new_size_in_bytes); 

    1) old_ptr == NULL 
    realloc() behaves like malloc() 
    realloc(NULL, 32) 
    == 
    malloc(32); 

    2) old_ptr != NULL then old_ptr MUST BE AN ADDRESS RETURNED BY 
       malloc(), calloc(), realloc() or any other DYNAMIC MEMORY 
       ALLOCATION FUNCTION.   
*/