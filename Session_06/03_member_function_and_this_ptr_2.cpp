#include <cstdio>

class Date{
    private:
        int day;
        int month;
        int year;
    public:
        void  show_member_addresses(){
            puts("Date::show_member_addresses() -> entered");
            printf("Address of a calling object: %lllu\n", 
                    (unsigned long long)this);
            printf("addr(this -> day):%llu\n",
                    (unsigned long long)&this -> day);
            printf("addre(this -> month):%llu\n",
                    (unsigned long long)&this -> month);
            printf("addr(this -> year):%llu\n",
                    (unsigned long long)&this -> year);
            puts("Date::show_member_addresses() -> leaving");
        }
};

int main (void)
{
    Date myDate1;
    Date myDate2;

    printf("&myDate1:%llu\n", (unsigned long long)&myDate1);
    printf("&myDate2:%llu\n", (unsigned long long)&myDate2);

    myDate1.show_member_addresses();
    myDate2.show_member_addresses();

    return(0);
}