/* 
complex Number : twp real numbers in order
A complex number is an ordered pair of real number 
 
 (1.1, 2.2)
 */

#include <cstdio>
#include <cstdlib>

class complex{
   private : 
     double re;  // real part 
     double im;  // imaginary part

     public : 
       complex() : re(0.0), im(0.0) {

       } 

       complex(double _re, double _im) : re(_re), im(_im){

       }

       complex add(complex second_number){
         complex summation_object;
         summation_object.re = this->re + second_number.re;
         summation_object.im = this->im + second_number.im;
         return summation_object;
       }

       void show(const char* msg) const{
         if(msg)
            puts(msg);

         printf("(%.3llf) + i(%.3llf)\n", re, im);
       }
};

int main (void){
   complex c1;
   complex c2(1.1, 2.2);
   complex sum;
   c1.show("c1: ");
   c2.show("c2 :");

   sum = c1.add(c2); // complex::add(&c1, c2);
   sum.show("Addition of c1 & c2");

   return EXIT_SUCCESS;
}