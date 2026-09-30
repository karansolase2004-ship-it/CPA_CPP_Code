#include <iostream>

class A{
    private : 
       char b1;
       int a;
       float c;
       char b;
       static double x, y, z;

    public : 
       A() : a(10), b1('A'), c(3.14f){

       }

       int geta() const { return a; };
       void seta(int new_a) { a = new_a; }
};

double A::x;
double A::y;
double A::z;

int main (void){
    A objA;
    std::cout << "sizeof(objA) :" << sizeof(objA) << std::endl;
     
    return 0;
}