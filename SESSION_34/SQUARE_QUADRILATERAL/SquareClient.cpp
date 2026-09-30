#include "Square.hpp" 

void test_square(void); 

int main(void){
    test_square(); 
    return EXIT_SUCCESS; 
}

void test_square(void){
    Square* pSquare = new Square(10); 
    double P = pSquare->perimeter(); 
    double A = pSquare->area(); 
    double D = pSquare->diagonal(); 

    printf("Size of Sqaure  = %d\n", sizeof(*pSquare));
    double temp = pSquare->diagonal();
    printf("diagonal Size : %f\n", temp);
}
