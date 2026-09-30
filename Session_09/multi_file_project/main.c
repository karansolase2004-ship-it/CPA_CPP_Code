#include <stdio.h>

/* struct Date{
    int day;
    int month;
    int year;
};

struct Date myDate; */

extern double cpa_sin(double);
extern double cpa_cos(double);
extern double angle;

int main (void){
    cpa_sin(angle);
    cpa_cos(angle);

    return(0);
}
