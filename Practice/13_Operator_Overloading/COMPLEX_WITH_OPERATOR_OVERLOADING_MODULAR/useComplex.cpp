#include "Complex.hpp"

int main (void){
    Complex c1(1.1, 2.2);
    Complex c2(3.3, 4.4);

    Complex summation = c2 + c1;
    Complex subtraction = c2 - c1;

    c1.show("c1 :");
    c2.show("c2 :");
    summation.show("Summation:");
    subtraction.show("Subtraction:");

    return (0);
}