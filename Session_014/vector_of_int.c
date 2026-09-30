#include <stdio.h>
#include <stdlib.h>

struct vector{
    int* p_array;
    size_t N;
};

struct vector* create_vector(void);
void push_back(struct vector* p_vec, int new_data);
void show(struct vector* p_vec);
void destroy_vector(struct vector* p_vec);

int main (void){
    struct vector* p_vec_1 = NULL;
    struct vector* p_vec_2 = NULL;

    p_vec_1 = create_vector();
    p_vec_2 = create_vector();

    push_back(p_vec_1, 100);
    push_back(p_vec_1, 200);
    push_back(p_vec_1, 300);
    push_back(p_vec_1, 400);

    push_back(p_vec_2, 1000);
    push_back(p_vec_2, 2000);
    push_back(p_vec_2, 3000);
    push_back(p_vec_2, 4000);
    push_back(p_vec_2, 5000);

    show(p_vec_1);
    show(p_vec_2);

    destroy_vector(p_vec_1);
    p_vec_1 = NULL;

    destroy_vector(p_vec_2);
    p_vec_2 = NULL;

    return 0;
}

struct vector* create_vector(void){
    struct vector* p_vec = NULL;   // s1

    p_vec = (struct vector*)malloc(sizeof(struct vector));  // s2
    // s3

    if (NULL == p_vec){
        fprintf(stderr,  "malloc() : fatal: memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    //s4
    p_vec->p_array = NULL;
    p_vec->N = 0;

    return(p_vec);
}

void push_back(struct vector* p_vec, int new_data){
    p_vec->p_array = (int*)realloc(p_vec->p_array, (p_vec->N + 1) * sizeof(int));
    if (NULL == p_vec->p_array){
        puts("Error in allocating memory");
        exit(-1);
    }

    p_vec->N = p_vec->N + 1;
    p_vec->p_array[p_vec->N - 1] = new_data;
}

void show(struct vector* p_vec){
    size_t i;

    for (i = 0; i < p_vec->N; ++i){
        printf("p_vec->p_array[%llu] : %d\n", i, p_vec->p_array[i]);
    }
}

void destroy_vector(struct vector* p_vec){
    free(p_vec->p_array);
    free(p_vec);
}




