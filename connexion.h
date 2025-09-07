/*#ifndef CONNEXION_H
#define CONNEXION_H

#include<QSqlDatabase>
#include<QSqlQuery>
#include<QDebug>
#include <qfile.h>
static bool connexionPOO()
{
    if (QSqlDatabase::contains("qt_sql_default_connection"))
    {
        QSqlDatabase::removeDatabase("qt_sql_default_connection");
    }
    QSqlDatabase con= QSqlDatabase::addDatabase("QSQLITE");
    con.setDatabaseName("C:/sqlite/RAM_SOCIETY.db");
    QFile dbFile("C:/sqlite/RAM_SOCIETY.db");
    if (!dbFile.exists()) {
        qDebug() << "La base n'existe pas. Connexion interdite.";
        return false;
    }

    if(con.open())
    {
        qDebug()<<"Bravo";
        return true;
    }
    else
    {
        qDebug()<<"Erreur";
        return false;
    }
}

#endif*/ // CONNEXION_H

#ifndef CONNEXION_H
#define CONNEXION_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QFile>

static bool connexionPOO()
{
    if (QSqlDatabase::contains("maConnexion"))
    {
        QSqlDatabase::removeDatabase("maConnexion");
    }

    QSqlDatabase con = QSqlDatabase::addDatabase("QSQLITE", "maConnexion");
    con.setDatabaseName("C:/sqlite/RAM_SOCIETY.db");

    QFile dbFile("C:/sqlite/RAM_SOCIETY.db");
    if (!dbFile.exists()) {
        qDebug() << "La base n'existe pas. Connexion interdite.";
        return false;
    }

    if (con.open()) {
        qDebug() << "Connexion ouverte avec succès";
        return true;
    } else {
        qDebug() << "Erreur d'ouverture de la base:" << con.lastError().text();
        return false;
    }
}

#endif // CONNEXION_H
