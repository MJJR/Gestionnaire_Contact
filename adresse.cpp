#include "adresse.h"

const QString &Adresse::getLibelle() const
{
    return libelle;
}

void Adresse::setLibelle(const QString &newLibelle)
{
    libelle = newLibelle;
}

const QString &Adresse::getComplement() const
{
    return complement;
}

void Adresse::setComplement(const QString &newComplement)
{
    complement = newComplement;
}

const QString &Adresse::getVille() const
{
    return ville;
}

void Adresse::setVille(const QString &newVille)
{
    ville = newVille;
}

int Adresse::getCodePostal() const
{
    return codePostal;
}

void Adresse::setCodePostal(int newCodePostal)
{
    codePostal = newCodePostal;
}

Adresse::Adresse(QString l, QString v, int c)
{
    this->setLibelle(l);
    this->setVille(v);
    this->setCodePostal(c);
}

Adresse::Adresse(QString l, QString comp, QString v, int c)
{
    this->setLibelle(l);
    this->setComplement(comp);
    this->setVille(v);
    this->setCodePostal(c);
}

QString Adresse::getAdress()
{
    return "Adresse: "+getLibelle()+ " "+getComplement()+" "+getVille()+" "+QString::number(getCodePostal());
}


