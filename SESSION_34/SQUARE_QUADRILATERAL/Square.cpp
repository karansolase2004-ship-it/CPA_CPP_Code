#include <cmath>
#include "Square.hpp"

Square::Square(double _s) : Quadrilateral(_s, _s, _s, _s),  s(_s){
}

double Square::diagonal() const {
    return sqrt(2) * s; 
}
