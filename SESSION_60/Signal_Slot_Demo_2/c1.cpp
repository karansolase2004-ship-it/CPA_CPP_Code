#include "c1.h"

C1::C1(QObject *parent)
    : QObject{parent}
{}

void C1::trigger(int iDataOne, int iDataTwo, double dDataOne, double dDataTwo)
{
    emit S1(iDataOne, iDataTwo);
    emit S2(dDataOne, dDataTwo);
}
