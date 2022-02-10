#include "professionnels.h"

QString Professionnels::getEmail() const
{
    return email;
}

void Professionnels::setEmail(const QString &value)
{
    email = value;
}

QString Professionnels::getNomEntreprise() const
{
    return nomEntreprise;
}

void Professionnels::setNomEntreprise(const QString &value)
{
    nomEntreprise = value;
}

Professionnels::Professionnels(QString nom, QString prenom, char sexe, Adresse* adresse, QString nEntreprise, QString email)
    :Contacts(nom,prenom,sexe,adresse)
{
    this->setNomEntreprise(nEntreprise);
    this->setEmail(email);
}

void Professionnels::affiche()
{

    qDebug() << "Contact professionnel :" << getNom() << " " << getPrenom() << ", Adresse :" << getAdresse()
             << ", Nom Entreprise:" << getNomEntreprise() << ", email" << getEmail() << endl;
}

