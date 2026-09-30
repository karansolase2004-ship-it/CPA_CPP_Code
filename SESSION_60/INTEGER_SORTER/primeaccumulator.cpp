#include "primeaccumulator.h"
#include <iostream>

PrimeAccumulator::PrimeAccumulator(QObject *parent)
    : QObject{parent}
{}

void PrimeAccumulator::accept(unsigned int N){
    ui_vec.push_back(N);
}

void PrimeAccumulator::show(){
    std::cout << "Showing vector of Prime numbers:" << std::endl;
    for(std::vector<unsigned int>::size_type i = 0; i < ui_vec.size(); ++i)
        std::cout << "Even Number " << i << ":" << ui_vec[i] << std::endl;
}
