#ifndef C1_H
#define C1_H

#include <QObject>

class C1 : public QObject
{
    Q_OBJECT
public:
    explicit C1(QObject *parent = nullptr);

signals:
    void S1(int,int);
    void S2(double,double);
public:
    void trigger(int iDataOne, int iDataTwo, double dDataOne, double dDataTwo);
};

#endif // C1_H
