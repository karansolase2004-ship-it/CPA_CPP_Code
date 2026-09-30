#include "Complex.hpp"
#include <cstdio>

Complex::Complex() : re(0.0), im(0.0){

}

Complex::Complex(double _re, double _im) : re(_re), im(_im) {

}

void Complex::show(const char* msg) const{
    if(msg)
       puts(msg);
    printf("(%.3lf) + i(%.3lf)\n", this->re, this->im);
}

Complex Complex::operator+(const Complex& other) const{
    Complex result;

    result.re = this->re + other.re;
    result.im = this->im + other.im;

    return (result);

    // return Complex(this->re + other.re, this->im + other.im);
}

Complex Complex::operator-(const Complex& other) const{
    Complex result;

    result.re = this->re - other.re;
    result.im = this->im - other.im;

    return(result);

    //return Complex(this->re - other.re, this->im - other.im)
}