#include <cstdio>
#include <cstdlib>

const int g_num = 100;

void test(void);

int main (void){
    // g_num = 400;
    int* ptr = NULL;
    // ptr = &g_num;
    // ptr = const_cast<int*>(&g_num); // it will not work as variable is stored in hadrware protected memory area so it will give  
    //  memory violation exception
    printf("*ptr = %d\n", *ptr);
    // *ptr = 520;
    // printf("%d\n", *ptr);

    test();
}

void test(void){
    const int local_num = 500;
    // local_num = 700; //CTE : lhs expression must be a modifiable value 
    int *ptr = NULL;
    // ptr = &local_num
    ptr = const_cast<int*>(&local_num);
    printf("*ptr = %d\n", *ptr); // 500;
    *ptr = 6000;
    printf("*ptr = %d\n", ptr);  // 6000
    printf("local_num = %d\n", local_num); // 500 
    // because local_num is treated as symbolic constant
}