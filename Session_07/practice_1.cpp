#include <cstdio>

class Date{
    private : 
        int day;
        int month;
        int year;
    public : 
        Date(int day, int month, int year) : day(day), month(month), year(year){

    }

    void show(){
        printf("%d/%d/%d\n",day, month, year);
    }
};

int main (void){



Date myDate1(1, 3, 2004);

myDate1.show();
}