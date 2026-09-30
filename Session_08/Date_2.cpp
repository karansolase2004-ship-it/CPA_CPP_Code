#include <cstdio>

class Date{
    private: 
       int day, month, year;
    public : 
       Date() : day(1), month(1), year(1970){

       }

       Date(    
           int init_day,
           int init_month,
           int init_year) : day(init_day),
                            month(init_month),
                            year(init_year){
                                printf("How are you bro ? ");
        }

        int get_day(){
            return this -> day;
        }

        int get_month(){
            return this-> month;
        }

        int get_year(){
            return this-> year;
        }

        void set_day(int new_day){
            this->day = new_day;
        }

        void set_month(int new_month){
            this->month = new_month;
        }

        void set_year(int new_year){
            this->year = new_year;
        }

        void show(){
            printf("%d/%d/%d\n", this->day, this->month, this->year);
        }
};

int main (void){
    Date epochDate;
    Date cpaOfficialStartingDate(28, 5, 2015);


    epochDate.show();
    cpaOfficialStartingDate.show();

    return(0);

}