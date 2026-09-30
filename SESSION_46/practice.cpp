#include <cstdio>

int main (void){
    char a = 1;
    short b = 2;
    int c = 3;
    int d = 4;
    long e = 5;
    long long g = 6;

    float f = a;
    printf("%f\n", f);
    f = b;
    printf("%f\n", f);
    f = c;
    printf("%f\n", f);
    f = d;
    printf("%f\n", f);
    f = e;
    printf("%f\n", f);
    f = g;
    printf("%f\n", f);

    unsigned int temp = -587;

    signed int pemt = temp;

    printf("%d\n", pemt);
}