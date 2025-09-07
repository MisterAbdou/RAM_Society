/********************************************************************************
** Form generated from reading UI file 'supprimer.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPPRIMER_H
#define UI_SUPPRIMER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Supprimer
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *cleSupprimer;
    QPushButton *pushButton;

    void setupUi(QWidget *Supprimer)
    {
        if (Supprimer->objectName().isEmpty())
            Supprimer->setObjectName("Supprimer");
        Supprimer->resize(1165, 494);
        horizontalLayoutWidget = new QWidget(Supprimer);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(330, 110, 631, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        cleSupprimer = new QLineEdit(horizontalLayoutWidget);
        cleSupprimer->setObjectName("cleSupprimer");

        horizontalLayout->addWidget(cleSupprimer);

        pushButton = new QPushButton(Supprimer);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(520, 230, 171, 29));

        retranslateUi(Supprimer);

        QMetaObject::connectSlotsByName(Supprimer);
    } // setupUi

    void retranslateUi(QWidget *Supprimer)
    {
        Supprimer->setWindowTitle(QCoreApplication::translate("Supprimer", "Form", nullptr));
        label->setText(QCoreApplication::translate("Supprimer", "Cle", nullptr));
        pushButton->setText(QCoreApplication::translate("Supprimer", "valider", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Supprimer: public Ui_Supprimer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPPRIMER_H
