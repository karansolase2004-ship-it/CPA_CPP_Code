#include <iostream>
#include "c2.h"

C2::C2(QObject *parent)
    : QObject{parent}
{}

void C2::sltOne(int data1, int data2)
{
    std::cout << "C2::sltOne Entered:" << std::endl;
    std::cout << "C2::sltOne:data received from signal:data1"
              << data1 << " data2:" << data2 << std::endl;
    std::cout << "C2::sltOne:Emitting Signal S3 with false, true" << std::endl;
    emit S3(false, true);
    std::cout << "C2::sltOne:Leaving" << std::endl;
}

void C2::sltTwo(double dData1, double dData2)
{
    std::cout << "C2::sltTwo Entered:" << std::endl;
    std::cout << "C2::sltTwo:data received from signal:data1"
              << dData1 << " data2:" << dData2 << std::endl;
    std::cout << "C2::sltTwo:Emitting Signal S3 with true, true" << std::endl;
    emit S3(false, false);
    std::cout << "C2::sltTwo:Leaving" << std::endl;
}
