#include "IDate.hpp"

#pragma comment(lib, "Date.lib")

int main(void){
    IDate* pIDate = IDate::get_instance(11, 8, 2024); 
    pIDate->show(); // Date::show(pIDate)
    pIDate->set_day(15); 
    pIDate->show(); 
    pIDate = 0; 

    // IDate p1IDate; 
  
    return 0; 
}

