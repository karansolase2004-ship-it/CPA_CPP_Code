#ifndef SIGNAL_H
#define SIGNAL_H

#include <QObject>

class Signal : public QObject
{
    Q_OBJECT
public:
    Signal();
signals:
    void test_signal(int data1, int data2);
public:
    void trigger(int n1, int n2);
};

#endif // SIGNAL_H
