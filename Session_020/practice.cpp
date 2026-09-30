#include <cstdio>

int post_increment(int&);
int pre_increment(int&);

int main (void){
    int i = 11;
    int result;
    result = post_increment(i);
    printf("i = %d\nResult = %d\n",i, result);
    result = pre_increment(i);
    printf("i = %d\nResult = %d\n",i, result); 
}

int post_increment(int& i){
    int result;
    result = i;
    i = i + 1;

    return result;
}

int pre_increment(int& i){
    i = i + 1;
    return i;
}