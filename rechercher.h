#ifndef RECHERCHER_H
#define RECHERCHER_H
#include "Hachage.h"
#include <QWidget>
#include <QVector>
#include <QPixmap>


namespace Ui {
class Rechercher;
}

class Rechercher : public QWidget
{
    Q_OBJECT

public:
    explicit Rechercher(TableHachage* tab,int ch,QWidget *parent = nullptr);
    ~Rechercher();

private slots:

    void on_boutonrechercher_clicked();

private:
    Ui::Rechercher *ui;
    TableHachage *tableau;
    int choix;
};

#endif // RECHERCHER_H
