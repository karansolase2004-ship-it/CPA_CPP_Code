#include "Date.hpp"
#include <iostream> 

Date::Date(int init_day, int init_month, int init_year) : 
    day(init_day), 
    month(init_month), 
    year(init_year)
{
    
}

int Date::get_day(){
    return day; 
}

int Date::get_month(){
    return month; 
}

int Date::get_year(){
    return year; 
}

void Date::set_day(int new_day){
    day = new_day; 
}

void Date::set_month(int new_month){
    month = new_month; 
}

void Date::set_year(int new_year){
    year = new_year; 
}

void Date::show(){
    std::cout << day << "/" << month << "/" << year << std::endl; 
}

IDate* IDate::get_instance(int init_day, int init_month, int init_year){
    return new Date(init_day, init_month, init_year); 
}

void IDate::release_instance(IDate* pIDate){
    delete (pIDate); 
}