#include <iostream> 

// Definition of funtion template 
// test is a FUNCTION   TEMPLATE having N as a non-type parameter 
// in template parameter list, x & y as paraeters in formal parameter 
// list and void as its return type 
// N is a non-type parameter of type int 
// type(x) == float, type(y) == float 
template <int N> 
void test(float x, float y){
    double result = x * N + y * N; 
    std::cout << "Result:" << result << std::endl; 
}

int main(void){
    // Function template use 
    test<10>(1.1, 2.2); 
    test<20>(3.3, 4.4); 

    return 0; 
}

// TEMPLATE INSTANTIATION 
// INSTANTIATION -> TO MAKE AN INSTANCE. 

// DATA TYPE -> VARIABLE 
// class template -> instance -> class -> instance -> object  
// vector<int> v; 
// vector<string> 
// vector<float>
// X y; 


 