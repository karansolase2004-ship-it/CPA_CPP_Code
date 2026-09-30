 #include <stdio.h>

 class Date{
    private : 
       int day , month, year;
};

const Date myDate;

int m = 100;
const int n = 200;


int main (void){
    const Date myDate;
    m = 1000;
    // n  = 2000  // CTE : an expression must be a modifiable l value 
}

// lValue  ==  location Value  == memory location
// m = 10000;
// 10000 = m;
