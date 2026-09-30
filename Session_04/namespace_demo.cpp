#include <cstdio>

namespace X{
    int num_m = 100;
    float f_num = 700;
}

int num = 750;


int main (void){
    printf("NUMBER  = %d\n", X::num_m);
    printf("NUMBER = %f\n", X::f_num);
    printf("NUMBER = %d\n", num);
    X::num_m = 9;
    X::f_num = 50;
    num = 0;
    printf("NUMBER  = %d\n", X::num_m);
    printf("NUMBER = %f\n", X::f_num);
    printf("NUMBER  = %d\n", num);
}