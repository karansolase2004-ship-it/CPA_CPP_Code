#include <iostream>

int main (void)
{
    int numerator = 10;
    int denominator = 3;

    double result_implicit = numerator / denominator;
    std::cout << "Implicit Result : " << result_implicit << std::endl;

    double result_explicit = static_cast<double>(numerator) / denominator;
    std::cout << "Explicit Result : " << result_explicit << std::endl;
}