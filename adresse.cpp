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
    //Expression régulière pour vérifier si le code postal français est valide
    QRegExp testCP("^(([0-8][0-9])|(9[0-5])|(2[ab]))[0-9]{3}$");
    if(testCP.exactMatch(QString::number(newCodePostal))){
        codePostal = newCodePostal;
        qDebug() << "\nCode Postal Valide !\n";
    }
    else{
        qDebug() << "\nCode Postal Non Valide !\n";
    }

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


