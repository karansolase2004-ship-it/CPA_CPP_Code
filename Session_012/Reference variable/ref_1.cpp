#include <cstdio>

int main(void){
    int n = 100;
    int& ref = n;
    int a = 90;
    int& a_topan = a;

    printf("&n =%llu, &ref = %llu\n",
        (unsigned long long)&n,
        (unsigned long long)&ref
        );

    printf("&n =%llu, &ref = %llu\n",
        (unsigned long long)&a,
        (unsigned long long)&a_topan
        );

        return 0;
}


//char c;
// int n
// float f;
// double d;
// struct Date myDate;
// Date myBirthDate;
// Book alg_book;
// QApplication app;
// std::mutex_lock mu;

// T* pT;