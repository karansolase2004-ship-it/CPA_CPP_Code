#include <iostream> 

class B{
    private: 
        int n1, n2; 
    public:
        B() : n1(100), n2(200){}

        void show(const char* msg = 0) const {
            if(msg)
                std::cout << msg << std::endl; 
            std::cout << "n1:" << n1 << " n2:" << n2 << std::endl; 
        } 

        void set(int _n1, int _n2){
            n1 = _n1; 
            n2 = _n2; 
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

    dynamic_cast<B*>(dynamic_cast<B1*>(&objD))->show(
        "BEFORE:showing B nested in B1 nested in D"
    ); // 100, 200

     dynamic_cast<B*>(dynamic_cast<B2*>(&objD))->show(
        "BEFORE:showing B nested in B2 nested in D"
    ); // 100, 200

    dynamic_cast<B*>(dynamic_cast<B1*>(&objD))->set(1000, 2000); 

     dynamic_cast<B*>(dynamic_cast<B1*>(&objD))->show(
        "AFTER:showing B nested in B1 nested in D"
    ); // 1000, 2000

     dynamic_cast<B*>(dynamic_cast<B2*>(&objD))->show(
        "AFTER:showing B nested in B2 nested in D"
    ); // 100, 200

    objD.show();

    return EXIT_SUCCESS; 
}