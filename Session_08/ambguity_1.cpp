#include <cstdio>

float add(int, int);
int add(char, char);

int main(void){
    int i_result;
    float f_result;

    i_result = add(100, 200);
    f_result = add(100, 200);

    printf("i_result = %d\n f_result = %f\n", i_result, f_result);

    return 0;
}

int add(char a, char b){
    return a + b;
}

float add(int a, int b){
    return ((float)(a+b))/7.0;
}