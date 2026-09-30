#include <cstdio>

namespace X{
    int num;
    float f_num;

    struct Date{
        int day;
        int month;
        int year;
    };

    // struct Date myDate_1;

    class date{
        public : 
        static int day = 01;
        int month;
        int year;

        void show(){
            printf("%d/%d/%d\n", this->day, this->month, this->year);
        }
    };

    int add(){
        return 6+7;
    }

    namespace Y{
        int l;
    }

};

int main (void){
    X::num = 5;
    X::f_num = 9;

    X::Date myDate_1;
    myDate_1.day = 8;
    myDate_1.month = 7;
    myDate_1.year = 1789;

    X::date mydate_1;
    // mydate_1.day = 8;
    mydate_1.month = 8;
    mydate_1.year = 7002;

    mydate_1.show(); 

    X::Y::l = 9;
}

