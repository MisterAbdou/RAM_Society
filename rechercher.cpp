#include "rechercher.h"
#include "ui_rechercher.h"
#include "QDebug"
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>


Rechercher::Rechercher(TableHachage* tab,int ch,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Rechercher)
    ,tableau(tab)
    ,choix(ch)
{
    ui->setupUi(this);
}

Rechercher::~Rechercher()
{
    delete ui;
}

/*void Rechercher::on_boutonrechercher_clicked()
{
    QString cle = ui->rechercher->text();
    qDebug() << cle;

    valeur* v = tableau->get(cle, choix);
    qDebug() << "choix :" << choix;

    if (tableau->content(cle, choix))
    {

        ui->labelType->setText("Type : "+v->type);
        ui->labelStanding->setText("Standing : "+v->stand);
        ui->labelChambres->setText("Nombre de chambres : " + QString::number(v->nb_ch));
       ui->labelToilettes->setText("Nombre de toilettes : " + QString::number(v->nb_bthl));
        ui->labelDescription->setText("Description : "+v->descrip);

        QSqlDatabase db = QSqlDatabase::database("maConnexion");
        if (!db.isOpen()) {
            if (!db.open()) {
                qDebug() << "Base non ouverte :" << db.lastError().text();
                return;
            }
        }

        QSqlQuery query(db);
        query.prepare("SELECT image_blob FROM image WHERE maison_cle = :cle");
        query.bindValue(":cle", cle);

        QList<QLabel*> imageLabels = {
            ui->label_3, ui->label_4, ui->label_5,
            ui->label_6, ui->label_7, ui->label_8
        };

        int imageIndex = 0;

        if (query.exec()) {
            while (query.next() && imageIndex < imageLabels.size()) {
                QByteArray imageData = query.value(0).toByteArray();
                QPixmap image;
                if (image.loadFromData(imageData)) {
                    imageLabels[imageIndex]->setPixmap(image.scaled(
                        imageLabels[imageIndex]->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
                } else {
                    qDebug() << "Erreur chargement image à l'index" << imageIndex;
                    imageLabels[imageIndex]->setText("Erreur image");
                }
                imageIndex++;
            }

            // Si aucune image trouvée
            if (imageIndex == 0) {
                imageLabels[0]->setText("Aucune image");
            }

            //On Vide les labels restants
            for (int i = imageIndex; i < imageLabels.size(); ++i) {
                imageLabels[i]->clear();
            }

        } else {
            qDebug() << "Erreur SQL :" << query.lastError().text();
            imageLabels[0]->setText("Erreur chargement image");
            for (int i = 1; i < imageLabels.size(); ++i) {
                imageLabels[i]->clear();
            }
        }

    } else {
        ui->labelType->setText("Non trouvé");
        ui->labelStanding->clear();
        ui->labelChambres->clear();
        ui->labelToilettes->clear();
        ui->labelDescription->clear();

        ui->label_3->clear();
        ui->label_4->clear();
        ui->label_5->clear();
        ui->label_6->clear();
        ui->label_7->clear();
        ui->label_8->clear();
    }
}*/


void Rechercher::on_boutonrechercher_clicked()
{
    QString cle = ui->rechercher->text();
    qDebug() << cle;

    valeur* v = tableau->get(cle, choix);
    qDebug() << "choix :" << choix;

    if (tableau->content(cle, choix))
    {
        // Affichage des infos textuelles
        ui->labelType->setText("Type : " + v->type);
        ui->labelStanding->setText("Standing : " + v->stand);
        ui->labelChambres->setText("Nombre de chambres : " + QString::number(v->nb_ch));
        ui->labelToilettes->setText("Nombre de toilettes : " + QString::number(v->nb_bthl));
        ui->labelDescription->setText("Description : " + v->descrip);

        // Connexion à la base
        QSqlDatabase db = QSqlDatabase::database("maConnexion");
        if (!db.isOpen()) {
            if (!db.open()) {
                qDebug() << "Base non ouverte :" << db.lastError().text();
                return;
            }
        }

        // Requête SQL pour récupérer les images
        QSqlQuery query(db);
        query.prepare("SELECT image_blob FROM image WHERE maison_cle = :cle");
        query.bindValue(":cle", cle);

        // Charger les images dans la liste
        listeImages.clear();
        indexImageActuelle = 0;

        if (query.exec()) {
            while (query.next()) {
                QByteArray imageData = query.value(0).toByteArray();
                QPixmap image;
                if (image.loadFromData(imageData)) {
                    listeImages.append(image);
                }
            }

            if (!listeImages.isEmpty()) {
                afficherImageCourante();
                ui->btnPrecedent->setEnabled(true);
                ui->btnSuivant->setEnabled(true);
            } else {
                ui->labelImage->setText("Aucune image");
                ui->btnPrecedent->setEnabled(false);
                ui->btnSuivant->setEnabled(false);
            }

        } else {
            qDebug() << "Erreur SQL :" << query.lastError().text();
            ui->labelImage->setText("Erreur chargement image");
            ui->btnPrecedent->setEnabled(false);
            ui->btnSuivant->setEnabled(false);
        }

    } else {
        // Si la clé n’est pas trouvée
        ui->labelType->setText("Non trouvé");
        ui->labelStanding->clear();
        ui->labelChambres->clear();
        ui->labelToilettes->clear();
        ui->labelDescription->clear();

        ui->labelImage->setText("Aucune image");
        ui->btnPrecedent->setEnabled(false);
        ui->btnSuivant->setEnabled(false);
    }
}

