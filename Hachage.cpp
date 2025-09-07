#include "Hachage.h"
#include "QChar.h"
#include <qdebug.h>
#include <QStandardItemModel>
#include <QTableView>

TableHachage::TableHachage(int n)
{

    cout << "Appel du constructeur par defaut";
    tailleMax = n;
    nbcourant = 0;
    tab = new Maison *[tailleMax];
    for (int i = 0; i < tailleMax; i++)
    {
        tab[i] = nullptr;
    }
}
TableHachage::~TableHachage()
{
    cout << " Appel du destruction " << endl;
    int i = 0;
    for (int i = 0; i < tailleMax; i++)
    {
        if (tab[i] != nullptr)
        {
            Maison *courant = tab[i];
            Maison *preced;
            while (courant != nullptr)
            {
                preced = courant;
                courant = courant->suiv;
                delete preced;
            }
        }
    }
}

void TableHachage::insertion(QString key, QString typ, QString stan, int nbc, int nbt, QString descrip, int i)
{
    int index = -1;
    switch (i)
    {
    case 1:
        index = f1(key);
        break;
    case 2:
        index = f2(key);
        break;
    case 3:
        index = f3(key);
        break;
    case 4:
        index =fonctionSansHachage();
    }
    Maison *noeud = new Maison;
    if (noeud)
    {
        noeud->cle = key;
        noeud->val.type = typ;
        noeud->val.stand = stan;
        noeud->val.nb_ch = nbc;
        noeud->val.nb_bthl = nbt;
        noeud->val.descrip = descrip;
        noeud->suiv = nullptr;
    }

    if (tab[index] == nullptr)
    {
        tab[index] = noeud;
        nbcourant++; // on incremente  le nombre courant d'element
    }
    else
    {
        if (!content(key, i))
        {
            noeud->suiv = tab[index];
            tab[index] = noeud;
            nbcourant++;
        }
    }
}

void TableHachage::suppression(QString key, int i)
{

    int index = -1;
    switch (i)
    {
    case 1:
        index = f1(key);
        break;
    case 2:
        index = f2(key);
        break;
    case 3:
        index = f3(key);
        break;
    case 4:
        index =fonctionSansHachage();
    }
    if (tab[index] == nullptr)
    {
        cout << " nada" << endl;
    }
    else
    {
        if (tab[index]->cle == key)
        {
            Maison *temp = tab[index];
            tab[index] = tab[index]->suiv;
            delete temp;
            temp = nullptr;
            return;
        }
        Maison *courant = tab[index];
        Maison *preced;
        while (courant != nullptr && courant->cle != key)
        {
            preced = courant;
            courant = courant->suiv;
        }
        if (courant != nullptr)
        {
            preced->suiv = courant->suiv;
            delete courant;
            nbcourant--;
        }
    }
}
bool TableHachage::content(QString key, int i)
{

    int index = -1;
    switch (i)
    {
    case 1:
        index = f1(key);
        break;
    case 2:
        index = f2(key);
        break;
    case 3:
        index = f3(key);
        break;
    case 4:
        index =fonctionSansHachage();
    }
    if (tab[index] == nullptr)
    {
        return false;
    }
    else
    {
        Maison *courant = tab[index];
        while (courant != nullptr && courant->cle != key)
        {
            courant = courant->suiv;
        }
        if (courant)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
int TableHachage::size()
{
    return nbcourant;
}
bool TableHachage::Est_vide()
{
    return nbcourant == 0;
}

int TableHachage::fonctionSansHachage()
{
    for (int i = 0; i < tailleMax; i++)
    {
        if (tab[i] == nullptr)
        {
            return i;
        }
    }
    return -1;
}


unsigned int TableHachage::f1(const QString& cle)
{
    const uint32_t nombrePremierFNV = 16777619u;
    uint32_t valeurHachage = 2166136261u;
    for (QChar caractere : cle)
    {
        valeurHachage ^= static_cast<uint32_t>(caractere.unicode());
        valeurHachage *= nombrePremierFNV;
    }
    return valeurHachage % tailleMax;
}


unsigned long TableHachage::f2(const QString& cle)
{
    unsigned long hash = 0;
    for (int i = 0; i < cle.length(); ++i)
    {
        // QChar c = cle[i];          version QT
        // hash = hash * 131 + c.unicode();   Version QT
        QChar c = cle[i];
        hash = hash * 131 + c.unicode();
    }
    return hash % tailleMax;
}


unsigned int TableHachage::f3(const QString& cle) {
    unsigned long h = 5381;
    for (QChar caractere : cle) {
        h = ((h << 5) + h) + static_cast<unsigned char>(caractere.unicode()); // hash * 33 + c
    }
    return h % tailleMax;
}


/*void TableHachage::afficher()
{
    qDebug() << "Méthode afficher() appelée.";
    for (int i = 0; i < tailleMax; i++)
    {
        if (tab[i] != nullptr)
        {
            qDebug() << "Indice" << i << ":";
            Maison *courant = tab[i];
            while (courant != nullptr)
            {
                qDebug() << "   Clé:" << courant->cle
                         << "| Type:" << courant->val.type
                         << "| Stand:" << courant->val.stand
                         << "| Nb_ch:" << courant->val.nb_ch
                         << "| Nb_bthl:" << courant->val.nb_bthl
                         << "| Desc:" << courant->val.descrip;
                courant = courant->suiv;
            }
        }
    }
}*/

void TableHachage::afficher(QTableView *tableView)
{
    QStandardItemModel *model = new QStandardItemModel();

    // Définir les en-têtes de colonnes
    model->setHorizontalHeaderLabels({ "Clé", "Type", "Stand", "Nb_ch", "Nb_bthl", "Descrip" });

    for (int i = 0; i < tailleMax; ++i)
    {
        Maison *courant = tab[i];
        while (courant != nullptr)
        {
            QList<QStandardItem *> row;

            row.append(new QStandardItem(courant->cle));
            row.append(new QStandardItem(courant->val.type));
            row.append(new QStandardItem(courant->val.stand));
            row.append(new QStandardItem(QString::number(courant->val.nb_ch)));
            row.append(new QStandardItem(QString::number(courant->val.nb_bthl)));
            row.append(new QStandardItem(courant->val.descrip));

            model->appendRow(row);
            courant = courant->suiv;
        }
    }

    for (int row = 0; row < model->rowCount(); ++row) {
        for (int col = 0; col < model->columnCount(); ++col) {
            QStandardItem *item = model->item(row, col);
            item->setFlags(item->flags() & ~Qt::ItemIsEditable);
        }
    }

    tableView->setModel(model);
    tableView->resizeColumnsToContents();
}
//---------------


valeur* TableHachage::get(QString key, int i)
{
    //  si la cle se trouve dans la table de Hachage
    int index = -1;
    switch (i)
    {
    case 1:
        index = f1(key);
        break;
    case 2:
        index = f2(key);
        break;
    case 3:
        index = f3(key);
        break;
    case 4:
        index =fonctionSansHachage();
    }

    if (tab[index] == nullptr)
    {
        return nullptr;
    }
    else
    {
        Maison *courant = tab[index];
        while (courant != nullptr && courant->cle != key)
        {
            courant = courant->suiv;
        }
        if (courant)
        {
            return &courant->val;
        }
        else
        {
            return nullptr;
        }
    }
}

void TableHachage::vider()
{
    for (int i = 0; i < tailleMax; ++i) {
        Maison* courant = tab[i];
        while (courant) {
            Maison* temp = courant;
            courant = courant->suiv;
            delete temp;
        }
        tab[i] = nullptr;
    }
}

