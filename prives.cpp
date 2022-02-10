#include "prives.h"

QString Prives::getSituation() const
{
    switch (this->situation)
    {
        case 'C': return "Célibataire";
        case 'M': return "Marié(e)";
        case 'D': return "Divorcé(e)";
        case 'X': return "Autre";
        default : return "Non renseigné";
    }
}

void Prives::setSituation(char newSituation)
{
    situation = newSituation;
}

const QString &Prives::getDateNaissance() const
{
    return dateNaissance;
}

void Prives::setDateNaissance(const QString &newDateNaissance)
{
    dateNaissance = newDateNaissance;
}

Prives::Prives(QString n, QString p, char s, Adresse a, char sit, QString d)
    :Contacts(n,p,s,a)
{
    this->setSituation(sit);
    this->setDateNaissance(d);
}

void Prives::affiche()
{
    qDebug() << "Contact privé: " << getNom() <<" "<< getPrenom() << ", situation: " << getSituation() << ", Adresse: " << getAdresse() << ", née le: " << getDateNaissance()<<"\n";
}
