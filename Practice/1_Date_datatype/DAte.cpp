#include <cstdio>
#include "Date.hpp"

Date::Date() : day(1), month(3), year(2004){

};


Date::Date(
    int init_day,
    int init_month,
    int init_year
){
    this->day = init_day;
    this->month = init_month;
    this->year = init_year;
};

int Date::get_day(){
    return this->day;
}

int Date::get_month(){
    return this->month;
}

int Date::get_year(){
    return this->year;
}

void Date::set_day(int new_day){
    this->day = new_day;
}

void Date::set_month(int new_month){
    this->month = new_month;
}

void Date::set_year(int new_year){
    this->year = new_year;
}

void Date::show(){
    printf("%d/%d/%d\n", this->day, this->month, this->year);
}


