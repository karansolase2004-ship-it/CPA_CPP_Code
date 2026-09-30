#include <iostream>
#include <QObject>
#include <QApplication>
#include "signal.h"
#include "slot.h"

int main(void)
{
    std::cout << "main:Start application" << std::endl;

    Signal S1;
    Signal S2;
    Slot SLT1;

    std::cout << "main:address of signal object S1:" << std::hex << &S1 << std::endl;
    std::cout << "main:address of signal object S2:" << std::hex << &S2 << std::endl;
    std::cout << "main:address of slot object SLT1:" << std::hex << &SLT1 << std::endl;

    QObject::connect(
        &S1,
        SIGNAL(test_signal(int,int)),
        &SLT1,
        SLOT(handle_test_signal(int,int))
    );

    S1.trigger(100, 200);
    S2.trigger(500, 600);

    std::cout << "main:end application" << std::endl;

    return 0;
}
