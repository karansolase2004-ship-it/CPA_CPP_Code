#include <cstdio>

class Date{
    private : 
       int day;
       int month;
       int year;
       static int n;
};

// int Date::n;

int main (void){
    int Date::n;
}