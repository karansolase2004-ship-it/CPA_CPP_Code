#include <cstdio>

class Date_1{
    private:
        int day;
        int month;
        int year;
    public:
        Date_1() : day(3), month(5), year(1999){

        }

        void show(){
            printf("%d/%d/%d\n", this->day, this->month, this->year);
        }
};

class Date_2{
    private:
        int day;
        int month;
        int year;
    public: 
        Date_2(int init_day, int init_month, int init_year) : day(init_day),
                                                              month(init_month),
                                                              year(init_year)
        {

        }

        void show(){
            printf("%d/%d/%d\n", this->day, this->month, this->year);
        }
};

int main (void){
    Date_1 myDate;
    Date_2 myBirthDate(2, 6, 2002);

    myDate.show();
    myBirthDate.show();

    return(0);
}