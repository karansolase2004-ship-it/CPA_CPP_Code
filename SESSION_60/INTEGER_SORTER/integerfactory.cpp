#include <iostream>
#include "integerfactory.h"

IntegerFactory::IntegerFactory(QObject *parent)
    : QObject{parent}
{}

void IntegerFactory::acceptIntegers(){
    unsigned int N;
    unsigned int ind = 0;

    while(ind < 25){
        N = rand() % 1000;

        if(N % 2 == 0)
            emit foundEven(N);
        else
            emit foundOdd(N);

        if(IntegerFactory::isPrime(N) == true)
            emit foundPrime(N);

        ind += 1;
    }
}

void IntegerFactory::broadcastShow(){
    emit showVectors();
}

bool IntegerFactory::isPrime(unsigned int N){
    bool is_prime = true;

    if(N == 1)
        return false;

    if(N == 2)
        return true;

    for(unsigned int i = 2; i < N; ++i)
        if(N % i == 0){
            is_prime = false;
            break;
        }

    return is_prime;
}
