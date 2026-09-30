#include <stdio.h>

#ifndef OFFSET_OF 
#define OFFSET_OF(type, member)     ((size_t)(&((type*)0)->member))
#endif 

#ifndef CONTAINER_OF 
#define CONTAINER_OF(addr, type, member)  ((type*)((size_t)addr - OFFSET_OF(type, member)))
#endif 

struct Date{
    int day;
    int month;
    int year;
};

int main (void){
    int a= 133;

    struct Date date;

    (*(&date)).day = 125;
    (&date)->month = 01;
    (&date)->year = 01;

    printf("%d/%d/%d\n", date.day, date.month, date.year); 
}