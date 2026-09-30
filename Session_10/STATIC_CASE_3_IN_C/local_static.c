#include <cstdio>
void test(void);

int main (void){
    printf("1st call ");
    test();
    printf("2nd call");
    test();
    printf("3rd call");
    test();
    return 0;
}

void test(void){
    int m=9;
    static int n=7;
    m=m+10;
    n=n+10;
    printf("\n m =%d\n n = %d\n", m , n);
}

