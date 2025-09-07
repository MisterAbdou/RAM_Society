/********************************************************************************
** Form generated from reading UI file 'pageafficher.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGEAFFICHER_H
#define UI_PAGEAFFICHER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PageAfficher
{
public:

    void setupUi(QWidget *PageAfficher)
    {
        if (PageAfficher->objectName().isEmpty())
            PageAfficher->setObjectName("PageAfficher");
        PageAfficher->resize(973, 450);

        retranslateUi(PageAfficher);

        QMetaObject::connectSlotsByName(PageAfficher);
    } // setupUi

    void retranslateUi(QWidget *PageAfficher)
    {
        PageAfficher->setWindowTitle(QCoreApplication::translate("PageAfficher", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PageAfficher: public Ui_PageAfficher {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGEAFFICHER_H
