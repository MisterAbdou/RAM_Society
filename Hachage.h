#ifndef HACHAGE_H
#define HACHAGE_H
#include "qstring.h"
#include <iostream>
#include <QString>
#include <QTableView>
// #include <QString>
using namespace std;
struct valeur
{
    QString type;    // type de la maison
    QString stand;   // le standing de la maison
    int nb_ch;      // nombre de chambre
    int nb_bthl;    // nombre de toilette
    QString descrip; // description de la maison
};

struct Maison
{
    QString cle;
    valeur val;
    Maison *suiv; // un pointeur sur un element
};

class TableHachage
{
private:
    int tailleMax; // taille maximale de la table de hachage
    int nbcourant; // nb courant
    Maison **tab;  // tableau de maison

public:
    TableHachage(int);
    ~TableHachage();                                               //   estructeur
    void insertion(QString, QString, QString, int, int, QString, int); // ajouter d'une maison dans la table
    void suppression(QString, int);                                 // suprressioon d'une maison dans la table
    bool content(QString, int);                                     // appartenance d'une maison
    int size();                                                    // le nombre de paire entrer dans la table
    bool Est_vide();                                               // retourne vrai si la table est vide
    unsigned int f1(const QString& cle);                                       // premiere fonction de  hachage
    unsigned long f2(const QString& cle);                                      // deuxieme fonction de hachage
    unsigned int f3(const QString& cle);                                       // troisieme fonction de hachage
    int fonctionSansHachage();
    //void afficher();
    void afficher(QTableView *tableView);
    valeur* get(QString key, int i);
    void vider();

};

#endif // HACHAGE_H
