#include<cstdio>

class Date{
    private:
        int day;
        int month;
        int year;
    public:
        //Mutators
        void set_day(int new_day){
            this->day = new_day;
            //day = new_day; is also valid 
            //C++ compiler is intelligent to 
            //convert day = new_day into this->day = mew_day;
        }

        void set_month(int new_month){
            this->month = new_month;
        }

        void set_year(int new_year){
            year = new_year;
        }

        //Accessors
        int get_day(){
            return this->day;
        }

        int get_month(){
            return this->month; 
        }

        int get_year(){
            return this->year;
        }
};

int main (void)
{
    Date myDate;
    int dd, mm, yy;

    //Fetching the member values using accessors
    //Showing garbage values of myDate
    dd = myDate.get_day();
    mm = myDate.get_month();
    yy = myDate.get_year();
    printf("%d/%d/%d\n", dd, mm, yy);

    //Setting valid values using mutators
    myDate.set_day(1);
    myDate.set_month(8);
    myDate.set_year(2024);

    //Again applying accessors to test
    //The mutators
    dd = myDate.get_day();
    mm = myDate.get_month();
    yy = myDate.get_year();

    printf("%d/%d/%d\n", dd, mm, yy);

    return(0);
}