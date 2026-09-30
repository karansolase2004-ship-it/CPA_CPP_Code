#include <iostream> 

class Date{
    private: 
        int day, month, year; 
    public: 
        Date(int _d, int _m, int _y) : day(_d), month(_m), year(_y){

        }

        int get_day() const { return day; }
        int get_month() const { return month; }
        int get_year() const { return year; }
        void set_day(int new_day) { day = new_day; }
        void set_month(int new_month) { month = new_month; }
        void set_year(int new_year) { year = new_year; }
}; 

void use_case_1(void);  // discard const 
void use_case_2(void);  // enforce constness
void access_date(Date* pDate); 

int main(void){
    use_case_1(); 
    use_case_2(); 
    return 0; 
}

void use_case_1(void){
    std::cout << "-------USE CASE 1--------" << std::endl; 
    const int num = 100; 
    int* p_num; 

    p_num = const_cast<int*>(&num); 

    std::cout << "BEFORE:" << *p_num << std::endl; 
    *p_num = 500; 
    std::cout << "AFTER:" << *p_num << std::endl; 
}

void use_case_2(void){
    Date today(29, 9, 2024); 
    access_date(&today); 
}

void access_date(Date* pDate){
    std::cout << "-------USE CASE 2--------" << std::endl; 
    int dd, mm, yy; 

    // part : accessors 
    dd = const_cast<const Date*>(pDate)->get_day(); 
    mm = const_cast<const Date*>(pDate)->get_month(); 
    yy = const_cast<const Date*>(pDate)->get_year(); 

    dd = 14;
    std::cout << "access date:" << dd << "/" << mm << "/" << yy << std::endl; 

    // part : mutators 
    // invoke mutators 
}