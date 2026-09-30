#include <iostream>

class Date{
    private :
      int day, month, year;

    public:
      friend std::ostream& operator<<(std::ostream& os, const Date& date_object);

      Date(int _dd, int _mm, int _yy) : day(_dd), month(_mm), year(_yy){

      }
};

std::ostream& operator<< (std::ostream& os, const Date& date_object){
    os << date_object.day << "/"
       << date_object.month << "/"
       << date_object.year
       << std::endl;
    return os;
}

int main (void){
    Date epochDate_1(1, 1, 1970);
    Date epochDate_2(1, 1, 1970);

    std::cout << "EpochDate : " << epochDate_1 << "Epoch Date :" << epochDate_2;

    return 0;
}