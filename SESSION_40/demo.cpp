#include <iostream> 

template <typename T1, typename T2, typename T3, int N>
T3 test(double x, double y){
    T1 a; 
    T2 b; 
    double rs = x*N + y*N; 
    std::cout << "type(a):" << typeid(a).name() << std::endl; 
    std::cout << "type(b):" << typeid(b).name() << std::endl; 
    std::cout << "type(return type):" << typeid(T3).name() << std::endl; 
    std::cout << "type(N):" << typeid(N).name() << std::endl; 

    std::cout << "Temp Value : " << temp << std::endl;

    T3 v; 

    return v;
}

int main(void){
    int ret_val; 

    ret_val = test<float, double, int, 100>(1.1, 2.2); 

    return 0; 
}

