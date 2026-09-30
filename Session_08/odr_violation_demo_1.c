#include <stdio.h>

int add(int, int);
double add(double, double);

int main (void){
    int i_result;
    double dbl_result;

    i_result = add(10, 20);
    dbl_result = add(1.5, 3.8);

    printf(
          "i_result = %d, dbl_result = %.3lf\n",
           i_result, dbl_result
    );

    return (0);  
}

int add(int a, int b){
    return a+b;
}

double add(double d1, double d2){
    return d1 + d2;
}