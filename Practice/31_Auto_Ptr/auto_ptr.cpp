#include <iostream> 
#include <memory> 

class Date{
    private: 
        int dd, mm, yy; 
    public: 
        Date(int _dd, int _mm, int _yy) : dd(_dd), mm(_mm), yy(_yy){

        }

        ~Date(){
            std::cout << "In Dtor of Date" << std::endl; 
        }

        void show() const {
            std::cout << dd << "/" << mm << "/" << yy << std::endl; 
        }

        void set_day(int new_day) 
        {
            this->dd = new_day;
        }

        void set_month(int new_month) 
        {
            this->mm = new_month;
        }

        void set_year(int new_year) 
        {
            this->yy = new_year;
        }
}; 

void test(void); 

int main(void){
    test(); 
    return 0; 
}

void test(void){
    int n; 
    std::auto_ptr<int> pint(new int(100)); 
   // Not prefered :  
    /* int a;
    std::auto_ptr<int> p2_int(&a);
    std::cout << *p2_int << std::endl;
    *p2_int = 890;
    std::cout << *p2_int << std::endl; */

    
    std::cout << *pint << std::endl; 
    *pint = 200; 
    std::cout << *pint << std::endl; 

    std::auto_ptr<Date> pDate(new Date(19, 10, 2024)); 
    pDate->show(); 
    pDate->set_day(3);
    pDate->set_month(8);
    pDate->set_year(2025);
    pDate->show();
}
