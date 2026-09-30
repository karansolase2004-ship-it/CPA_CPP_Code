#include <cstdio>

class Date{
    private:
        int day;
        int month;
        int year;
    public:
        Date(){
            this->day = 1;
            this->month = 1;
            this->year = 1970;
        }

        void show(){
            printf("Date::show():addr(this):%llu\n",
                    (unsigned long long)this);
            printf("%d/%d/%d\n", this->day,this->month,this->year);
        }
};

int main (void)
{
    Date myDate_1;
    Date myDate_2;
    Date myDate_3;

    printf("main():addr(myDate_1):%llu\naddr(myDate_2):%lluaddr(myDate_3):%llu",
            (unsigned long long)&myDate_1,
            (unsigned long long)&myDate_2,
            (unsigned long long)&myDate_3);

    myDate_1.show();
    myDate_2.show();
    myDate_3.show();

    return(0); 
}