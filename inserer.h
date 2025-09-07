#ifndef INSERER_H
#define INSERER_H
#include "Hachage.h"
#include <QWidget>
#include <QVector>
#include <QByteArray>

struct ImageTemporaire {
    QString cle;
    QByteArray image_blob;
};
namespace Ui {
class inserer;
}

class inserer : public QWidget
{
    Q_OBJECT

public:
    explicit inserer(TableHachage *table,Maison **tinser,int *pt,QVector<ImageTemporaire> *imgList,QWidget *parent = nullptr);
    ~inserer();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_images_clicked();

private:
    Ui::inserer *ui;
    TableHachage *table;
    Maison **tinse;
    int *choiPi;
    QVector<ImageTemporaire> *images;
};

#endif // INSERER_H
