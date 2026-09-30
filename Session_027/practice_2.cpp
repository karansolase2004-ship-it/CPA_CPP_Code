#include <cstdio>
#include <cstdlib>

struct block{
    int n;
    struct block* ptr;
};

int main (void){
    struct block* p1 = (struct block*)malloc(sizeof(struct block));
    p1->n = 10;
    struct block* p2 = (struct block*)malloc(sizeof(struct block));
    p1->ptr = p2;
    p1->ptr->n = 20;
    p2 = (struct block*)malloc(sizeof(struct block));
    p1->ptr->ptr = p2;
    p1->ptr->ptr->n = 30;
    p2 = (struct block*)malloc(sizeof(struct block));
    p1->ptr->ptr->ptr = p2;
    p1->ptr->ptr->ptr->n = 40;
    p2 = (struct block*)malloc(sizeof(struct block));
    p1->ptr->ptr->ptr->ptr = p2;
    p1->ptr->ptr->ptr->ptr->n = 50;
    p1->ptr->ptr->ptr->ptr->ptr = NULL;

    p2 = p1;

    while(p2->ptr != NULL){
        printf("n = %d\n", p2->n);
        p2 = p2->ptr;
        if(p2->ptr == NULL){
        printf("n = %d\n", p2->n);
    }
    }
}