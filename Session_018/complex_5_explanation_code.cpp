#include <cstdio>
#include <cstdlib>

class complex{
    private :
        double re, im;

    public :
      complex() :re(0.0), im(0.0){

      }
      complex(double _re, double _im) : re(_re), im(_im) {

      }

      complex* add(const complex& second_number) const{
        complex* psum = new complex;

        psum->re = this->re + second_number.re;
        psum->im = this->im + second_number.im;

        return (psum);
      }

      void show(const char* msg){
        if(msg)
           puts(msg);

        printf("(%.2lf) + i(%.2lf)\n", this->re, this->im);
      }
};

int main (void){
    complex c1(1.1, 2.2);
    complex c2(3.2, 4.1);
    complex c3(3.2, 4.1);

    complex* psummation = (c1.add(c2))->add(c3); // (*(c1.add(c2))).add(c3);  

    delete psummation;
    psummation = 0;

    return EXIT_SUCCESS;
}


