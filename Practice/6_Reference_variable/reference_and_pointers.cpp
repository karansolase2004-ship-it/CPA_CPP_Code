#include <cstdio>
#include <cstdlib>

void test(void);

int main (void){
    test();

    return 0;
}

void test(void){

    int* p = (int*)malloc(sizeof(int));
    if(NULL == p){
        puts("Error in allocating memory");
        exit(-1);
    }

    int& ref = *p;

    printf("%d\n", sizeof(ref));

    printf("Address in p = %p\n", p);
    printf("Address of ref = %p\n", &ref);
    printf("%d = %d\n", ref, *p);

    *p = 500;
    printf("ref = %d\n", ref);
    printf("*p = %d\n", *p);

    ref = 600;
    printf("ref = %d\n", ref);
    printf("*p = %d\n", *p);

    free(p);
    // OR
    free(&ref);
}