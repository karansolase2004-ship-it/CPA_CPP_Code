#include "Square.hpp" 
#include <typeinfo> 

void test_square(void); 
void test_virtual(void); 

int main(void){
    test_square(); 
    test_virtual(); 
    return EXIT_SUCCESS; 
}

void test_square(void){
    Square* pSquare = new Square(10); 
    double P = pSquare->perimeter(); 
    double A = pSquare->area(); 
    double D = pSquare->diagonal(); 
    double C = pSquare->Quadrilateral::area();

    std::cout << "1" << std::endl;

    delete pSquare;
    pSquare = 0;
}

void test_virtual(void){
    Square S(10); 
    Quadrilateral* pQuadrilateral = 0; 
    Square* pSquare = 0; 

    pQuadrilateral = &S;    // Square 'is-a' Quadrilateral
    double P = pQuadrilateral->perimeter();     // Quadrilateral::perimeter(pQuadrilateral); 
    double A = pQuadrilateral->area();          // Square::area(pQuadrilateral); 
    A = pQuadrilateral->Quadrilateral::area();  // Quadrilateral::area(pQuadrilateral);

    std::cout << "2" << std::endl; 
    
    if(typeid(*pQuadrilateral) == typeid(Square))
        double D = dynamic_cast<Square*>(pQuadrilateral)->diagonal(); 

    // std::cout << pquad->Square::diagonal(); // CTE 

    std::cout << "3" << std::endl;

    pSquare = &S; 
    P = pSquare->diagonal(); 
    P = pSquare->perimeter();           // Quadrilateral::perimeter(pSquare);  
    A = pSquare->area();                // Square::area(pSquare); 
    A = pSquare->Quadrilateral::area(); // Quadrilateral::area(pSquare);
}