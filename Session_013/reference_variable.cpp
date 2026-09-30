#include <cstdio>
#include <cstdlib>

//reference variable general syntax 
// T& ref = RHS_EXPR ; // type(RHS_expr) == T

void test(void);

int main (void){
    test();
    return 0;
}

void test(void){
    int m;

    int&  n = m; //type(m) = int ....annoted by programmer

    printf("%d\n", n);

    int* p = (int*)malloc(sizeof(int));
    if (NULL == p){
        puts("Error in alocating memory");
        exit(-1);
    }

    int& ref = *p;

    printf("%d\n", sizeof(ref));

    printf("Addr in p =%p\n", p);
    printf("Addr of ref = %p\n", &ref);
    printf("%d = %d\n", ref, *p);

    *p = 500;
    printf("ref = %d\n", ref);
    printf("*p  = %d\n", *p);

    ref = 600;
    printf("ref = %d\n", ref);
    printf("*p  = %d\n", *p);

    free(p);
    free(&ref);
}

// int& ref = *p;
//  T& ref = expr_with_type_T_which_represents_memory_block_of_type_T
//  ref -> type(ref) == T