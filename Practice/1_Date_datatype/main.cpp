#include <cstdio>
#include "Date.hpp"

int main (void){
    Date mydate_1;
    mydate_1.show();
    Date mydate_2(1, 1, 1970);
    mydate_2.show();
    mydate_2.set_day(12);
    mydate_2.set_month(12);
    mydate_2.set_year(2012);
    mydate_2.show();
    printf("%d/%d/%d\n", mydate_1.get_day(), mydate_1.get_month(), mydate_1.get_year());
}