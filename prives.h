#ifndef PRIVES_H
#define PRIVES_H

#include <QString>
#include "contacts.h"
#include <QDebug>




class Prives : public Contacts
{
private:
    /*char situation;*/
    QString dateNaissance;


public:
    Prives(QString,QString,char,Adresse*,/*char,*/QString);

    void affiche() override;


   /* QString getSituation() const;
    void setSituation(char newSituation);*/

    const QString &getDateNaissance() const;
    void setDateNaissance(const QString &newDateNaissance);
};

#endif // PRIVES_H
