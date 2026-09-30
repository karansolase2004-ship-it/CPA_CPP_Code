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
    protected: 
        int d1_prot; 
    public: 
        D1() : d1_prot(-1) {} 
        void show(const char* msg = 0) const {
            if(msg)
                std::cout << msg << std::endl; 
            
            std::cout << "PUBLIC MEMBERS OF B1:" << std::endl; 
            std::cout << "p:" << p << " q:" << q << std::endl; 

            std::cout << "PROTECTED MEMBERS OF B1:" << std::endl; 
            std::cout << "x:" << x << " y:" << y << std::endl; 
        }
}; 

class D11 : public D1{
    public: 
        void show(const char* msg = 0){
            if(msg)
                std::cout << msg << std::endl; 
            std::cout << "ACCESSING PROTECTED OF D1:" << std::endl; 
            std::cout << "d1_prot:" << d1_prot << std::endl; 
            
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
    protected: 
        int d2_prot; 
    public: 
        D2() : d2_prot(-1){}

        void show(const char* msg = 0) const {
            if(msg)
                std::cout << msg << std::endl; 
            
            std::cout << "PUBLIC MEMBERS OF B2:" << std::endl; 
            std::cout << "p:" << p << " q:" << q << std::endl; 

            std::cout << "PROTECTED MEMBERS OF B2:" << std::endl; 
            std::cout << "x:" << x << " y:" << y << std::endl; 
        }
}; 

class D22 : private D2{
    public: 
        void show(const char* msg = 0){
            if(msg)
                std::cout << msg << std::endl; 
            std::cout << "ACCESSING PROTECTED OF D2:" << std::endl; 
            std::cout << "d1_prot:" << d2_prot << std::endl; 
            
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
    protected: 
        int d3_prot; 
    public: 
        D3() : d3_prot(-1) {} 

        void show(const char* msg = 0) const {
            if(msg)
                std::cout << msg << std::endl; 
            
            std::cout << "PUBLIC MEMBERS OF B3:" << std::endl; 
            std::cout << "p:" << p << " q:" << q << std::endl; 

            std::cout << "PROTECTED MEMBERS OF B3:" << std::endl; 
            std::cout << "x:" << x << " y:" << y << std::endl; 
        }
}; 

class D33 : public D3{
    public: 
        void show(const char* msg = 0){
            if(msg)
                std::cout << msg << std::endl; 
            std::cout << "ACCESSING PROTECTED OF D3:" << std::endl; 
            std::cout << "d3_prot:" << d3_prot << std::endl; 
            
            std::cout << "TRYING TO ACCESS PUBLIC MEMBERS p, q OF B3:" << std::endl; 
            // std::cout << "p:" << p << " q:" << q << std::endl; // CTE : inaccessible

            std::cout << "TRYING TO ACCESS PROTECTED MEMBERS x, y OF B3:" << std::endl; 
            // std::cout << "x:" << x << " y:" << y << std::endl; // CTE : inaccessible
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
    objD1.show("D1::show()"); 

    D11 objD11; 
    objD11.show("D11::show()"); 

    std::cout << "test1():ACCESSING PUBLIC OF B1 from objD1" << std::endl; 
    std::cout << "p, q of B1 from objD1:" << objD1.p << " " << objD1.q << std::endl; 
    
    // std::cout << objD1.x << objD1.d1_prot << std::endl; // Due to Protected specifiers

    std::cout << "test_1():public inheritance OVER" << std::endl; 
}

void test_2(void){
    D2 objD2;
    objD2.show("D2::show()"); 

    D22 objD22; 
    objD22.show("D22:show():"); 

    std::cout << "test_2():Trying to access public B2 from objD2()" << std::endl; 
    // objD2.p; // CTE: member "B2::p" (declared at line 54) is inaccessible
    // objD2.q; // CTE: member "B2::q" (declared at line 54) is inaccessible
    std::cout << "test_2():PROTECTED inheritance OVER" << std::endl; 
}

void test_3(void){
    D3 objD3; 
    objD3.show("D3::show()"); 

    D33 objD33; 
    objD33.show("D33:show():"); 

    std::cout << "test_3():Trying to access public B3 from objD3()" << std::endl; 
    // objD3.p;  // CTE: member "B3::p"  is inaccessible
    // objD3.q;  // CTE: member "B3::p"  is inaccessible

    std::cout << "test_3():PRIVATE inheritance OVER" << std::endl; 
}