/********************************************************************************
** Form generated from reading UI file 'affichages.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AFFICHAGES_H
#define UI_AFFICHAGES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Affichages
{
public:
    QTableView *LesVues;
    QPushButton *pushButton;

    void setupUi(QWidget *Affichages)
    {
        if (Affichages->objectName().isEmpty())
            Affichages->setObjectName("Affichages");
        Affichages->resize(848, 452);
        LesVues = new QTableView(Affichages);
        LesVues->setObjectName("LesVues");
        LesVues->setGeometry(QRect(70, 20, 691, 341));
        pushButton = new QPushButton(Affichages);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(300, 390, 191, 29));

        retranslateUi(Affichages);

        QMetaObject::connectSlotsByName(Affichages);
    } // setupUi

    void retranslateUi(QWidget *Affichages)
    {
        Affichages->setWindowTitle(QCoreApplication::translate("Affichages", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("Affichages", "Retourner", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Affichages: public Ui_Affichages {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AFFICHAGES_H
