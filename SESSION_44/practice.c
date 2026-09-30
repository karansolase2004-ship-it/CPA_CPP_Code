#include <stdio.h>

int main (void){
    int n = 65;
    int a = 9;
    int* p = &a;

    printf("%d\n%d", p,p+1);

    char m ="";

    m = (char)n;

    printf("%s", m);
}