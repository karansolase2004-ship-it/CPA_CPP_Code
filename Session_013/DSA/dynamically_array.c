// Let int be a data type.
// lets assume that we have to allocate as array of integers
// if we want to be resizeable then we MUST allocate it DYNAMICALLY

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void alloc_use_free_array_of_ints(void);

int main (void){
    alloc_use_free_array_of_ints();
    return 0;
}

void alloc_use_free_array-of_ints(void){
    size_t N = 8;
    int* p_array = NULL;
    int current_element;
    size_t i;

    p_array = (int*)malloc(N * sizeof(int));
    if (NULL == p_array){
        fprintf(stderr, "Error in allocating memory\n");
        exit(EXIT_FAILURE);
    }

    memset(p_array, 0, N * sizeof(int));

    for (i = 0; i < N; ++i)
        p_array[i] = (i + 1) * 100;  //*(p_array + i) = (i + 1) * 100;

    for (i = 0; i < N; ++i){
        current_element = p_array[i];
        printf("Element at index : %llu : %d\n", i, p_array[i]);
    }

    free(p_array);
    p_array = NULL;
}

