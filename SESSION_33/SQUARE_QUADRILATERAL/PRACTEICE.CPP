#include "Quadrilateral.hpp"
#include <cstdlib>
#include <cmath>

Quadrilateral::Quadrilateral(double _s1, double _s2, double _s3, double _s4)
{
    if(_s1 <= 0.0 || _s2<= 0.0 || _s3 <= 0.0 || _s4 <= 0.0){
        std::cout << "Side of quadrilateral cannot be negative. exiting" << std::endl;
    }
}