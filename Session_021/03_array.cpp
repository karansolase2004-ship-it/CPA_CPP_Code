#include <iostream> 
#include <cstdlib> 

typedef long long int ssize_t; 

const int SUCCESS     = 1; 
const int INDEX_ERROR = 2; 

class array{
    private: 
        int* pa; 
        ssize_t N; 

    public: 
        array(ssize_t _N) : pa(new int[_N]), N(_N){

        }

        int set(ssize_t index, int data){
            if(index < 0 || index >= N)
                return (INDEX_ERROR);
            this->pa[index] = data; 
            return (SUCCESS); 
        }

        int get(ssize_t index, int* p_data){
            if(index < 0 || index >= N)
                return (INDEX_ERROR);
            *p_data = this->pa[index]; 
            return (SUCCESS); 
        }

        ~array(){
            delete []pa; 
        }
}; 

void test_array1(void); 
void test_array2(void); 

int main(void){
    test_array1(); 
    test_array2(); 

    return EXIT_SUCCESS; 
}


void test_array1(void){
    array A(10); 
    int status;
    int num;  

    status = A.set(0, 100); // index 0, data 100, set 
    if(status == INDEX_ERROR){
        std::cout << "A.set(0,100):array index out of range" << std::endl; 
    }

    status = A.set(1, 200); // index 0, data 100, set 
    if(status == INDEX_ERROR){
        std::cout << "A.set(0,100):array index out of range" << std::endl; 
    }

    status = A.set(2, 300); // index 0, data 100, set 
    if(status == INDEX_ERROR){
        std::cout << "A.set(0,100):array index out of range" << std::endl; 
    }

    status = A.set(3, 400); // index 0, data 100, set 
    if(status == INDEX_ERROR){
        std::cout << "A.set(0,100):array index out of range" << std::endl; 
    }

    status = A.get(3, &num); // array::get(&A, 3, &num);  
    if(status == INDEX_ERROR){
        std::cout << "A.get(3, &num):array index out of range" << std::endl; 
    }

    std::cout << "Value at index 3:" << num << std::endl; 
    // printf("%d\n", A[5]);
}

void test_array2(void){
    const ssize_t N = 10; 
    int status; 
    array A(N); 

    for(ssize_t i = 0; i < N; ++i){
        status = A.set(i, (i+1) * 1000); 
        if(status == INDEX_ERROR){
            std::cout << "Index:" << i << ":out of range" << std::endl; 
        }
    }

    for(ssize_t i = 0; i < N; ++i){
        int data; 
        status = A.get(i, &data); 
        if(status == INDEX_ERROR){
            std::cout << "Index:" << i << ":out of range" << std::endl; 
        }
        else{
            std::cout << "Value at index:" << i << ":is:" << data << std::endl; 
        }
    }
}

/* 
    void test(void){
        int* p = new int(100); 
        // use p 
        delete p; 
        p = 0; 

        #----------------------

        int* pa = new int[10]; 

        delete[] pa; 
    
    }

    void test(){
        array A(10); 

        A.set(3, 100); 

        A[3] = 100;   // INSTEAD of A.set(3, 100); 

        A.get(3, &data);

        data = A[3];    // INSTEAD OF A.get(3, &num);  
    }
    
    class array

    operator[]
*/