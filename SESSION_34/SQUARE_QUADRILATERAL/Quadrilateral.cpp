#include "Quadrilateral.hpp"
#include <cstdlib> 
#include <cmath> 

Quadrilateral::Quadrilateral(double _s1, double _s2, double _s3, double _s4){
    if(_s1 <= 0.0 || _s2 <= 0.0 || _s3 <= 0.0 || _s4 <= 0.0){
        std::cerr << "Side of quadrilateral cannot be negative. exiting" 
                << std::endl; 
        exit(EXIT_FAILURE); 
    }

    if(
        (_s1 + _s2 + _s3) <= _s4 ||
        (_s1 + _s2 + _s4) <= _s3 ||
        (_s1 + _s3 + _s4) <= _s2 ||
        (_s2 + _s3 + _s4) <= _s1
    ){
        std::cerr << "Input lengths do not form valid quadrilateral. existing" 
                << std::endl; 
        exit(EXIT_FAILURE); 
    }

    s1 = _s1; 
    s2 = _s2; 
    s3 = _s3; 
    s4 = _s4; 
}

double Quadrilateral::perimeter() const { 
    return (s1 + s2 + s3 + s4); 
}

double Quadrilateral::area() const { 
    double s = perimeter() / 2; 
    return (sqrt((s-s1) * (s-s2) * (s-s3) * (s-s4))); 
}

std::ostream& operator<<(std::ostream& os, const Quadrilateral& quad_object){
    os  << "SIDES OF QUADRILATERAL:" << std::endl 
        << "length of side 1 == " << quad_object.s1 << std::endl 
        << "length of side 2 == " << quad_object.s2 << std::endl 
        << "length of side 3 == " << quad_object.s3 << std::endl 
        << "length of side 4 == " << quad_object.s4 << std::endl; 
    return os; 
}