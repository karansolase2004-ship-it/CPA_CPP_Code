class C{
    private: 
        // non-static data definition statement 
        // static data definition statement 
        // non-static function declaration / definition 
        // static funciton declaration / definition 
        // friend function / friend class declaration 
        // typedef 
    protected: 
        // non-static data definition statement 
        // static data definition statement 
        // non-static function declaration / definition 
        // static funciton declaration / definition 
        // friend function / friend class declaration 
        // typedef 
    public: 
        // non-static data definition statement 
        // static data definition statement 
        // non-static function declaration / definition 
        // static funciton declaration / definition 
        // friend function / friend class declaration 
        // typedef 
}; 

class Student{
    public: 
        typedef int roll_number_t; 
}; 

void test(void){
    Student::roll_number_t my_roll_number; 
}

namespace std{
    template <typename T> class vector{
        public: 
            typedef unsigned long long int size_type; 
    }   
}

void test2(void){
    std::vector<int>::size_type i; 
}
