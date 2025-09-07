/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCharger;
    QAction *actionAfficher;
    QAction *actionTaille;
    QAction *actionQuitter;
    QAction *actionSauvegarder;
    QAction *actionQuitter_2;
    QAction *actionRechercher;
    QAction *actionIns_rer;
    QAction *actionSupprimer;
    QAction *actionf1;
    QAction *actionf2;
    QAction *actionf3;
    QAction *actionSans_Hachage;
    QAction *actionHachage_Sans_Hachage;
    QAction *actionf_i_f_j;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QLabel *labelLogo;
    QLabel *labelTexte;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menubar;
    QMenu *menuBases;
    QMenu *menuMaison;
    QMenu *menuFonction_Hachage;
    QMenu *menuCourbe_de_Comparaison;
    QMenu *menuAide;
    QStatusBar *statusbar;
    QToolBar *toolBar;
    QToolBar *toolBar_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1037, 554);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color:#EAEFEF;"));
        actionCharger = new QAction(MainWindow);
        actionCharger->setObjectName("actionCharger");
        actionAfficher = new QAction(MainWindow);
        actionAfficher->setObjectName("actionAfficher");
        actionTaille = new QAction(MainWindow);
        actionTaille->setObjectName("actionTaille");
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName("actionQuitter");
        actionSauvegarder = new QAction(MainWindow);
        actionSauvegarder->setObjectName("actionSauvegarder");
        actionQuitter_2 = new QAction(MainWindow);
        actionQuitter_2->setObjectName("actionQuitter_2");
        actionRechercher = new QAction(MainWindow);
        actionRechercher->setObjectName("actionRechercher");
        actionIns_rer = new QAction(MainWindow);
        actionIns_rer->setObjectName("actionIns_rer");
        actionSupprimer = new QAction(MainWindow);
        actionSupprimer->setObjectName("actionSupprimer");
        actionf1 = new QAction(MainWindow);
        actionf1->setObjectName("actionf1");
        actionf2 = new QAction(MainWindow);
        actionf2->setObjectName("actionf2");
        actionf3 = new QAction(MainWindow);
        actionf3->setObjectName("actionf3");
        actionSans_Hachage = new QAction(MainWindow);
        actionSans_Hachage->setObjectName("actionSans_Hachage");
        actionHachage_Sans_Hachage = new QAction(MainWindow);
        actionHachage_Sans_Hachage->setObjectName("actionHachage_Sans_Hachage");
        actionf_i_f_j = new QAction(MainWindow);
        actionf_i_f_j->setObjectName("actionf_i_f_j");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, -1, -1, -1);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        labelLogo = new QLabel(centralwidget);
        labelLogo->setObjectName("labelLogo");
        labelLogo->setScaledContents(true);

        verticalLayout->addWidget(labelLogo, 0, Qt::AlignmentFlag::AlignHCenter);

        labelTexte = new QLabel(centralwidget);
        labelTexte->setObjectName("labelTexte");
        labelTexte->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #2c3e50;\n"
"    font-size: 18pt;\n"
"    font-weight: bold;\n"
"    font-style: italic;\n"
"    text-align: center;\n"
"}"));

        verticalLayout->addWidget(labelTexte, 0, Qt::AlignmentFlag::AlignHCenter);

        label = new QLabel(centralwidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);


        verticalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1037, 26));
        menuBases = new QMenu(menubar);
        menuBases->setObjectName("menuBases");
        menuMaison = new QMenu(menubar);
        menuMaison->setObjectName("menuMaison");
        menuFonction_Hachage = new QMenu(menubar);
        menuFonction_Hachage->setObjectName("menuFonction_Hachage");
        menuCourbe_de_Comparaison = new QMenu(menubar);
        menuCourbe_de_Comparaison->setObjectName("menuCourbe_de_Comparaison");
        menuAide = new QMenu(menubar);
        menuAide->setObjectName("menuAide");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);
        toolBar_2 = new QToolBar(MainWindow);
        toolBar_2->setObjectName("toolBar_2");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar_2);

        menubar->addAction(menuBases->menuAction());
        menubar->addAction(menuMaison->menuAction());
        menubar->addAction(menuFonction_Hachage->menuAction());
        menubar->addAction(menuCourbe_de_Comparaison->menuAction());
        menubar->addAction(menuAide->menuAction());
        menuBases->addAction(actionCharger);
        menuBases->addAction(actionAfficher);
        menuBases->addAction(actionTaille);
        menuBases->addAction(actionSauvegarder);
        menuBases->addSeparator();
        menuBases->addAction(actionQuitter_2);
        menuMaison->addAction(actionRechercher);
        menuMaison->addAction(actionIns_rer);
        menuMaison->addAction(actionSupprimer);
        menuFonction_Hachage->addAction(actionf1);
        menuFonction_Hachage->addAction(actionf2);
        menuFonction_Hachage->addAction(actionf3);
        menuFonction_Hachage->addAction(actionSans_Hachage);
        menuCourbe_de_Comparaison->addAction(actionHachage_Sans_Hachage);
        menuCourbe_de_Comparaison->addAction(actionf_i_f_j);
        toolBar_2->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionCharger->setText(QCoreApplication::translate("MainWindow", "Charger", nullptr));
        actionAfficher->setText(QCoreApplication::translate("MainWindow", "Afficher", nullptr));
        actionTaille->setText(QCoreApplication::translate("MainWindow", "Taille", nullptr));
        actionQuitter->setText(QCoreApplication::translate("MainWindow", "Quitter", nullptr));
        actionSauvegarder->setText(QCoreApplication::translate("MainWindow", "Sauvegarder", nullptr));
        actionQuitter_2->setText(QCoreApplication::translate("MainWindow", "Quitter", nullptr));
        actionRechercher->setText(QCoreApplication::translate("MainWindow", "Rechercher", nullptr));
        actionIns_rer->setText(QCoreApplication::translate("MainWindow", "Ins\303\251rer", nullptr));
        actionSupprimer->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        actionf1->setText(QCoreApplication::translate("MainWindow", "f1", nullptr));
        actionf2->setText(QCoreApplication::translate("MainWindow", "f2", nullptr));
        actionf3->setText(QCoreApplication::translate("MainWindow", "f3", nullptr));
        actionSans_Hachage->setText(QCoreApplication::translate("MainWindow", "Sans Hachage", nullptr));
        actionHachage_Sans_Hachage->setText(QCoreApplication::translate("MainWindow", "Hachage / Sans Hachage", nullptr));
        actionf_i_f_j->setText(QCoreApplication::translate("MainWindow", "f(i)/f(j)", nullptr));
        label_3->setText(QString());
        labelLogo->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        labelTexte->setText(QCoreApplication::translate("MainWindow", "Bienvenu dans RAM society .  ", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        menuBases->setTitle(QCoreApplication::translate("MainWindow", "Bases", nullptr));
        menuMaison->setTitle(QCoreApplication::translate("MainWindow", "Maison", nullptr));
        menuFonction_Hachage->setTitle(QCoreApplication::translate("MainWindow", "Fonction Hachage", nullptr));
        menuCourbe_de_Comparaison->setTitle(QCoreApplication::translate("MainWindow", "Courbe de Comparaison", nullptr));
        menuAide->setTitle(QCoreApplication::translate("MainWindow", "Aide", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
        toolBar_2->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar_2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
