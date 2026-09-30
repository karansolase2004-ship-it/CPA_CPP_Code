#ifndef ODDACCUMULATOR_H
#define ODDACCUMULATOR_H

#include <QObject>
#include <vector>

class OddAccumulator : public QObject
{
    Q_OBJECT
private:
    std::vector<unsigned int> ui_vec;
public:
    explicit OddAccumulator(QObject *parent = nullptr);

public slots:
    void accept(unsigned int);
    void show();
};

#endif // ODDACCUMULATOR_H
