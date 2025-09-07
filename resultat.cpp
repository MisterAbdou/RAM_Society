#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlError>
#include <QDebug>
#include "resultat.h"
#include "ui_resulat.h"


Resulat::Resulat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Resulat)
{
    ui->setupUi(this);
    afficherDonnees(); // Appel lors de l'ouverture du widget
}

Resulat::~Resulat()
{
    delete ui;
}

void Resulat::afficherDonnees()
{
    QSqlDatabase db = QSqlDatabase::database("C:/sqlite/RAM_SOCIETY.db"); // nom de la connexion
    if (!db.isOpen()) {
        qDebug() << "Erreur : base de données non ouverte";
        return;
    }

    model = new QSqlTableModel(this, db);
    model->setTable("maison"); // ⚠ Remplacez par votre nom de table réel
    model->select(); // Charge les données

    ui->TableResultat->setModel(model); // Associe le modèle à votre QTableView
}
