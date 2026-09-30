#include <iostream> 

class Date{
    private: 
        int day, month, year; 
    public: 
        Date() : day(1), month(1), year(1970){

        } 

         
         Date(int _day, int _month, int _year) : day(_day), 
                                                month(_month), 
                                                year(_year){
        } 

        int get_day() const { return day; }
        int get_month() const { return month; }
        int get_year() const { return year; }

        void set_day(int new_day) { day = new_day; }
        void set_month(int new_month) { month = new_month; }
        void set_year(int new_year) { year = new_year; }

        void show(const char* msg) const {
            if(msg)
                std::cout << msg << std::endl; 
            std::cout << day << "/" << month << "/" << year << std::endl; 
        }
}; 

void test_1(void); 

int main(void){
    test_1(); 
    return 0; 
}

void test_1(void){
    Date myDate1;   // Default CC 
    myDate1.show("Showing myDate1:"); // 1/1/1970 

    Date myDate2(23, 6, 2024); // Parameterized CC 
    myDate2.show("Showing myDate2:");   

    Date myDate3(myDate1);  // SAME AS Date myDate3 = myDate1; 
    myDate3.show("Showing myDate3:"); 

    Date myDate4 = myDate2; 
    myDate3.show("Showing myDate3 after assigning myDate2 to it:"); 
}

/* 
    Date myDate1; 
    Memory will be allocated to myDate1 (12 bytes) in the local storage of test_1() 
    and it will be passed through the default constructor Date::Date() where its 
    day, month and year members will be assigned to 1, 1, 1970. 

    Date myDate2(23, 6, 2024); 
    Memory will be allocated to myDate2 (12 bytes) in the local storage of test_1() 
    and it will be passed through the parameterised constructor Date::Date(int, int, int)
    and _day, _month, _year formal parameters of the Date::Date(int, int, int) will be 
    initialised by 23, 6, and 2024 respectively. 

    The parameterised constructor will initialise the day, month and year members of 
    myDate2 to _day(23), _month(6), _year(2024) respectively! 


    Date myDate3(myDate1); 
    Memory will be allocated to myDate3 (12 bytes) in the local storage of test_1() 
    The myDate3 will require an overloaded constructor having following formal parameter list 

    Date::Date(const Date& date_object) :   day(date_object.day), 
                                            month(date_object.month), 
                                            year(date_object.year){
    }

    The above constructor has one invisible this pointer. 
    actual parameter of this pointer = &myDate3 

    Named formal parameter date_object is a const reference to Date 
    and therefore, its actual parameter must be a date object which it is! 
    Reference myDate1 will be date_object.  

    myDate3 = myDate2; 

    Date& operator=(const Date& rhs_object){
        this->day = rhs_object.day; 
        this->month = rhs_object.month; 
        this->year = rhs_object.year; 
        return *this; 
    }

    int a = 10; 
    int b; 

    b = a; 

    int c; 

    c = b = a = 10; 

*/

/* 
Date myDate; 
Date myDate(1, 1, 1970); 

Date newDate(existingDateObject);

Date newObject = std::move(existingDateObject); 

int n = 10; 


Date myDate2 = myDate1; 

Date myDate(myDate1); 
*/

/* 
    
*/  