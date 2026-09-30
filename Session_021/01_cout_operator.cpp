#include <iostream> 

class Date{
    private: 
        int day,month, year; 
    public: 
        friend std::ostream& operator<<(std::ostream& os, const Date& date_object); 
        Date () : day(1), month(1), year(1970){

        }

        Date(int _day, int _month, int _year) : day(_day), 
                                                month(_month), 
                                                year(_year){
        }

}; 

std::ostream& operator<<(std::ostream& os, const Date& date_object){
    os  << date_object.day << "/" << date_object.month << "/" << date_object.year 
        << std::endl; 
    
    return os; 
}

int main(void){
    Date today(22, 6, 2024); 

    std::cout << today << std::endl; 
  
    return 0; 
}
