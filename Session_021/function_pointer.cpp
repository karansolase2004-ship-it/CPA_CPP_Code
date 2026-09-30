#include <cstdio>

int add(int, int);
int sub(int, int);

int main (void){
    int (*add_func) (int, int);

    add_func= &add;
    int result = (*add_func)(5, 3);
    printf("add() Result = %d\n", result);
    printf("Address stored in add_func = %p\n", add_func);

    add_func = &sub;
    result = (*add_func)(5, 3);
    printf("Sub() Result = %d\n", result);
    printf("Address stored in add_func = %p\n", add_func);
}

int add(int a, int b){
    return a+b;
}

int sub(int a, int b){
    return a-b;
}