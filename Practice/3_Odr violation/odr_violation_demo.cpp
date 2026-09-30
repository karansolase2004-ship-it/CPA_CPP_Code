#include <cstdio>

float add(float, float);
double add(double, double);

int main (void){
    double dbl_result;

    dbl_result = add(1.5, 3.8f);

    printf("ldbl_result = %.3lf", dbl_result);

    return 0;
}

double add(double d1, double d2){
    return d1+d2;
}