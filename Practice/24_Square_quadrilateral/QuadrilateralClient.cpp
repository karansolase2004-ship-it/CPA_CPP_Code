#include <iostream>
#include "Quadrilateral.hpp"

int main(void){
    Quadrilateral* pquad = new Quadrilateral(2.3, 5.6, 9.4, 59.7);

    std::cout << "perimeter () : " << pquad->perimeter() << std::endl;

    std::cout << "Area () : " << pquad->area() << std::endl;

    std::cout << *pquad << std::endl;

    delete pquad;
    pquad = 0;
}