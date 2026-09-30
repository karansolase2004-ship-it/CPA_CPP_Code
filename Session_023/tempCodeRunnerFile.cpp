#include <cstdio>
#include <cstdlib>

int main (void){
    int* p =NULL;
    p = (int*)malloc(5 * sizeof(int));
    if(NULL == p){
        puts("Error in allocating the memory");
        exit(-1);
    }

    p = (int*)malloc(5 * sizeof(int));
    
}