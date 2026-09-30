#include <cmath>
#include "Square.hpp"

Square::Square(double _s) : Quadrilateral(_s, _s, _s, _s),  s(_s){
}

double Square::area() const {
    std::cout << "In Square::area()" << std::endl; 
    return s * s;  
}

double Square::diagonal() const {
    std::cout << "In Square::diagonal()" << std::endl;
    return sqrt(2) * s; 
}