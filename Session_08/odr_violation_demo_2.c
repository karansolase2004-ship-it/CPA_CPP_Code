

#include <stdio.h>

void test_function(void);

int main(void){
    test_function();
    return 0;
}

void test_function(void){
    int num = 10;
    double num = 1.1;

    printf("in test_function()");
}