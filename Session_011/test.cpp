#include <cstdio> 
#include <cstdlib> 

#define N 100 

int arr[N]; 

const int gnum = 100; 

void test(void); 

int main(void){
    // gnum = 600; // CTE: lhs expression must a modifiable lvalue 
    test(); 
    return (0); 
}

void test(void){
    const int local_num = 500; 
    // local_num = 700; // CTE: lhs expression must a modifiable lvalue 
    int* ptr = NULL; 
    
    ptr = const_cast<int*>(&local_num);   // warning 
                        // type(local_num) == const int     ... given by programmer 
                        // type(&local_num) == const int*   ... type system rule 
                        // type(ptr) == int*                ... given by programmer 
    printf("*ptr = %d\n", *ptr);     // 500 
    *ptr = 6000; 
    printf("*ptr = %d\n", *ptr);    // 6000 
    printf("local_num = %d\n", local_num); // 500 0

}