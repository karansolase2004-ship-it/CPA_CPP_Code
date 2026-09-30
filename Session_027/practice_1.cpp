#include <cstdio>
#include <cstdlib>

struct block{
    int n;
    int* ptr;
};

int main (void){
   struct block* p = (struct block*)malloc(sizeof(struct block));
   p->n = 10;
   struct block* p1 = (struct block*)malloc(sizeof(struct block));
   p1->n=20;
   p->ptr = &(p1->n);

   printf("p->n = %d\n", p->n)
   ;
   printf("p->ptr = %d\n", p->ptr);
   printf("*(p->ptr) = %d\n", *(p->ptr));
//    p->ptr->ptr;
   // u cannot access p->ptr->ptr because p->ptr is of type int* so it can access only p->ptr->n that too with help only syntax : *(p->ptr) not p->ptr->n because u cannot apply arrow operator on pointer to int
}
