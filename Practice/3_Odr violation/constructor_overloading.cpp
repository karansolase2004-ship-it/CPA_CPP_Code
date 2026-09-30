#include <cstdio>

class Date{
    private :
       int day;
       int year;
    public :
       Date( const int init_day) : day(init_day) {

       };

       Date(int init_year) : year(init_year){

       }
};

int main(void){
    Date mydate_1(1254);
}