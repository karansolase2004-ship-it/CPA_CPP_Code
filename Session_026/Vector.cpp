#include <iostream> 
#include <cstdlib> 

class VecPtr{
    private: 
        int* a; 
        size_t N; 
        unsigned ref_count; 
}; 

class Vector{
    private: 
        VecPtr* pVecPtr; 
    public: 
        Vector(); 
        Vector(size_t _N); 
        
        Vector(Vector& other_vec); 
        Vector& operator=(Vector& other_vec); 
        ~Vector(); 

        int& operator[](size_t index); 
        friend std::ostream& operator<<(std::ostream&, const Vector& vec_object); 
}; 

