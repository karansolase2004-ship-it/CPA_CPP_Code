#include <iostream> 
#include <vector> 

void test_iterators(void); 

int main(void){
    test_iterators(); 
    return 0; 
}

void test_iterators(void){
    std::vector<int> ivec { 100, 200, 300, 400, 500 }; 

    std::cout << "Forward Read/Write" << std::endl; 
     // forward r/w
    for(
        std::vector<int>::iterator iter = ivec.begin(); 
        iter != ivec.end(); 
        ++iter
    )
    {
        std::cout << "*iter = " << *iter << std::endl; 
        *iter = *iter + 5; // OK
    }
   
    std::cout << "Forward const iterator" << std::endl; 
    for(
        std::vector<int>::const_iterator iter = ivec.cbegin(); 
        iter != ivec.cend(); 
        ++iter
    ){
        // *iter = *iter + 5; // CTE 
        std::cout << "*iter = " << *iter << std::endl; 
    }

    std::cout << "Reverse Read/Write" << std::endl; 
    // reverse r/w
    for(
        std::vector<int>::reverse_iterator iter = ivec.rbegin(); 
        iter != ivec.rend(); 
        ++iter
    )
    {
        std::cout << "*iter = " << *iter << std::endl;
        *iter = *iter - 5; 
    }

    std::cout << "Reverse const iterator"  << std::endl; 
    for(
        std::vector<int>::const_reverse_iterator iter = ivec.crbegin(); 
        iter != ivec.crend(); 
        ++iter
    )
    {
        // *iter = *iter - 5; // CTE
        std::cout << "*iter = " << *iter << std::endl; 
    }
}

// Exercise : Add cosnt_iterator, reverse_iterator, reverse_const iterator 
// in the doubly circular linked list code (refer Session 31) 