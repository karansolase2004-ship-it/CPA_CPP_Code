#include <cstdio> 

void test(void); 

int main(void){
    test(); 
    return 0; 
}

void test(void){
    int num1 = 10; 
    int result_1;

    int num2 = 20; 
    int result_2; 

    printf("before assignment:num1 = %d\n", num1); 
    result_1 = ++num1; 
    printf("after assignment:num1 = %d, result_1 = %d\n", num1, result_1); 

    printf("before assignment:num2 = %d\n", num2); 
    result_2 = num2++; 
    printf("after assignment:num2 = %d, result_2 = %d\n", num2, result_2);  
}

/* 
int n1 = 20; 
    int n2 = 7; 

    int result; 

    result = n1 + n2; 
    result = n1 - n2; 
    result = n1 * n2; 
    result = n1 / n2; 
    result = n1 % n2; 
    result = n1 << n2; 
    result = n1 >> n2; 
    result = n1 & n2; 
    result = n1 | n2; 
    result = n1 ^ n2; 
    result = ~n1; 
    result = n1 && n2; 
    result = n1 || n2; 
    result = !n1; 
    result = n1 > n2; 
    result = n1 >= n2; 
    result = n1 < n2; 
    result = n1 <= n2; 
    result = n1 == n2; 
    result = n1 != n2; 

*/

/* 
result = ++num; 

movl    num, %eax 
addl    $1, %eax 
movl    %eax, num
movl    %eax, result 

#----------------------------

result = num++; 

movl    num, %eax 
movl    %eax, result 
addl    $1, %eax 
movl    %eax, num; 

atomic integer 

num = num + 1; 
*/

