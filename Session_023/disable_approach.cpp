#include <iostream> 
#include <stdexcept> 

class HasPtr{
    private: 
        int n; 
        int* ptr; 

    public: 
        HasPtr(int _n, int _val) : n(_n), ptr(new int(_val)){
            
        }

        HasPtr(const HasPtr& rhs){
            throw std::runtime_error("Cannot initialize new object of HasPtr by existing object")        ; 
        }

        HasPtr& operator=(const HasPtr& rhs){
            throw std::runtime_error("Cannot assign existing object of HasPtr by another existing object"); 
        }

        ~HasPtr(){
            delete ptr; 
        }
}; 

int main(void){
    HasPtr hp1(10, 100); 
    HasPtr hp2(20, 200); 

    try{
        hp1 = hp2;
    }
    catch(std::runtime_error& e){
        std::cout << e.what() << std::endl; 
    }

    try{
        HasPtr hp3(hp1); 
    }
    catch(std::runtime_error& e){
        std::cout << e.what() << std::endl; 
    }

    std::cout << "application terminates successfully" << std::endl; 

    return EXIT_SUCCESS; 
}

