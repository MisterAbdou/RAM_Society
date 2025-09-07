#ifndef RESULAT_H
#define RESULAT_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlTableModel>

namespace Ui {
class Resulat;
}

class Resulat : public QDialog
{
    Q_OBJECT

public:
    explicit Resulat(QWidget *parent = nullptr);
    ~Resulat();

    void afficherDonnees();

private:
    Ui::Resulat *ui;
    QSqlTableModel *model;
};

#endif // RESULAT_H
