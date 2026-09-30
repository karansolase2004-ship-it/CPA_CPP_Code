#include <iostream>

class Date{
    private :
    int day, month, year;
    public :   
    Date(int _dd, int _mm, int _yy) : day(_dd), month(_mm), year(_yy){

    };

    Date operator<<(std::ostream& os){
        os  << this->day << "/" 
        << this->month << "/" 
        << this->year 
        << std::endl; 
    return os; 
    }
};

int main (void){
    Date first(1, 1, 1970);
    Date Second(1, 3, 2004);
    first << std::cout << Second;
}