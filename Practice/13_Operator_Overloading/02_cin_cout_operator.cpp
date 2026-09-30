#include <iostream> 

class Date{
    private: 
        int day,month, year; 
    public: 
        friend std::ostream& operator<<(std::ostream& os, const Date& date_object); 
        friend std::istream& operator>>(std::istream& os, Date& date_object); 
        
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

std::istream& operator>>(std::istream& is, Date& date_object){
    std::cout << "Enter day:"; 
    is >> date_object.day; 
    std::cout << "Enter month:"; 
    is >> date_object.month; 
    std::cout << "Enter year:"; 
    is >> date_object.year; 

    return is; 
}

int main(void){
    Date today; 
    Date tommorow;

    std::cin >> today >> tommorow; 
    std::cout << today << tommorow << std::endl; 
  
    return 0; 
}
