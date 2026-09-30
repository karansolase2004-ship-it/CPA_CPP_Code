#include <cstdio>
#include <cstdlib>

class complex{
    private :
       double re, im;

    public : 
       complex() : re(0.0), im(0.0) {

       }

       complex(double _re, double _im) : re(_re), im(_im) {

       }

       void show(const char* msg) const {
        if (msg) 
           puts(msg);

        printf("(%.2lf) + i(%.2lf)\n", re, im);
       }

       complex& add(const complex& second_number) const{
        static complex summation_object;
         
        summation_object.re = this->re + second_number.re;
        summation_object.im = this->im + second_number.im;

        return summation_object;
       }
};

int main (void){
    complex c1(1.1, 2.2);
    complex c2(3.3, 4.4);
    complex c3(5.5, 6.6);
    complex c4(7.7, 8.8);

    c1.show("c1 :");
    c2.show("c2 :");
    c3.show("c3 :");
    c4.show("c4 :");

    complex& refsum1 = c1.add(c2);
    refsum1.show("Showing refsum1: addition of c1 and c2");

    complex& refsum2 = c3.add(c4);
    refsum2.show("Showing refsum2 : addition of c3 and c4");

    refsum1.show("Showing refsum1 : addition of ?? (SURPRISE! SURPRISE!!)");

    printf("&refsum1 = %llu, &refsum2 = %llu\n", 
                (unsigned long long)&refsum1,
                (unsigned long long)&refsum2);

    return 0;
}