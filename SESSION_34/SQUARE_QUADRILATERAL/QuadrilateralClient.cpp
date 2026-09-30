#include <iostream> 
#include "Quadrilateral.hpp"

void test_quadrilateral(void); 

int main(void){
    test_quadrilateral(); 
    return 0;  
}

void test_quadrilateral(void){
    Quadrilateral* pQuad = new Quadrilateral(4.2, 3.5, 2.8, 1.8); 

    double perimeter = pQuad->perimeter(); 
    std::cout << "Perimeter:" << perimeter << std::endl; 

    double area = pQuad->area(); 
    std::cout << "Area:" << area << std::endl; 

    std::cout << "pQuad:" << std::endl << *pQuad; 

    delete pQuad; 
    pQuad = 0; 
}