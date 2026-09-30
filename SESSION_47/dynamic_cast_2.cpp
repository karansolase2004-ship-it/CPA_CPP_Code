#include <iostream> 
#include <typeinfo> 
#include <cstdlib> 

class B{
    public: 
  virtual  void f(){
            std::cout << "in B::f()" << std::endl; 
        }
}; 

class D1 : public B{
    public: 
        void f(){
            std::cout << "in D1::f()" << std::endl; 
        }

        void g1(){
            std::cout << "in D1::g1()" << std::endl; 
        } 
}; 

class D2 : public B{
    public: 
        void f(){
            std::cout << "in D2::f()" << std::endl; 
        }

        void g2(){
            std::cout << "in D2::g2()" << std::endl; 
        } 
}; 

class D3 : public B{
    public: 
        void f(){
            std::cout << "in D3::f()" << std::endl; 
        }

        void g3(){
            std::cout << "in D3::g3()" << std::endl; 
        } 
}; 

void invoke_all(B* pB); 

int main(void){
    D1 objD1; 
    D2 objD2; 
    D3 objD3; 

    invoke_all(&objD1);
    invoke_all(&objD2); 
    invoke_all(&objD3); 

    B* pb = &objD1;

    printf("%s\n",typeid(*pb).name());

    reinterpret_cast<D1*>(pb)->f(); 
    // Without using reinterpret cast and by applying virtaul qualifier 
    // Result : typeid(*pb).name() = D1

    // Using reinterpret cast  and by removing virtual qualifiers accesing the overridden function of a D1 is possible 
    // Result :  typeid(*pb).name() = B
    // due to above result typeid(*pb) will not be equal to D1 which will lead to getting condition false in invoke all function
    printf("\n");

    return 0; 
}

void invoke_all(B* pB){
    pB->f(); 

    if(typeid(*pB) == typeid(D1))
        dynamic_cast<D1*>(pB)->g1(); 
    else if(typeid(*pB) == typeid(D2))
        dynamic_cast<D2*>(pB)->g2(); 
    else if(typeid(*pB) == typeid(D3)) 
        dynamic_cast<D3*>(pB)->g3(); 
}

