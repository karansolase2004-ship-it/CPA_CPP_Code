//THis source code demonstartes default constructor 

#include <cstdio>

class Date1{
    private:
        int day;
        int month;
        int year;
    public:
        Date1 (){
            this->day = 1;
            this->month = 1;
            this->year = 1970;
        }

        void show(){
            printf(
            "%d/%d/%d\n", 
                this->day, this->month, this->year);
        }
};

class Date2{
    private:
        int day;  
        int month;
        int year;
    public: 
        Date2() :day(1), month(1), year(1970){

        }

        void show(){
            printf(
                "%d/%d/%d\n",
                    this->day, this->month, this->year);
        }
};

void test1();
void test2();

int main (void){
    test1();
    test2();

    return(0);
}

void test1(void){
    Date1 myDate1;

    puts("Test1():Entered");
    myDate1.show();
    puts("Test1:Leaving");
}

void test2(void){
    Date2 myDate2;

    puts("Test1():entered");
    myDate2.show();
    puts("Test2():Leaving");
}