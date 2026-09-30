#include <stdio.h> 

int main(void){
    int a = 10; 
    int b, c; 

    printf("BEFORE : a = %d, b = %d, c= %d\n", a, b, c); 

    c = b = a; 

    printf("AFTER : a = %d, b = %d, c= %d\n", a, b, c); 

    return (0); 
}