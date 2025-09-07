#include "affichages.h"
#include "ui_affichages.h"
#include <QSqlTableModel>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>



Affichages::Affichages(TableHachage *tableHachage, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Affichages)
{
    ui->setupUi(this);
    tableHachage->afficher(ui->LesVues);  // ui->LesVues est un QTableView ici
}


Affichages::~Affichages()
{
    delete ui;
}



void Affichages::on_pushButton_clicked()
{
    this->close();
}

