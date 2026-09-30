#include "c1.h"
#include "c2.h"
#include "c3.h"

int main(void)
{
    C1 objC1;
    C2 objC2;
    C3 objC3;

    QObject::connect(
        &objC1,
        SIGNAL(S1(int,int)),
        &objC2,
        SLOT(sltOne(int,int))
    );

    QObject::connect(
        &objC1,
        SIGNAL(S2(double,double)),
        &objC2,
        SLOT(sltTwo(double,double))
    );

    QObject::connect(
        &objC2,
        SIGNAL(S3(bool,bool)),
        &objC3,
        SLOT(sltOneForS3(bool,bool))
    );

    QObject::connect(
        &objC2,
        SIGNAL(S3(bool,bool)),
        &objC3,
        SLOT(sltTwoForS3(bool,bool))
    );

    objC1.trigger(100, 200, 1.1, 2.2);

    return 0;
}

