#include "signal.h"
#include <iostream>

Signal::Signal() : QObject() {}

void Signal::trigger(int n1, int n2){
    std::cout << "Signal::trigger():Emitting test signal with input params n1 and n2" << std::endl;
    std::cout << "Signal::trigger():Emitting signal object using an object with addr:" << std::hex << this << std::endl;
    emit test_signal(n1, n2);
    std::cout << "Signal::trigger():Done emitting the signal" << std::endl;
}
