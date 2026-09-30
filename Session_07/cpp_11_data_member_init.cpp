#include <cstdio>

class Date{
    private: 
       int day = 1;
       int month = 3;
       const int year= 2004;
    public : 
       void show(){
        printf("%d/%d/%d\n", day, month, year);
       } 
};

int main (void){
    Date myDate;

    myDate.show();
}