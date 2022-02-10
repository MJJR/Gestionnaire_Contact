#include "contacts.h"

int Contacts::nbContact = 1;

Contacts::Contacts()
{

}

Contacts::Contacts(QString vNom,QString vPrenom,char vSexe,QString vAdresse)
{
    setNom(vNom);
    setPrenom(vPrenom);
    setSexe(vSexe);
    setAdresse(vAdresse);
    this->id=nbContact;
    Contacts::nbContact ++;
}

Contacts::~Contacts()
{

}

int Contacts::getId() const
{
    return id;
}

QString Contacts::getAdresse() const
{
    return adresse;
}

void Contacts::setAdresse(const QString &value)
{
    adresse = value;
}

char Contacts::getSexe() const
{
    return sexe;
}

void Contacts::setSexe(char value)
{
    sexe = value;
}

QString Contacts::getPrenom() const
{
    return prenom;
}

void Contacts::setPrenom(const QString &value)
{
    prenom = value;
}

QString Contacts::getNom() const
{
    return nom;
}

void Contacts::setNom(const QString &value)
{
    nom = value;
}


void Contacts::affiche()
{

}


