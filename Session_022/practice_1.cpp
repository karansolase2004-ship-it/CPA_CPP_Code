#include <cstdio>
#include <iostream>

class Date{
    private :
      int day, month, year;
    public :
       Date() : day(1), month(1), year(1970){

       };

       Date(int init_day, int init_month, int init_year) : 
       day(init_day), 
       month(init_month),
       year(init_year){

       };

       void show(){
        std::cout 
           << this->day <<  "/"
           << this->month << "/"
           << this->year << std::endl; 
       };
};

int main (void){
    Date mydate_1;
    Date mydate_2(01, 03, 2004);
    Date mydate_3(14, 5, 1996);

    mydate_1.show();
    mydate_2.show();
    mydate_1 = mydate_2 = mydate_3;
        mydate_1.show();

}