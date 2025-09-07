/*#ifndef AFFICHAGES_H
#define AFFICHAGES_H

#include <QWidget>

namespace Ui {
class Affichages;
}

class Affichages : public QWidget
{
    Q_OBJECT

public:
    explicit Affichages(QWidget *parent = nullptr);
    ~Affichages();

private:
    Ui::Affichages *ui;
};

#endif // AFFICHAGES_H*/

#ifndef AFFICHAGES_H
#define AFFICHAGES_H

#include <QWidget>
#include "Hachage.h"

namespace Ui {
class Affichages;
}

class Affichages : public QWidget
{
    Q_OBJECT

public:
    //explicit Affichages(TableHachage *tableHachage, QWidget *parent = nullptr);
    explicit Affichages(TableHachage *tableHachage, QWidget *parent = nullptr);
    ~Affichages();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Affichages *ui;
    // TableHachage *table;  // optionnel, uniquement si tu veux le réutiliser ailleurs
};

#endif // AFFICHAGES_H

