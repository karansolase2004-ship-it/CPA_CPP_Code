#include <stdio.h>
#include <stdlib.h>


struct Date{
    int day;
    int month; 
    int year;
};

struct temp{
  double x, y;
};

int main (void){
    int* ptr = NULL;

    ptr = malloc(sizeof(int));

    int* pointer = ((void*)0);

    struct Date pDate;
    struct temp* p_temp = &pDate;

    return 0;
}