#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"connexion.h"
#include "Hachage.h"
#include "resultat.h"
#include<QDebug>
#include<QMessageBox>
#include <QPixmap>
#include "affichages.h"
#include <QProgressDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap logo(":/images/logo.png");
    ui->labelLogo->setPixmap(logo.scaled(500, 500, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->labelLogo->setAlignment(Qt::AlignCenter);

    // Centrer le texte (sécurité)
    ui->labelTexte->setAlignment(Qt::AlignCenter);
    QVector<ImageTemporaire> images_temp;
    connexionPOO();
    Table=new TableHachage(1000);
    if(!Table)
    {
        qDebug()<<"erreur d'allocation";
        exit(-1);
    }

    Tableajout=new Maison*[maxins];
    if(!Tableajout)
    {
        qDebug()<<"erreur d'allocation";
        exit(-1);
    }
    int i=0;
    while(i<maxins)
    {
        Tableajout[i]=nullptr;
        i++;
    }

    Tablesupprimer=new Maison*[1500];
    if(!Tablesupprimer)
    {
        qDebug()<<"erreur d'allocation";
        exit(-1);
    }
    i=0;
    while(i<maxsup)
    {
        Tablesupprimer[i]=nullptr;
        i++;
    }



}

MainWindow::~MainWindow()
{
    delete ui;
    delete ptrInserer;
    delete ptrRechercher;
    delete choix;
    delete chargereussi;
    int i=0;
    while(i<maxins&&Tableajout[i]!=nullptr)
    {
        delete Tableajout[i];
    }
    delete []Tableajout;

    i=0;
    while(i<maxins&&Tableajout[i]!=nullptr)
    {
        delete Tablesupprimer[i];
    }
    delete []Tablesupprimer;
}
//-------------------------Chargement-----------------------

void MainWindow::on_actionCharger_triggered()
{
    if (!choix)
    {
        QMessageBox::critical(this, "Erreur", "Vous devez choisir une fonction de hachage avant de charger la table !");
        return;
    }

    QSqlDatabase db = QSqlDatabase::database("maConnexion");
    if (!db.isOpen()) {
        QMessageBox::critical(this, "Erreur", "La base de données n'est pas ouverte.");
        return;
    }


    QSqlQuery query(db);
    if (!query.exec("SELECT * FROM maison")) {
        QMessageBox::critical(this, "Erreur SQL", "Erreur lors de l'exécution de la requête : " + query.lastError().text());
        return;
    }

    Table->vider();
    // Vider la table avant de recharger, si nécessaire
    while (query.next()) {
        QString cle      = query.value("cle").toString();
        QString type     = query.value("type").toString();
        QString stand    = query.value("standing").toString();
        int nb_ch        = query.value("nb_chambres").toInt();
        int nb_bthl      = query.value("nb_toilettes").toInt();
        QString descrip  = query.value("description").toString();

        Table->insertion(cle, type, stand, nb_ch, nb_bthl, descrip, *choix);
    }

    chargereussi = new int(1); // ou juste un bool serait plus propre
    QMessageBox::information(this, "Chargement", "Chargement de la base réussi !");
}


/*void MainWindow::on_actionCharger_triggered()
{
    if (!choix)
    {
        QMessageBox::critical(this, "Erreur", "Vous devez choisir une fonction de hachage avant de charger la table !");
        return;
    }

    QSqlDatabase db = QSqlDatabase::database("maConnexion");
    if (!db.isOpen()) {
        QMessageBox::critical(this, "Erreur", "La base de données n'est pas ouverte.");
        return;
    }

    // Étape 1 : compter le nombre total de lignes
    int total = 0;
    QSqlQuery countQuery(db);
    if (countQuery.exec("SELECT COUNT(*) FROM maison") && countQuery.next()) {
        total = countQuery.value(0).toInt();
    }

    if (total == 0) {
        QMessageBox::information(this, "Chargement", "Aucune donnée à charger !");
        return;
    }

    // Étape 2 : créer la barre de progression
    QProgressDialog progress("Chargement des données...", "Annuler", 0, total, this);
    progress.setWindowModality(Qt::WindowModal);
    progress.setMinimumDuration(0);
    progress.setValue(0);

    // Étape 3 : exécuter la requête et charger
    QSqlQuery query(db);
    if (!query.exec("SELECT * FROM maison")) {
        QMessageBox::critical(this, "Erreur SQL", "Erreur lors de la requête : " + query.lastError().text());
        return;
    }

    int current = 0;

    while (query.next()) {
        QString cle      = query.value("cle").toString();
        QString type     = query.value("type").toString();
        QString stand    = query.value("standing").toString();
        int nb_ch        = query.value("nb_chambres").toInt();
        int nb_bthl      = query.value("nb_toilettes").toInt();
        QString descrip  = query.value("description").toString();

        Table->insertion(cle, type, stand, nb_ch, nb_bthl, descrip, *choix);

        // Mise à jour de la barre
        current++;
        progress.setValue(current);

        if (progress.wasCanceled()) {
            QMessageBox::warning(this, "Annulé", "Le chargement a été interrompu par l'utilisateur.");
            return;
        }
    }

    chargereussi = new int(1);
    progress.setValue(total); // aller jusqu'à 100%
    QMessageBox::information(this, "Chargement", "Chargement de la base réussi !");
}*/


//-------------------------Afficher-----------------------
void MainWindow::on_actionAfficher_triggered()
{   if(!chargereussi)
    {
        QMessageBox::information(this, "Afficher", "Charger d'abord la table avant d'afficher");
        return;
    }


    //Table->afficher();
    //Affichages *fenetre = new Affichages(this);
    //fenetre->show();  // Ou .exec() si tu passes à QDialog
    Affichages *fenetre = new Affichages(Table);  // Table est un pointeur vers TableHachage
    connect(fenetre, &Affichages::destroyed, this, &MainWindow::show);
    fenetre->show();
}



//---------------------------------Choix des fonction-------------------
void MainWindow::on_actionf1_triggered()
{
    if(!choix)
        choix=new int();
    *choix=1;
    qDebug()<<*choix;
}


void MainWindow::on_actionf2_triggered()
{
    if(!choix)
        choix=new int();
    *choix=2;
            qDebug()<<*choix;
}


void MainWindow::on_actionf3_triggered()
{
    if(!choix)
        choix=new int();
    *choix=3;
    qDebug()<<*choix;
}


void MainWindow::on_actionSans_Hachage_triggered()
{
    if(!choix)
        choix=new int();
    *choix=4;
    qDebug()<<*choix;
}
//-----------------------------------------------------------------

//-------------------------------Taille----------
void MainWindow::on_actionTaille_triggered()
{
    if (chargereussi) {
        int taille = Table->size();  // Accès via méthode publique
        QMessageBox::information(this, "Taille",
                                 "La taille de la base est : " + QString::number(taille));
    } else {
        QMessageBox::warning(this, "Erreur", "La table n’est pas encore chargée !");
    }
}

// ---------------------quitter----------------------
void MainWindow::on_actionQuitter_2_triggered()
{
    close();
}

//--------------------INSERTION---------------------
void MainWindow::on_actionIns_rer_triggered()
{
    if(!chargereussi)
    {
        QMessageBox::information(this, "Afficher", "Charger d'abord la table avant d'afficher");
        return;
    }

    inserer *fenetreInserer = new inserer(Table,Tableajout,choix, &images_temp);
    connect(fenetreInserer, &inserer::destroyed, this, &MainWindow::show);
    fenetreInserer->show();
}

//-----------------Rechercher----------------------------
void MainWindow::on_actionRechercher_triggered()
{
    if(!chargereussi)
    {
        QMessageBox::information(this, "Afficher", "Charger d'abord la table avant d'afficher");
        return;
    }

    ptrRechercher =new Rechercher(Table,*choix);
    ptrRechercher->show();
}

//------------------suppression----------------
void MainWindow::on_actionSupprimer_triggered()
{
    if(!chargereussi)
    {
        QMessageBox::information(this, "Afficher", "Charger d'abord la table avant d'afficher");
        return;
    }
    ptrsupprimer=new Supprimer(Table,Tablesupprimer,*choix);
    ptrsupprimer->show();
}

//------------------Suavegarder-----------------------
void MainWindow::on_actionSauvegarder_triggered()
{
    QSqlDatabase db = QSqlDatabase::database("maConnexion");
    if (!db.isOpen()) {
        QMessageBox::critical(this, "Erreur", "La base de données n'est pas ouverte.");
        return;
    }

    QSqlQuery query(db);

    //------------- Pour savegarder  l'ajout dans la BD ----------
    int i = 0;
    while (i < maxins && Tableajout[i] != nullptr) {
        Maison* m = Tableajout[i];

        query.prepare("INSERT OR REPLACE INTO maison "
                      "(cle, type, standing, nb_chambres, nb_toilettes, description) "
                      "VALUES (:cle, :type, :standing, :nb_chambres, :nb_toilettes, :description)");
        query.bindValue(":cle", m->cle);
        query.bindValue(":type", m->val.type);
        query.bindValue(":standing", m->val.stand);
        query.bindValue(":nb_chambres", m->val.nb_ch);
        query.bindValue(":nb_toilettes", m->val.nb_bthl);
        query.bindValue(":description", m->val.descrip);

        if (!query.exec()) {
            QMessageBox::warning(this, "Erreur insertion maison", query.lastError().text());
            // On continue malgré l'erreur
        }

        i++;
    }

    // Insertion des images avec vérification de la clé étrangère
    for (const ImageTemporaire& img : images_temp) {
        // Vérifier si la clé existe dans la table maison
        query.prepare("SELECT 1 FROM maison WHERE cle = :cle");
        query.bindValue(":cle", img.cle);

        if (!query.exec()) {
            QMessageBox::warning(this, "Erreur SQL", "Erreur lors de la vérification clé maison : " + query.lastError().text());
            continue;  // Passe à l’image suivante
        }

        if (query.next()) {  // La clé existe, on peut insérer l'image
            query.prepare("INSERT INTO image (maison_cle, image_blob) VALUES (:cle, :blob)");
            query.bindValue(":cle", img.cle);
            query.bindValue(":blob", img.image_blob);

            if (!query.exec()) {
                QMessageBox::warning(this, "Erreur insertion image", query.lastError().text());
                continue;
            }
        } else {
            qDebug() << "Image ignorée car clé maison non trouvée :" << img.cle;
        }
    }

    // Suppression des maisons dans Tablesupprimer
    int j = 0;
    while (j < maxsup && Tablesupprimer[j] != nullptr) {
        Maison* m = Tablesupprimer[j];

        // Supprimer d'abord les images associées
        query.prepare("DELETE FROM image WHERE maison_cle = :cle");
        query.bindValue(":cle", m->cle);
        if (!query.exec()) {
            QMessageBox::warning(this, "Erreur suppression image", query.lastError().text());
        }

        // Supprimer la maison
        query.prepare("DELETE FROM maison WHERE cle = :cle");
        query.bindValue(":cle", m->cle);
        if (!query.exec()) {
            QMessageBox::warning(this, "Erreur suppression maison", query.lastError().text());
        }

        j++;
    }




    QMessageBox::information(this, "Sauvegarde", "Sauvegarde terminée.");
}


