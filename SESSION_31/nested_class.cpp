#include <iostream> 
#include <cstdlib> 

class A{
    private: 
        int a; 
        int b; 

    public:
        A() : a(100), b(200){}

        void show() const {
            std::cout << "a:" << a << std::endl 
                << "b:" << b << std::endl; 
        } 

        class B{
            private: 
                double x, y, z; 
            public: 
                B() : x(1.1), y(2.2), z(3.3) {} 
                
                void show() const {
                    std::cout << "x:" << x << std::endl 
                            << "y:" << y << std::endl
                            << "z:" << z << std::endl; 
                    A objA; 
                    std::cout << "a:" << objA.a  << std::endl; 
                } 

                void accessA(const A& ref){
                    std::cout << "a:" << ref.a << std::endl 
                            << "b:" << ref.b << std::endl; 
                } 
        }; 
}; 

int main(void){
    A objA; 
    A::B objB; 

    std::cout << "size(objA):" << sizeof(objA) << std::endl; 
    std::cout << "size(objB):" << sizeof(objB) << std::endl; 
    objB.show(); 

    objB.accessA(objA); 

    return 0; 
}