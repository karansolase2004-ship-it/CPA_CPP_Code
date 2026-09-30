#include "oddaccumulator.h"
#include <iostream>

OddAccumulator::OddAccumulator(QObject *parent)
    : QObject{parent}
{}

void OddAccumulator::accept(unsigned int N){
    ui_vec.push_back(N);
}

void OddAccumulator::show(){
    std::cout << "Showing vector of odd numbers:" << std::endl;
    for(std::vector<unsigned int>::size_type i = 0; i < ui_vec.size(); ++i)
        std::cout << "Even Number " << i << ":" << ui_vec[i] << std::endl;
}
