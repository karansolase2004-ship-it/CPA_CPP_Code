#include "integerfactory.h"
#include "evenaccumulator.h"
#include "oddaccumulator.h"
#include "primeaccumulator.h"

int main(void){
    IntegerFactory int_factory;
    EvenAccumulator acc_even;
    OddAccumulator acc_odd;
    PrimeAccumulator acc_prime;

    QObject::connect(
        &int_factory,
        SIGNAL(foundEven(uint)),
        &acc_even,
        SLOT(accept(uint))
        );

    QObject::connect(
        &int_factory,
        SIGNAL(foundOdd(uint)),
        &acc_odd,
        SLOT(accept(uint))
        );

    QObject::connect(
        &int_factory,
        SIGNAL(foundPrime(uint)),
        &acc_prime,
        SLOT(accept(uint))
        );

    QObject::connect(
        &int_factory,
        SIGNAL(showVectors()),
        &acc_even,
        SLOT(show())
        );

    QObject::connect(
        &int_factory,
        SIGNAL(showVectors()),
        &acc_odd,
        SLOT(show())
        );

    QObject::connect(
        &int_factory,
        SIGNAL(showVectors()),
        &acc_prime,
        SLOT(show())
        );

    int_factory.acceptIntegers();
    int_factory.broadcastShow();

    return EXIT_SUCCESS;
}
