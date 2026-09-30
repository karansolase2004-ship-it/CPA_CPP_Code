#include <cstdio>

class Date{
    private : 
       int day, month, year;
    public : 
       //Default constructor 
       Date() : day(1), month(1), year(1970){

       }
       //OR
       Date(){
        this -> day = day;
        this -> month = month;
        this -> year = year;
       } 

       //Parameterized constructor 
       Date(int init_day, int init_month, int init_year) : day(init_day),
                                                           month(init_month),
                                                           year(init_year){

                                                           }
        //OR
        Date(int init_day, int init_month, int init_year){
            this -> day = init_day;
            this -> month = init_month;
            this -> year = init_year;
        }
};