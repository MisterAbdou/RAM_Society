#include "supprimer.h"
#include "ui_supprimer.h"
#include <QMessageBox>
#define maxins 500
#define maxsup 1500

Supprimer::Supprimer(TableHachage* tab,Maison **tsupprimer,int ch,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Supprimer)
    ,tableau(tab)
    ,tsupp(tsupprimer)
    ,choix(ch)
{
    ui->setupUi(this);
}

Supprimer::~Supprimer()
{
    delete ui;
}

/*void Supprimer::on_pushButton_clicked()
{
    QString cle=ui->cleSupprimer->text();
    qDebug()<<cle;
    if(tableau->content(cle,choix))
    {
        valeur *v=tableau->get(cle,choix);
        int i=0;
        while(i<maxsup&&tsupp[i]!=nullptr)
            i++;
        if(i<maxsup)
        {
            Maison* m = new Maison;
            m->cle = cle;
            m->val = {v->type, v->stand, v->nb_ch, v->nb_bthl, v->descrip};
            m->suiv = nullptr;
            tsupp[i] = m;
        }
        //tsupp->insertion(cle,v->type,v->stand,v->nb_ch,v->nb_bthl,v->descrip,choix);
        tableau->suppression(cle,choix);
        qDebug()<<"Suppression de "<<cle<<"reussi";
    }else{
        qDebug()<<"la cle n'esiste pas ";
    }

}*/

void Supprimer::on_pushButton_clicked()
{
    QString cle = ui->cleSupprimer->text().trimmed();

    if (cle.isEmpty()) {
        QMessageBox::warning(this, "Champ vide", "Veuillez entrer une clé à supprimer.");
        return;
    }

    if (!tableau->content(cle, choix)) {
        QMessageBox::critical(this, "Erreur", "La clé spécifiée n'existe pas dans la table.");
        return;
    }

    // Demande de confirmation
    auto reponse = QMessageBox::question(this, "Confirmation", "Êtes-vous sûr de vouloir supprimer cette maison ?");
    if (reponse != QMessageBox::Yes) {
        return;
    }

    // La clé existe, on peut supprimer
    valeur *v = tableau->get(cle, choix);

    int i = 0;
    while (i < maxsup && tsupp[i] != nullptr)
        i++;

    if (i < maxsup) {
        Maison* m = new Maison;
        m->cle = cle;
        m->val = {v->type, v->stand, v->nb_ch, v->nb_bthl, v->descrip};
        m->suiv = nullptr;
        tsupp[i] = m;
    }

    tableau->suppression(cle, choix);
    qDebug() << "Suppression de" << cle << "réussie";

    QMessageBox::information(this, "Succès", "La maison a été supprimée avec succès !");
    ui->cleSupprimer->clear();  // Efface le champ après suppression
}

