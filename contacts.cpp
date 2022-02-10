#include "contacts.h"

Contacts::Contacts()
{

}

Contacts::~Contacts()
{

}

QString Contacts::getAdresse() const
{
    return adresse;
}

void Contacts::setAdresse(const QString &value)
{
    adresse = value;
}

bool Contacts::getSexe() const
{
    return sexe;
}

void Contacts::setSexe(bool value)
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

int Contacts::getId() const
{
    return id;
}

void Contacts::setId(int value)
{
    id = value;
}

void Contacts::affiche()
{

}


