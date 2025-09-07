/********************************************************************************
** Form generated from reading UI file 'rechercher.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECHERCHER_H
#define UI_RECHERCHER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Rechercher
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *rechercher;
    QLabel *label_2;
    QPushButton *boutonrechercher;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *labelStanding;
    QLabel *labelType;
    QLabel *labelChambres;
    QLabel *labelToilettes;
    QLabel *labelDescription;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;

    void setupUi(QWidget *Rechercher)
    {
        if (Rechercher->objectName().isEmpty())
            Rechercher->setObjectName("Rechercher");
        Rechercher->resize(1035, 624);
        horizontalLayoutWidget = new QWidget(Rechercher);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(140, 80, 681, 91));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        rechercher = new QLineEdit(horizontalLayoutWidget);
        rechercher->setObjectName("rechercher");

        horizontalLayout->addWidget(rechercher);

        label_2 = new QLabel(Rechercher);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(360, 30, 221, 20));
        boutonrechercher = new QPushButton(Rechercher);
        boutonrechercher->setObjectName("boutonrechercher");
        boutonrechercher->setGeometry(QRect(390, 180, 151, 29));
        gridLayoutWidget = new QWidget(Rechercher);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(130, 270, 761, 141));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        labelStanding = new QLabel(gridLayoutWidget);
        labelStanding->setObjectName("labelStanding");

        gridLayout->addWidget(labelStanding, 3, 0, 1, 1);

        labelType = new QLabel(gridLayoutWidget);
        labelType->setObjectName("labelType");

        gridLayout->addWidget(labelType, 2, 0, 1, 1);

        labelChambres = new QLabel(gridLayoutWidget);
        labelChambres->setObjectName("labelChambres");

        gridLayout->addWidget(labelChambres, 4, 0, 1, 1);

        labelToilettes = new QLabel(gridLayoutWidget);
        labelToilettes->setObjectName("labelToilettes");

        gridLayout->addWidget(labelToilettes, 5, 0, 1, 1);

        labelDescription = new QLabel(gridLayoutWidget);
        labelDescription->setObjectName("labelDescription");

        gridLayout->addWidget(labelDescription, 6, 0, 1, 1);

        horizontalLayoutWidget_2 = new QWidget(Rechercher);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(130, 430, 701, 131));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(horizontalLayoutWidget_2);
        label_3->setObjectName("label_3");

        horizontalLayout_2->addWidget(label_3);

        label_4 = new QLabel(horizontalLayoutWidget_2);
        label_4->setObjectName("label_4");

        horizontalLayout_2->addWidget(label_4);

        label_5 = new QLabel(horizontalLayoutWidget_2);
        label_5->setObjectName("label_5");

        horizontalLayout_2->addWidget(label_5);

        label_6 = new QLabel(horizontalLayoutWidget_2);
        label_6->setObjectName("label_6");

        horizontalLayout_2->addWidget(label_6);

        label_7 = new QLabel(horizontalLayoutWidget_2);
        label_7->setObjectName("label_7");

        horizontalLayout_2->addWidget(label_7);

        label_8 = new QLabel(horizontalLayoutWidget_2);
        label_8->setObjectName("label_8");

        horizontalLayout_2->addWidget(label_8);


        retranslateUi(Rechercher);

        QMetaObject::connectSlotsByName(Rechercher);
    } // setupUi

    void retranslateUi(QWidget *Rechercher)
    {
        Rechercher->setWindowTitle(QCoreApplication::translate("Rechercher", "Form", nullptr));
        label->setText(QCoreApplication::translate("Rechercher", "ENTRER LA CLE DE LA MAISON :", nullptr));
        label_2->setText(QCoreApplication::translate("Rechercher", "Rechercher une maison par la cle", nullptr));
        boutonrechercher->setText(QCoreApplication::translate("Rechercher", "Rechercher", nullptr));
        labelStanding->setText(QString());
        labelType->setText(QString());
        labelChambres->setText(QString());
        labelToilettes->setText(QString());
        labelDescription->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
        label_6->setText(QString());
        label_7->setText(QString());
        label_8->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Rechercher: public Ui_Rechercher {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECHERCHER_H
