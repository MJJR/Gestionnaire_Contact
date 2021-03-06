#ifndef CONTACTS_H
#define CONTACTS_H

#include <QString>
#include <QDebug>
#include "adresse.h"

class Contacts
{
private:
    int id;
    static int nbContact;

protected:
    QString nom;
    QString prenom;
    char sexe;
    Adresse* adresse;
    int error=VALIDE;


public:
    Contacts();
    Contacts(QString,QString,char,Adresse*);
    virtual ~Contacts();


    int getId() const;
    QString getNom() const;
    void setNom(const QString &value);
    QString getPrenom() const;
    void setPrenom(const QString &value);
    char getSexe() const;
    void setSexe(char value);
    Adresse* getAdresse() const;
    void setAdresse( Adresse* &value);
    int getError() const;

    virtual void affiche();

};

#endif // CONTACTS_H
