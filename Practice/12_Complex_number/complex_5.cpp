#include <cstdio> 
#include <cstdlib> 

class Complex{
    private: 
        double re, im; 

    public: 
        Complex() : re(0.0), im(0.0){

        }

        Complex(double _re, double _im) : re(_re), im(_im){

        }
 
        // MEMORY MANAGEMENT WISE CORRECT 
        // THREAD SAFE 
        // BUT SYNTAXWISE AWKWARD 
        // Complex* ptr = c1 + c2; 
        // WILL PREVENT OBJECT CHAINING 
        // c1 + c2 + c3;
        // will not be possible: because type(c1+c2)==Complex* (as per our implementation)
        // Complex* + Complex (IS NOT ALLOWED)

        Complex* add(const Complex& second_number) const {
            Complex* pSum = new Complex; 
            
            pSum->re = this->re + second_number.re; 
            pSum->im = this->im + second_number.im; 

            return (pSum); 
        }

        void show(const char* msg){
            if(msg)
                puts(msg); 

            printf("(%.2lf)+i(%.2lf)\n", this->re, this->im); 
        }
}; 


int main(void){
    Complex c1(1.1, 2.2); 
    Complex c2(3.2, 4.1);  
    Complex c3(3.2, 4.1);  
 
    c1.show("Showing c1:"); 
    c2.show("Showing c2:"); 

    Complex* pSummation = c1.add(c2).add(c3); 
    // c1.add(c2) हा call Complex* return करतो आणि complex*.add(c3) करता येणार नाही कारण complex* हा address आहे आणि आपल्याला object पाहिजे 
    // complex* हा address derefence करून add(c3) अस करता येईल परंतु ते काहीस असा दिसेल : (c1.add(c2))->add(c3); or (*(c1.add(c2))).add(c3); आणि अजून object add करायचे म्हणला तर SYNTAXWISE ते AWKWARD होईल म्हणून object chaining possible नाही.

    delete pSummation; 
    pSummation = 0; 

    return EXIT_SUCCESS; 
}
