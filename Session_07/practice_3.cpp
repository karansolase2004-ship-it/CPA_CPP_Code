#include <cstdio>

class Date{
    private: 
       int day; 
       int month;
       int year;
    public:
       Date(): day(1), month(2){

       }
       Date() : year(2003){

       }
       void show(){
        printf("%d/%d/%d\n", day, month, year);
       }
};

int main (void){
    Date myDate1;
myDate1.show();
}