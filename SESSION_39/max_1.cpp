#include <iostream> 

int max(const int& a, const int& b); 
float max(const float& a, const float& b); 

int main(void){
    int a = 100, b = 200; 
    int m; 

    m = max(a, b); 
    m = max(300, b); 
    m = max(a, 300); 
    m = max(300, 600); 

    std::cout << "m:" << m << std::endl; 

    return 0; 
}

int max(const int& a, const int& b){
    if(a > b)
        return a; 
    return b;
}

float max(const float& a, const float& b){
    if(a > b)
        return a; 
    return b;
}

/*

T max(T const & a, T const& b){
     if(a > b)
        return a; 
    return b;
}

*/

