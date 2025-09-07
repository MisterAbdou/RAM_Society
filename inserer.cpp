#include "inserer.h"
#include "ui_inserer.h"
#include<QTextEdit>
#include <QDebug>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QFileDialog>
#include <QFile>
#include <QByteArray>
#define maxins 500
#define maxsup 1500


inserer::inserer(TableHachage *table, Maison **tinser, int *pt, QVector<ImageTemporaire> *imgList, QWidget *parent)
    : QWidget(parent),
    ui(new Ui::inserer),
    table(table),
    tinse(tinser),
    choiPi(pt),
    images(imgList)
{
    ui->setupUi(this);
}

inserer::~inserer()
{
    delete ui;
}

void inserer::on_pushButton_clicked()
{
    QString cle = ui->cle->text().trimmed();
    QString type = ui->Type->text().trimmed();
    QString standing = ui->standing->text().trimmed();
    int n_chambre = ui->nb_chambres->value();
    int n_toilette = ui->nb_toilettes->value();
    QString description = ui->description->toPlainText().trimmed();

    // Vérification des champs textes
    if (cle.isEmpty() || type.isEmpty() || standing.isEmpty() || description.isEmpty()) {
        QMessageBox::warning(this, "Champs vides", "Veuillez remplir tous les champs obligatoires.");
        return;
    }

    // Vérification des nombres si besoin (par exemple 0 chambres n’est pas valide)
    if (n_chambre <= 0 || n_toilette <= 0) {
        QMessageBox::warning(this, "Valeurs invalides", "Le nombre de chambres et de toilettes doit être supérieur à 0.");
        return;
    }

    if(!table->content(cle,*choiPi))
    {
        table->insertion(cle,type,standing,n_chambre,n_toilette,description,*choiPi);
        //on insere dans la table qu'on doit ajouter dans la base en cas de
        int i=0;
        while(i<maxins&&tinse[i]!=nullptr)
            i++;
        if(i<maxins)
        {
            Maison* m = new Maison;
            m->cle = cle;
            m->val = {type, standing,n_chambre,n_toilette,description};
            m->suiv = nullptr;
            tinse[i] = m;
        }


         QMessageBox::information(this, "Succès", "Maison insérée dans la table et la base !");
    }else{
        QMessageBox::critical(this, "Redondance", "La maison existe deja" );
    }

}


void inserer::on_pushButton_3_clicked()
{
    this->close();
}


void inserer::on_images_clicked()
{
    if (ui->cle->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, "Clé manquante", "Veuillez d'abord entrer la clé de la maison.");
        return;
    }

    QStringList chemins = QFileDialog::getOpenFileNames(this, "Choisir les images", "", "Images (*.png *.jpg *.jpeg *.bmp)");
    if (!chemins.isEmpty()) {
        for (const QString &chemin : chemins) {
            QFile file(chemin);
            if (file.open(QIODevice::ReadOnly)) {
                QByteArray blob = file.readAll();
                ImageTemporaire img;
                img.cle = ui->cle->text().trimmed();
                img.image_blob = blob;
                images->append(img);
            }
        }

        QMessageBox::information(this, "Images", QString("%1 image(s) ajoutée(s)").arg(chemins.size()));
    }
}

