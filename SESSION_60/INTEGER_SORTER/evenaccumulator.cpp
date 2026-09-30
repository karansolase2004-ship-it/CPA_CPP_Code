#include "evenaccumulator.h"
#include <iostream>

EvenAccumulator::EvenAccumulator(QObject *parent)
    : QObject{parent}
{}

void EvenAccumulator::accept(unsigned int N){
    ui_vec.push_back(N);
}

void EvenAccumulator::show(){
    std::cout << "Showing vector of even numbers:" << std::endl;
    for(std::vector<unsigned int>::size_type i = 0; i < ui_vec.size(); ++i)
        std::cout << "Even Number " << i << ":" << ui_vec[i] << std::endl;
}
