#ifndef INTEGERFACTORY_H
#define INTEGERFACTORY_H

#include <QObject>

class IntegerFactory : public QObject
{
    Q_OBJECT
private:
    static bool isPrime(unsigned int N);
public:
    explicit IntegerFactory(QObject *parent = nullptr);

    void acceptIntegers();
    void broadcastShow();

signals:
    void foundEven(unsigned int);
    void foundOdd(unsigned int);
    void foundPrime(unsigned int);
    void showVectors();
};

#endif // INTEGERFACTORY_H
