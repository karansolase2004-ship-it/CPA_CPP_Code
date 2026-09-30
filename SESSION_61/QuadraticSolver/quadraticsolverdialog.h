#ifndef QUADRATICSOLVERDIALOG_H
#define QUADRATICSOLVERDIALOG_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDialog>

class QuadraticSolverDialog : public QDialog
{
    Q_OBJECT
public:
    QuadraticSolverDialog(QWidget* parent = nullptr);
};

#endif // QUADRATICSOLVERDIALOG_H
