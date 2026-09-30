#include <stdio.h>
#include <stdlib.h>

// const int g_num = 100;

 void test(void);

int main (void){
    // g_num = 600; //CTE: lhs expression must be a modifiale l Value
    test();   
    // int *ptr = &g_num;
    // *ptr = 5000; //General rpotection fault #GPF -> memory violation exception
    puts("End of program");

    return 0;
}

void test(void){
    const int local_num = 500;
    // local_num = 700; // CTE : lhs expression must be a modifiable value
    int * ptr = NULL;
printf("local_num = %d\n", local_num);
    ptr = &local_num; //Warning 
                      // type(local_num) == const int* ... given by programmer
                      // type(&local_num) == const int* ... type system  rule 
                      // type(ptr) == int*              ... given by programmer
    printf("*ptr = %d\n", *ptr);    // 500
    *ptr = 6000;
    printf("*ptr = %d\n", *ptr); //6000
    printf("local_num = %d\n", local_num);
}