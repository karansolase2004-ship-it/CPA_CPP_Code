 #include <cstdio> 

class Date_1{
    private:
        int day; 
        int month; 
        int year;
};

class Date_2{
    public: 
        int day; 
        int month; 
        int year; 
}; 

void test1(void); 
void test2(void); 
 
int main(void){
    test1(); 
    test2(); 

    return (0); 
}

void test1(void){
    // FRAGMENT 1 
    Date_1 myDate1; 

    printf("Sizeof(myDate1):%d\n", sizeof(myDate1)); 

     myDate1.day = 1;     // Compile Time Error
     myDate1.month = 1;   // Compile Time Error
     myDate1.year = 1970; // Compile Time Error
}

void test2(void){
    // FRAGMENT 2 
    Date_2 myDate2; 

    printf("Sizeof(myDate2):%llu\n", sizeof(myDate2)); 

    myDate2.day = 1; 
    myDate2.month = 1; 
    myDate2.year = 1970; 
}

