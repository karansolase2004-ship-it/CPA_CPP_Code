#include <iostream> 

class B1{
    private: 
        int n1, n2; 
    protected: 
        int x, y; 
    public: 
        int p, q; 
        B1() : n1(100), n2(200), x(300), y(400), p(500), q(600){

        }
}; 

class D1 : public B1{
    public: 
        void show(const char* msg = 0) const {
            if(msg)
                std::cout << msg << std::endl; 
            
            std::cout << "PUBLIC MEMBERS OF B1:" << std::endl; 
            std::cout << "p:" << p << " q:" << q << std::endl; 

            std::cout << "PROTECTED MEMBERS OF B1:" << std::endl; 
            std::cout << "x:" << x << " y:" << y << std::endl; 
        }
}; 

class B2{
    private: 
        int n1, n2; 
    protected: 
        int x, y; 
    public: 
        int p, q; 
        B2() : n1(100), n2(200), x(300), y(400), p(500), q(600){

        }
}; 

class D2 : protected B2{
    public: 
        void show(const char* msg = 0) const {
            if(msg)
                std::cout << msg << std::endl; 
            
            std::cout << "PUBLIC MEMBERS OF B2:" << std::endl; 
            std::cout << "p:" << p << " q:" << q << std::endl; 

            std::cout << "PROTECTED MEMBERS OF B2:" << std::endl; 
            std::cout << "x:" << x << " y:" << y << std::endl; 
        }
}; 

class B3{
    private: 
        int n1, n2; 
    protected: 
        int x, y; 
    public: 
        int p, q; 
        B3() : n1(100), n2(200), x(300), y(400), p(500), q(600){

        }
}; 

class D3 : private B3{
    public: 
        void show(const char* msg = 0) const {
            if(msg)
                std::cout << msg << std::endl; 
            
            std::cout << "PUBLIC MEMBERS OF B3:" << std::endl; 
            std::cout << "p:" << p << " q:" << q << std::endl; 

            std::cout << "PROTECTED MEMBERS OF B3:" << std::endl; 
            std::cout << "x:" << x << " y:" << y << std::endl; 
        }
}; 

void test_1(void); 
void test_2(void); 
void test_3(void); 

int main(void){
    test_1(); 
    test_2(); 
    test_3(); 

    return 0; 
}

void test_1(void){
    D1 objD1; 
    objD1.show(); 
}

void test_2(void){
    D2 objD2;
    objD2.show(); 
}

void test_3(void){
    D3 objD3; 
    objD3.show(); 
}