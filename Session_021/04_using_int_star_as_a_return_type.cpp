#include <iostream> 
#include <cstdlib> 

typedef long long int size; 

const int SUCCESS     = 1; 
const int INDEX_ERROR = 2; 

class array{
    private: 
        int* pa; 
        size N; 

    public: 
        array(size _N) : pa(new int[_N]), N(_N){
        }

        int* operator[](size index){
            return &(pa[index]);      
        }

        ~array(){
            delete[] pa; 
        }
}; 

int main(void){
    const size N = 10; 
    size i; 
    array A(N); 
    int tmp;

    std::cout << "A[i] = val;   std::cout << A[i]" << std::endl; 

    for(size i = 0; i < N; ++i)
        *(A[i]) = (i+1) * 1000; //2

    for(i = 0; i < N; ++i)
        std::cout   << "Value at index:" 
                    << i 
                    << ":is:" 
                    << A[i]     // array::operator[](&A, i); // 1
                    << std::endl; 

    tmp = *(A[i]);

    return EXIT_SUCCESS; 
}
