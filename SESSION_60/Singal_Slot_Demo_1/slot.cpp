#include "slot.h"

Slot::Slot(QObject *parent)
    : QObject{parent}
{}

void Slot::handle_test_signal(int x1, int x2)
{
    std::cout << "Slot::handle_test_signal():Start of the slot function" << std::endl;
    std::cout << "Slot::handle_test_signal():this:" << std::hex << this << std::endl;
    std::cout << "Slot::handle_test_signal():Data received from the signal emission:x1:"
              << std::dec << x1 << " x2:" << x2 << std::endl;
    std::cout << "Slot::handle_test_signal():End of slot function" << std::endl;
}
