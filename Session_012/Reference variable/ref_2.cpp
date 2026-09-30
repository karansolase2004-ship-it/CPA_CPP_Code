#include <cstdio>

void swap(int& ref_a, int& ref_b);

int main (void){
    int a = 10;
    int b = 20;

    swap(a, b);
    printf("a = %d\nb= %d\n", a, b);

    return 0;
}

void swap(int& ref_a, int& ref_b){
    int tmp;
    tmp = ref_a;
    ref_a = ref_b;
    ref_b = tmp;
}