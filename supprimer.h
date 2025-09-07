#ifndef SUPPRIMER_H
#define SUPPRIMER_H
#include "Hachage.h"
#include <QWidget>

namespace Ui {
class Supprimer;
}

class Supprimer : public QWidget
{
    Q_OBJECT

public:
    explicit Supprimer(TableHachage* tab,Maison **tsupprimer,int ch,QWidget *parent = nullptr);
    ~Supprimer();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Supprimer *ui;
    TableHachage *tableau;
    Maison **tsupp;
    int choix;
};

#endif // SUPPRIMER_H
