#ifndef C2_H
#define C2_H

#include <QObject>

class C2 : public QObject
{
    Q_OBJECT
public:
    explicit C2(QObject *parent = nullptr);

signals:
    void S3(bool,bool);
public slots:
    void sltOne(int data1, int data2);
    void sltTwo(double dData1, double dData2);
};

#endif // C2_H
