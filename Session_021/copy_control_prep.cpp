#include <iostream>

class Date{
    private :
      

    public :


    void set_day(int new_day) {day = new_day; } 
    void set_month(int new_month) { month = new_month;}
    void set_year( int new_year) {year = new_year; }

    void show(const char* msg) const {
        if(msg)
           puts(msg);
           std::cout << msg << std::endl;
        std::cout << day << "/" << month << "/" << year << std::endl;
    }
};

int main (void){
    test_1(); 

    return 0;
}

void test_1(void){
    Date myDate_1; // Default CC
    myDate_1.show("Showing myDate1:"); // 

    Date 
}