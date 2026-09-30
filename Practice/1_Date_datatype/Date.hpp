#include <cstdio>
#include <iostream>

class Date{
    private :
       int day;
       int month;
       int year;
    public :
       Date(); //Default constructor 
       Date(
        int init_day,
        int init_month,
        int init_year
       );

       int get_day();
       int get_month();
       int get_year();

       void set_day(int new_day);
       void set_month(int new_month);
       void set_year(int new_year);

       void show();

      friend std::ostream& operator<<(std::ostream& os, const Date& object)
      {
         os << object.day << "/" << object.month << "/" << object.year << std::endl;
      }
};