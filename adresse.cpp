#include "adresse.h"

const QString &Adresse::getLibelle() const
{
    return libelle;
}

void Adresse::setLibelle(const QString &newLibelle)
{
    //TODO Expr Reg
    QRegularExpression testLibelle("^[0-9]{1,}.*");
    if(testLibelle.match( newLibelle ).hasMatch()){
        libelle = newLibelle;
    }
    else{
     errorA=LIBELLE;
    }
}

const QString &Adresse::getComplement() const
{
    return complement;
}

void Adresse::setComplement(const QString &newComplement)
{
    // A priori pas de test avec des expr reg ici

    complement = newComplement;
}

const QString &Adresse::getVille() const
{
    return ville;
}

void Adresse::setVille(const QString &newVille)
{

    QRegularExpression testVille("^[a-zA-Z]+(?:[\s-][a-zA-Z]+)*$");
    if(testVille.match( newVille ).hasMatch()){
        ville = newVille;
    }
    else{
     errorA=VILLE;
    }

}

int Adresse::getCodePostal() const
{
    return codePostal;
}

void Adresse::setCodePostal(int newCodePostal)
{
    //Expression régulière pour vérifier si le code postal français est valide
    QRegularExpression testCP("^(([0-8][0-9])|(9[0-5])|(2[ab]))[0-9]{3}$");
    if(testCP.match(QString::number(newCodePostal)).hasMatch()){
        codePostal = newCodePostal;
        qDebug() << "\nCode Postal Valide !\n";
    }
    else{
        qDebug() << "\nCode Postal Non Valide !\n";
    }

}

int Adresse::getErrorA() const
{
    return errorA;
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


