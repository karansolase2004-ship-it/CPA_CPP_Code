#include <iostream> 
#include "Date.hpp"

#pragma comment(lib, "Date.lib")

int main(void){
    Date myDate(11, 8, 2024); 

    myDate.show(); 

    int day = myDate.get_day(); 
    int month = myDate.get_month(); 
    int year = myDate.get_year();

    std::cout << "getter:" << day << "/" << month << "/" << year << std::endl; 

    myDate.set_day(12); 
    myDate.set_month(9); 
    myDate.set_year(2025); 

    day = myDate.get_day(); 
    month = myDate.get_month(); 
    year = myDate.get_year();

    std::cout << "getter:" << day << "/" << month << "/" << year << std::endl; 

    return 0; 

}