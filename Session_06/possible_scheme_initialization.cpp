#include <cstdio>

class Date{
    private:
        int day;
        int month;
        int year;

    public:
        void init_date(int init_day, int init_month, int init_year){
            this->day = init_day;
            this->month = init_month;
            this->year = init_year;
        } 

        void show(){
            printf("%d/%d/%d\n", 
                    this->day,
                    this->month,
                    this->year
                );
        }
};


int main (void){
    Date myDate;
    myDate.init_date(1, 1, 1970);
    myDate.show();

    
    return(0);
}