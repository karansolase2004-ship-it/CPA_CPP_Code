#include <cstdio> 

class Base{
    public: 
        // INHERITOR 
        void f(){
            puts("In Base::f()"); 
        }

        // OVERRIDDEN FUNCTION 
        void g(){
            puts("In Base::g()"); 
        }
}; 

class Derived : public Base{
    public: 
        // OVERRIDDEN FUNCTION  : REPLACEMENT 
        void g(){
            puts("In Derived::g()"); 
        }

        // DERIVED SPECIFIC 
        void h(){
            puts("In Derived::h()"); 
        }
}; 

void test_Base(void); 
void test(void); 

int main(void){
    test_Base(); 
    test(); 
    return 0; 
}

void test_Base(void){
    Base* pB1 = new Base; 
    
    pB1->f(); 
    pB1->g(); 

    delete pB1; 
    pB1 = 0; 
}

void test(void){
    Derived D; 
    Derived* pD = &D; 
    Base* pB = &D; 

    pD->f();    // B::f() 
    pD->h();    // D::h() 
    pD->g();    // D::g()

    pB->g();    // B::g()   
    pB->f();    // B::f() 
    // pB->h();    // COMPILE TIME ERROR  
}