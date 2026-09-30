#include <cstdio>
#include <cstdlib>

int* test_1();

int main(void){
    int* m;
    m = test_1();
    printf("%p = %d\n", m, *m );
}

int* test_1(){
    static int p;
    return  &p;
}