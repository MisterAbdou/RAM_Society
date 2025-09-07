/********************************************************************************
** Form generated from reading UI file 'inserer.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERER_H
#define UI_INSERER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_inserer
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *cle;
    QLabel *label_2;
    QLineEdit *Type;
    QLabel *label_3;
    QLineEdit *standing;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QTextEdit *description;
    QSpinBox *nb_chambres;
    QSpinBox *nb_toilettes;
    QPushButton *images;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *inserer)
    {
        if (inserer->objectName().isEmpty())
            inserer->setObjectName("inserer");
        inserer->resize(1037, 554);
        inserer->setStyleSheet(QString::fromUtf8(""));
        formLayoutWidget = new QWidget(inserer);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(120, 60, 811, 278));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label);

        cle = new QLineEdit(formLayoutWidget);
        cle->setObjectName("cle");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, cle);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_2);

        Type = new QLineEdit(formLayoutWidget);
        Type->setObjectName("Type");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, Type);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label_3);

        standing = new QLineEdit(formLayoutWidget);
        standing->setObjectName("standing");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, standing);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName("label_4");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, label_4);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName("label_5");

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, label_5);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName("label_6");

        formLayout->setWidget(5, QFormLayout::ItemRole::LabelRole, label_6);

        description = new QTextEdit(formLayoutWidget);
        description->setObjectName("description");

        formLayout->setWidget(5, QFormLayout::ItemRole::FieldRole, description);

        nb_chambres = new QSpinBox(formLayoutWidget);
        nb_chambres->setObjectName("nb_chambres");

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, nb_chambres);

        nb_toilettes = new QSpinBox(formLayoutWidget);
        nb_toilettes->setObjectName("nb_toilettes");

        formLayout->setWidget(4, QFormLayout::ItemRole::FieldRole, nb_toilettes);

        images = new QPushButton(formLayoutWidget);
        images->setObjectName("images");

        formLayout->setWidget(6, QFormLayout::ItemRole::FieldRole, images);

        pushButton = new QPushButton(inserer);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(260, 390, 211, 51));
        pushButton_2 = new QPushButton(inserer);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(630, 390, 211, 51));
        pushButton_3 = new QPushButton(inserer);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(440, 480, 181, 41));

        retranslateUi(inserer);

        QMetaObject::connectSlotsByName(inserer);
    } // setupUi

    void retranslateUi(QWidget *inserer)
    {
        inserer->setWindowTitle(QCoreApplication::translate("inserer", "Form", nullptr));
        label->setText(QCoreApplication::translate("inserer", "Nom(cle)", nullptr));
        label_2->setText(QCoreApplication::translate("inserer", "Type", nullptr));
        label_3->setText(QCoreApplication::translate("inserer", "standing", nullptr));
        label_4->setText(QCoreApplication::translate("inserer", "nombre chambres", nullptr));
        label_5->setText(QCoreApplication::translate("inserer", "nombre toilettes", nullptr));
        label_6->setText(QCoreApplication::translate("inserer", "description", nullptr));
        images->setText(QCoreApplication::translate("inserer", "Ajouter des images", nullptr));
        pushButton->setText(QCoreApplication::translate("inserer", "Ajouter", nullptr));
        pushButton_2->setText(QCoreApplication::translate("inserer", "renitialiser", nullptr));
        pushButton_3->setText(QCoreApplication::translate("inserer", "Retour", nullptr));
    } // retranslateUi

};

namespace Ui {
    class inserer: public Ui_inserer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERER_H
