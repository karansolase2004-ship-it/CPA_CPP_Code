#include <cstdio>

class Date{
    private: 
        int day;
        int month;
        int year;
    public:
        Date(){
            puts("Inside Date::Date()");
            printf("Date::Date()->Address in this ptr:%llu\n",
                    (unsigned long long)this);
        }
};

int main (void){
    Date myDate1;
    printf("main():addr(myDate_1):%llu\n", (unsigned long long)&myDate1);
    
    Date myDate2;
    printf("main():addr(myDate_2):%llu\n", (unsigned long long)&myDate2);
    
    Date myDate3;
    printf("main():addr(myDate_3):%llu\n", (unsigned long long)&myDate3);

    return(0);
}