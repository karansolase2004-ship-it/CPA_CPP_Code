#include <iostream>
#include "c3.h"

C3::C3(QObject *parent)
    : QObject{parent}
{}

void C3::sltOneForS3(bool b1, bool b2)
{
    std::cout << "C3::sltOneForS3():Entered" << std::endl;
    std::cout << "C3::sltOneForS3():Input data:Conjunction:" << (b1 && b2)
              << " Disjunction:" << (b1 || b2) << std::endl;
    std::cout << "C3::sltOneForS3():Leaving" << std::endl;
}

void C3::sltTwoForS3(bool b1, bool b2)
{
    std::cout << "C3::sltTwoForS3():Entered" << std::endl;
    std::cout << "C3::sltTwoForS3():Input data:Conjunction:" << (b1 && b2)
              << " Disjunction:" << (b1 || b2) << std::endl;
    std::cout << "C3::sltTwoForS3():Leaving" << std::endl;
}
