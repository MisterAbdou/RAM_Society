#include "pageafficher.h"
#include "ui_pageafficher.h"
#include <QGroupBox>
#include <QVBoxLayout>
#include <QLabel>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QPixmap>
#include <QByteArray>

Affichage::Affichage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Affichage)
{
    ui->setupUi(this);

    // Assure-toi que le layout est défini dans ton .ui et nommé "mainLayout"
    mainLayout = new QVBoxLayout(this);
    setLayout(mainLayout);
}

Affichage::~Affichage()
{
    delete ui;
}

void Affichage::afficherDepuisTable(TableHachage *table)
{
    // Nettoyage du layout
    QLayoutItem *item;
    while ((item = mainLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    int count = 0;

    for (int i = 0; i < table->getTailleMax(); ++i) {
        Maison* courant = table->getMaisonByIndex(i); // Fonction à ajouter si ce n'est pas déjà fait

        while (courant != nullptr) {
            QGroupBox *maisonBox = new QGroupBox("Maison : " + courant->cle);
            QVBoxLayout *boxLayout = new QVBoxLayout(maisonBox);

            valeur val = courant->val;

            QLabel *descLabel = new QLabel(
                QString("Type : %1\nStanding : %2\nChambres : %3\nToilettes : %4\nDescription : %5")
                    .arg(val.type)
                    .arg(val.stand)
                    .arg(val.nb_ch)
                    .arg(val.nb_bthl)
                    .arg(val.descrip)
                );
            boxLayout->addWidget(descLabel);

            // Requête pour récupérer les images liées à la maison
            if (!QSqlDatabase::contains("qt_sql_default_connection"))
                db = QSqlDatabase::addDatabase("QSQLITE");
            else
                db = QSqlDatabase::database();

            db.setDatabaseName("C:/sqlite/RAM_SOCIETY.db"); // Remplace par ton chemin correct

            if (db.open()) {
                QSqlQuery imgQuery(db);
                imgQuery.prepare("SELECT image_blob FROM image WHERE maison_cle = ?");
                imgQuery.addBindValue(courant->cle);

                if (imgQuery.exec()) {
                    while (imgQuery.next()) {
                        QByteArray imageData = imgQuery.value(0).toByteArray();
                        QPixmap pix;
                        pix.loadFromData(imageData);

                        QLabel *imageLabel = new QLabel;
                        imageLabel->setPixmap(pix.scaled(200, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation));
                        boxLayout->addWidget(imageLabel);
                    }
                } else {
                    qDebug() << "Erreur requête image:" << imgQuery.lastError().text();
                }
            } else {
                qDebug() << "Échec ouverture BDD pour les images";
            }

            mainLayout->addWidget(maisonBox);
            courant = courant->suiv;
            count++;
        }
    }

    if (count == 0) {
        QMessageBox::information(this, "Affichage", "Aucune maison dans la table de hachage.");
    }
}
