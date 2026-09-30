#include <cstdio>

void swap(int& ref_a, int& ref_b);

int main (void){
    int a = 120;
    int b = 140;

    printf("&a = %llu, &b = %llu\n",
            (unsigned long long)&a,
            (unsigned long long)&b
            );

    swap(a,b);
    printf("a = %d\nb = %d\n", a,b);

    return 0;
}

void swap(int& ref_a, int& ref_b){

    printf("&ref_a = %llu,  &ref_b = %llu\n",
            (unsigned long long)&ref_a,
            (unsigned long long)&ref_b
            );

    int tmp;
    tmp = ref_a;
    ref_a = ref_b;
    ref_b = tmp;
}