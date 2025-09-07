/********************************************************************************
** Form generated from reading UI file 'resultat.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESULTAT_H
#define UI_RESULTAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_resultat
{
public:
    QTableView *TableResultat;
    QPushButton *pushButton;

    void setupUi(QWidget *resultat)
    {
        if (resultat->objectName().isEmpty())
            resultat->setObjectName("resultat");
        resultat->resize(1071, 507);
        TableResultat = new QTableView(resultat);
        TableResultat->setObjectName("TableResultat");
        TableResultat->setGeometry(QRect(20, 30, 1021, 471));
        pushButton = new QPushButton(resultat);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(350, 0, 93, 29));

        retranslateUi(resultat);

        QMetaObject::connectSlotsByName(resultat);
    } // setupUi

    void retranslateUi(QWidget *resultat)
    {
        resultat->setWindowTitle(QCoreApplication::translate("resultat", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("resultat", "Charger", nullptr));
    } // retranslateUi

};

namespace Ui {
    class resultat: public Ui_resultat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESULTAT_H
