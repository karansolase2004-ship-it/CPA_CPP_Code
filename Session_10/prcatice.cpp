#include <cstdio>

class Date{
    private :
       int day, month, year;
    public : 
    static int n;
    void show(){
        printf("HI how are you ? ");
    }
};

int Date::n = 20;



int main (void){
    Date mydate_1;
    mydate_1.show();
    printf("%d\n", Date::n);
}