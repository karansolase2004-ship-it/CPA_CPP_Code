#include "quadraticsolverdialog.h"

QuadraticSolverDialog::QuadraticSolverDialog(QWidget* parent) : QDialog(parent)
{
    QLabel* pLabel_1 = new QLabel(tr("Enter CF of x^2:"));
    QLabel* pLabel_2 = new QLabel(tr("Enter CF of x:"));
    QLabel* pLabel_3 = new QLabel(tr("Enter the constant:"));

    QLineEdit* pText_1 = new QLineEdit;
    QLineEdit* pText_2 = new QLineEdit;
    QLineEdit* pText_3 = new QLineEdit;

    pLabel_1->setBuddy(pText_1);
    pLabel_2->setBuddy(pText_2);
    pLabel_3->setBuddy(pText_3);

    QPushButton* pSolveButton = new QPushButton(tr("Solve!"));
    QPushButton* pCloseButton = new QPushButton(tr("Close"));

    connect(pSolveButton,
            SIGNAL(clicked()),
            this,
            SLOT(close()));

    connect(pCloseButton,
            SIGNAL(clicked()),
            this,
            SLOT(close()));

    QHBoxLayout* entry_1 = new QHBoxLayout;
    entry_1->addWidget(pLabel_1);
    entry_1->addWidget(pText_1);

    QHBoxLayout* entry_2 = new QHBoxLayout;
    entry_2->addWidget(pLabel_2);
    entry_2->addWidget(pText_2);

    QHBoxLayout* entry_3 = new QHBoxLayout;
    entry_3->addWidget(pLabel_3);
    entry_3->addWidget(pText_3);

    QVBoxLayout* leftLayout = new QVBoxLayout;
    leftLayout->addLayout(entry_1);
    leftLayout->addLayout(entry_2);
    leftLayout->addLayout(entry_3);

    QVBoxLayout* rightLayOut = new QVBoxLayout;
    rightLayOut->addWidget(pSolveButton);
    rightLayOut->addWidget(pCloseButton);
    rightLayOut->addStretch();

    QHBoxLayout* mainLayOut = new QHBoxLayout;
    mainLayOut->addLayout(leftLayout);
    mainLayOut->addLayout(rightLayOut);

    this->setLayout(mainLayOut);
    this->setWindowTitle("Quadratic Solver");
    this->setFixedHeight(this->sizeHint().height());
}
