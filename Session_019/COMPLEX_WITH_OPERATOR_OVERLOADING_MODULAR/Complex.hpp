#ifndef _COMPLEX_H
#define _COMPLEX_H

class Complex{
    private :
       double re;
       double im;

    public :
       Complex();
       Complex(double _re, double _im);
       void show(const char* msg) const;
       Complex operator+(const Complex& other) const;
       Complex operator-(const Complex& other) const;
};

#endif
