#ifndef PRIVES_H
#define PRIVES_H

#include <QString>
#include "contacts.h"
#include <QDebug>

class Prives : public Contacts
{
private:
    QString dateNaissance;


public:
    Prives(QString,QString,char,Adresse*,/*char,*/QString);

    void affiche() override;

    const QString &getDateNaissance() const;
    void setDateNaissance(const QString &newDateNaissance);
};

#endif // PRIVES_H
