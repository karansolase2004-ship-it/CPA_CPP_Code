#include <iostream>

class Date
{
    private :
    int  day;
    int month;
    int year;

    public :
    Date(int _day, int _month, int _year) :
    day(_day), month(_month), year(_year)
    {

    }
    
    Date operator=(const Date& RHS)
    {
        this->day = RHS.day;
        this->month = RHS.month;
        this->year = RHS.year;

        // return *this;
    }

    void show()
    {
        std::cout
        << "Day : " << day << " " 
        << "Month : " << month << " " 
        << "Year : " << year;
    }
};

int main (void)
{

    Date obj1(1, 12, 2025);
    Date obj2(3, 02, 2015);
    Date obj3(29, 6, 2014);

    obj1 = obj2 = obj3;

    obj3.show();
    std::cout << std::endl;
    obj2.show();
    std::cout << std::endl;
    obj1.show();

    return 0;
}