#include "IDate.hpp"

#pragma comment(lib, "Date.lib")

int main(void){
    IDate* pIDate = IDate::get_instance(11, 8, 2024); 
    pIDate->show(); 
    pIDate->set_day(15); 
    pIDate->show(); 
    IDate::release_instance(pIDate);
    pIDate = 0; 

    IDate pDate;

    return 0; 
}