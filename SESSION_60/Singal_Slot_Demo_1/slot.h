#ifndef SLOT_H
#define SLOT_H

#include <iostream>
#include <QObject>

class Slot : public QObject
{
    Q_OBJECT
public:
    explicit Slot(QObject *parent = nullptr);

signals:

public slots:
    void handle_test_signal(int x1, int x2);

};

#endif // SLOT_H
