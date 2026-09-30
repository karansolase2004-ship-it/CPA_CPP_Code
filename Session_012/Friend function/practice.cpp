#include <cstdio>

class Date{
    public : 
    int day;
    int month;
    int year;
    Date(int day, int month, int year) :day(day), month(month), year(year){

    } //Default constructor 
};

int main (void){
    Date mydate_1(1, 1, 1970);   
}