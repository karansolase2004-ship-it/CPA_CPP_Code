#include <cstdio>

int& test(void);

int main (void){
    int q;
    int& p = q;
    int& a = test();
    // return type (int& ) should match variable (a) to which function call is assigned and type of return value(n) should be compatible (assignable) to a. 
}

int& test(){
    static int n;
    return n;
    // n value return करताना कोणत्या तिला compatible असणाऱ्या कोणत्या type मध्ये return करायची हे return type मधून सांगायचा असत  
}