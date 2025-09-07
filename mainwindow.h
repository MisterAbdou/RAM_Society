#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#define maxins 500
#define maxsup 1500
#include <QMainWindow>
#include <QVector>
#include <QByteArray>
#include"Hachage.h"
#include "inserer.h"
#include "rechercher.h"
#include "supprimer.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionCharger_triggered();

    void on_actionAfficher_triggered();

    void on_actionf1_triggered();

    void on_actionf2_triggered();

    void on_actionf3_triggered();

    void on_actionSans_Hachage_triggered();

    void on_actionTaille_triggered();

    void on_actionQuitter_2_triggered();

    void on_actionIns_rer_triggered();

    void on_actionRechercher_triggered();

    void on_actionSupprimer_triggered();

    void on_actionSauvegarder_triggered();

private:
    Ui::MainWindow *ui;
    TableHachage *Table = nullptr;
    Maison **Tableajout=nullptr;
    Maison **Tablesupprimer=nullptr;
    int *choix=nullptr;
    int *chargereussi=nullptr;

    inserer *ptrInserer;
    Rechercher *ptrRechercher;
    Supprimer *ptrsupprimer;
    QVector<ImageTemporaire> images_temp;
};



#endif // MAINWINDOW_H
