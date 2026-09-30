#include <cstdio>

class Date{
    private : 
       int day; 
       int month;
       int year;

    public : 
       Date(int _day, int _month, int _year) : day(_day), month(_month), year(_year){



       }

       void show(){
        printf("%d/%d/%d\n", day, month, year);
       }
};

int main(void){
    Date myDate(18, 05, 2024);

    myDate.show();

    //myDate.day = 27;
    //myDate.month = 9;
    //myDate.year = 2024;

    *reinterpret_cast<int*>(reinterpret_cast<char*>(&myDate) + 0) = 27;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(&myDate) + 4) = 9;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(&myDate) + 8) = 2026;

    myDate.show();

    return 0;
}