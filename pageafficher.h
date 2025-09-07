#ifndef PAGEAFFICHER_H
#define PAGEAFFICHER_H

#include "Hachage.h"

class Affichage : public QWidget
{
    Q_OBJECT

public:
    explicit Affichage(QWidget *parent = nullptr);
    ~Affichage();

    void afficherDepuisTable(TableHachage *table);
private:
    QVBoxLayout *mainLayout;
    QSqlDatabase db; // utilisé uniquement si tu veux charger des images depuis la BDD
};

#endif // PAGEAFFICHER_H
