#ifndef EVENACCUMULATOR_H
#define EVENACCUMULATOR_H

#include <QObject>
#include <vector>

class EvenAccumulator : public QObject
{
    Q_OBJECT
private:
    std::vector<unsigned int> ui_vec;
public:
    explicit EvenAccumulator(QObject *parent = nullptr);

public slots:
    void accept(unsigned int N);
    void show();
};

#endif // EVENACCUMULATOR_H
