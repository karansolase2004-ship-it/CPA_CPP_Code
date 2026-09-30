#include <iostream> 

class Date{
    private: 
        int day, month, year; 
    public: 
        Date(int _d, int _m, int _y) : day(_d), month(_m), year(_y){

        }

        void show() const {
            std::cout << "Date::show():" << day << "/" << month << "/" << year << std::endl; 
        } 
}; 

int main(void){
    Date myDate(22, 9, 2023); 
    myDate.show(); 

    int local_day = *(int*)((char*)&myDate + 0); 
    int local_month = *(int*)((short*)&myDate + 2); 
    int local_year = *(int*)((char*)&myDate + 8); 

    std::cout << "main:" << local_day << "/" << local_month << "/" << local_year << std::endl; 

    return 0; 
}