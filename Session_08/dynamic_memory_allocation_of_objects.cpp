#include <cstdio>

class Date{
    private:
       int day, month, year;
    public : 
       Date(); //Default CC

       Date(
           int init_day,
           int init_month,
           int init_year
       ); //Parameterized CC

       //Accessors
       int get_day();
       int get_month();
       int get_year();

       //Mutators
       void set_day(int new_day);
       void set_month(int new_month);
       void set_year(int new_year);

       // member function for displaying object 
    //    on the standard output device 
       void show();
};
 

Date::Date() : day(1) , month(1), year(1970){

}

Date::Date(
    int init_day, 
    int init_month, 
    int init_year) : day(init_day),
                     month(init_month),
                     year(init_year){

}

int Date::get_day(){
return this -> day;
}

int Date::get_month(){
return this -> month;
}

int Date::get_year(){
return this -> year;
}

void Date::set_day(int new_day){
     this -> day = new_day;
}

void Date::set_month(int new_month){
     this -> month = new_month;
}

void Date::set_year(int new_year){
     this -> year = new_year;
}

void Date::show(){
    printf("%d/%d/%d\n", this->day, this->month, this->year);
}

int main (void){
    Date* pDate_1 = new Date(5, 5, 2024);
    Date* pDate_2 = new Date;
    Date* pDate_3 = new Date;

    pDate_1->show();
    pDate_2->show();
    pDate_3->show();

    delete pDate_1;
    pDate_1 = 0;

    delete pDate_2;
    pDate_2 = 0;

    delete pDate_3;
    pDate_3 = 0;
}