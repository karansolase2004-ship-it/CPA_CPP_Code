#include <iostream> 

class B{
    private: 
        int n1, n2; 
    public:
        void show() const {
            std::cout << "n1:" << n1 << " n2:" << n2 << std::endl; 
        } 
}; 

class B1 : virtual public B{
    private: 
        double d1, d2; 
};  

class B2 : virtual public B{
    private: 
        int a[4]; 
}; 

class D : public B1, public B2{
    private: 
        int b[8]; 
}; 

int main(void){
    D objD; 

    std::cout << "sizeof(objD):" << sizeof(objD) << std::endl; 
    // objD.show(); 

    return EXIT_SUCCESS; 
}