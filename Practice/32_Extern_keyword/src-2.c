#include <stdio.h>   // for declaration of printf() 

extern int g_num;   // type declaration of g_num 
                    // definition of g_num is in src-1.c 

extern void insertion_sort(int* a, int N); // type declaration of sort() function 
                                 // definition of sort() is in src-3.c 

int main(void)
{
    int i_arr[5] = {50, 40, 30, 20, 10}; 
    int i; 

    printf("g_num = %d\n", g_num); // 10 
    
    puts("Show:i_arr:Before sort:"); 
    for(i = 0; i < 5; ++i)
        printf("i_arr[%d]:%d\n", i, i_arr[i]); 

    insertion_sort(i_arr, 5); 

    puts("Show:i_arr:After sort:"); 
    for(i = 0; i < 5; ++i)
        printf("i_arr[%d]:%d\n", i, i_arr[i]); 

    return (0); 
}