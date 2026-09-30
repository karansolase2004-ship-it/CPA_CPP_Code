#include <cstdio>


/*
  struct Date {
    int day;
    int month;
    int year;
};

void test(void){
    int n = 10;
    struct Date myDate = {1, 1, 1970};
    struct Date myBirthDate = {3, 5, 1990};
}*/

class Date{
    private :
        int day;
        int month;
        int year;
    public :
        Date(int init_day, int init_month, int init_year){
            this->day = init_day;
            this->month = init_month;
            this->year = init_year;
        }

        void show(){
            printf("Date::show():addre(this):%llu\n", 
                    (unsigned long long)this);
            printf("%d/%d/%d\n", this->day, this->month, this->year);
        }
};

int main (void){
    Date myDate_1(1, 1, 1970);
    Date myBirthDate(3, 5, 1990);

    myDate_1.show();
    myBirthDate.show();

    return(0);
}