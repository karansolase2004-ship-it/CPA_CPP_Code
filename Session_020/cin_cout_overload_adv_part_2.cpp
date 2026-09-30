#include <iostream> 

class Date{
    private: 
        int day; 
        int month; 
        int year; 

    public: 
        friend std::ostream operator<<(std::ostream& os, const Date& date_object); 
        Date(int _dd, int _mm, int _yy) : day(_dd), month(_mm), year(_yy){

        }
}; 

std::ostream operator<<(std::ostream& os, const Date& date_object){
    os  << date_object.day << "/" 
        << date_object.month << "/" 
        << date_object.year 
        << std::endl; 
    return os; 
}


int main(void){
    Date epochDate_1(1, 1, 1970); 
    Date epochDate_2(1, 1, 1970); 

    std::cout << "EPOCH DATE:" << epochDate_1 << "EPOCH DATE :" << epochDate_2; 
    // std::cout << epochDate_1.day << std::endl;

    return 0; 
}

/* 
    n1: CPAint 
    n2: CPAint 

    n1 + n2; 
    == 
    n1.operator+(n2); 
    ==
    CPAint::operator+(&n1, n2); 
    
    class CPAint{
        private: 
            int n; 
        public: 
            CPAint operator+(const CPAint& other) const {
                // CPAint + CPAint
            }

            CPAint operaetor+(const int& number) const {
                // CPAint + int
            }
    }; 
    
    n1: CPAint 
    n2: CPAint 
    n1 + n2     // CPAint::operator+()    CPAint + CPAint 
    n1.operator+(n2); 

    n1: CPAint 
    k: int 
    n1 + k      // CPAint::operator+()  CPAint + int 
    n1.operator+(k)
    /////////////////////////////////////////////////////

    std::cout << epochDate; 

    std::cout:      std::ostream 
    epochDate       Date 

    namespace std{
        class ostream{
            public: 
                operator<<(const Date& date_object) const {
                    // logic to print date object 
                }
        }; 
    }

    std::cout << epochDate; 
    ==
    std::cout.operator<<(epochDate)
    ==
    std::ostream::operator<<(&std::cout, epochDate); 

    class myType{
    
    };

    myType mto; 

    std::cout << mto;  

    std::ostream& operator<<(std::ostream& os, const myType& your_object){
    
    }

    cout << date_object;

    cout.operator<<(date_object); 

    std::ostream::operator<<(&cout, date_object)

    date_object << cout 

    class Date{
        public: 
            operator<<(std::ostream& os){
            
            }
    }; 

*/