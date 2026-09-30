#include <cstdio>

void test_function();

class Date{
    friend void test_function(void);
    private :
      int day, month, year;
      int add(){
        return 4+5;
       }
    public : 
       Date(int _day, int _month, int _year) : day(_day), month(_month), year(_year){

       }
       void show() const {
        printf("%d-%d-%d\n", day, month, year);
       }
};

int main(void){
    test_function();
    return 0;
}

void test_function(void){
    Date myDate(1, 1, 1970);
    myDate.show();
    myDate.day = 2;
    myDate.month = 3;
    myDate.year = 1990;
    myDate.show();
    printf("%d\n", myDate.add());
}