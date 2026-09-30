#ifndef PRIMEACCUMULATOR_H
#define PRIMEACCUMULATOR_H

#include <QObject>
#include <vector>

class PrimeAccumulator : public QObject
{
    Q_OBJECT
private:
    std::vector<unsigned int> ui_vec;
public:
    explicit PrimeAccumulator(QObject *parent = nullptr);

public slots:
    void accept(unsigned int N);
    void show();
};

#endif // PRIMEACCUMULATOR_H
