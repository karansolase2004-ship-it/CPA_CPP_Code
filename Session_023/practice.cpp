#include <cstdio>
#include <cstdlib>

int main (void){
    int* p =NULL;
    p = (int*)realloc(p, 5 * sizeof(int));
    if(NULL == p){
        puts("Error in allocating the memory");
        exit(-1);
    }

    printf("%d\n", p);
    p = (int*)realloc(p, 10 * sizeof(int));
    printf("%d\n", p);

}