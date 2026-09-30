#include <vector> 
#include <iostream> 

void test_vector(void); 
void test_vector_initialisation(void); 

int main(void){
    test_vector(); 
    test_vector_initialisation();
    return 0; 
}

void test_vector(void){
    std::vector<int> ivec; 
    std::vector<float> fvec; 

    ivec.push_back(10); 
    ivec.push_back(20); 
    ivec.push_back(30); 

    fvec.push_back(1.1); 
    fvec.push_back(2.2); 
    fvec.push_back(3.3); 

    int m; 
    m = ivec[0];  // will give access to 10 
    m = ivec[1];  // will give access to 20 
    m = ivec[2];  // will give access to 30 
    
    // m = ivec[3];  // breaching the bound. result: undefined 

    std::cout << "sizeof(ivec) : " << sizeof(ivec) << std::endl;

    std::cout << "Showing ivec:" << std::endl; 
    for(
        std::vector<int>::size_type i = 0; 
        i != ivec.size(); 
        ++i
    )
        std::cout << "ivec[" << i << "]:" << ivec[i] << std::endl; 

    std::cout << "Showving fvec:" << std::endl; 
    for(
        std::vector<float>::size_type i = 0; 
        i != fvec.size(); 
        ++i
    )    
        std::cout << "fvec[" << i << "]:" << fvec[i] << std::endl; 

    for(
        std::vector<int>::size_type i = 0; 
        i != ivec.size(); 
        ++i
    )
        ivec[i] = (i + 1) * 100; 


    std::cout << "Showing modified ivec:" << std::endl; 
    for(
        std::vector<int>::size_type i = 0; 
        i != ivec.size(); 
        ++i
    )
        std::cout << "ivec[" << i << "]:" << ivec[i] << std::endl; 
}

void test_vector_initialisation(void){
    std::vector<int> ivec1; // empty vector
    std::vector<int> ivec2(5); // new vector having preallocation for 5 instances of int 
    std::vector<int> ivec3(5, 100); // new vector having preallocation for 5 instances of int 
                                    // each initialised to 100 
    std::vector<int> ivec4(ivec2);  // initialise new vector from existing vector  

    // C11 extension (initialiser list)
    std::vector<int> ivec5{100, 200, 300, 400, 500}; 

    std::cout << "Showing ivec3 : " << std::endl; 

    for(
        std::vector<int>::size_type i = 0; 
        i != ivec3.size(); 
        ++i
    )
        std::cout << "ivec3[" << i << "]:" << ivec3[i] << std::endl; 

}