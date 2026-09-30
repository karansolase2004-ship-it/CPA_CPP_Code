#ifndef C3_H
#define C3_H

#include <QObject>

class C3 : public QObject
{
    Q_OBJECT
public:
    explicit C3(QObject *parent = nullptr);

signals:
public slots:
    void sltOneForS3(bool b1, bool b2);
    void sltTwoForS3(bool b1, bool b2);
};

#endif // C3_H
