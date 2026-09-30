#include <cstdio>

int& test(void);

int main (void){
    int p;
    int& q=p;
    int& a = test();
}

int& test(){
    static int n;
    return n;
}