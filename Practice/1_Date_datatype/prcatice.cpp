#include <iostream>

class B{
     void f(){
        printf("B::f()");
    }
};

class B1 : public B{
    void f(){
        printf("B1::f()");
    }
};

class D{
    virtual void g(){
        printf("D::g()");
    }
};

class D1 : public D{
    void g(){
        printf("D1::g()");
    }
};


int main (void){

    D* pD = new D1;
    int a;

    dynamic_cast<B*>(pD)->B::f();

    delete pD;
    pD = 0;
}