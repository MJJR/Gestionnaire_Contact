#include "contacts.h"

int Contacts::nbContact = 1;

Contacts::Contacts()
{

}

Contacts::Contacts(QString vNom,QString vPrenom,char vSexe,Adresse* vAdresse)
{
    setNom(vNom);
    setPrenom(vPrenom);
    setSexe(vSexe);
    setAdresse(vAdresse);
    this->id= Contacts::nbContact;
    Contacts::nbContact ++;
}

Contacts::~Contacts()
{
    qDebug() << "Destruction du contact " << this->id <<"\n";
}

int Contacts::getId() const
{
    return id;
}

Adresse* Contacts::getAdresse() const
{
    return this->adresse;
}

void Contacts::setAdresse(Adresse* &value)
{
    adresse = value;
}

char Contacts::getSexe() const
{
    return sexe;
}

void Contacts::setSexe(char value)
{
    //TODO REGEX
    QRegularExpression testSX("[M|F]{1}");
    if(testSX.match(QString(value)).hasMatch()){
        sexe = value;
    }
    else{
     qDebug() << "Invalide Sexe" ;
    }

}

QString Contacts::getPrenom() const
{
    return prenom;
}

void Contacts::setPrenom(const QString &value)
{
    //TODO REGEX
    QRegularExpression testPr("^[A-Z]{1}[a-z]*");
    if(testPr.match(value).hasMatch()){
        prenom = value;
    }
    else{
     error=PRENOM;
    }

}

QString Contacts::getNom() const
{
    return nom;
}

void Contacts::setNom(const QString &value)
{
    //TODO REGEX
    QRegularExpression testNm("[A-Z]+|[a-z]+");
    if(testNm.match(value).hasMatch()){
        nom = value.toUpper();
    }
    else{
     error=NOM;
    }

}

int Contacts::getError() const
{
    return error;
}


void Contacts::affiche()
{
    qDebug() << "Contact :"
           << "\nIdentifiant : "<< getId()
           << "\nNom : "<< getNom()
           << "\nPrenom : "<<getPrenom()
           << "\nSexe : "<< getSexe()
           << "\nAdresse : "<<adresse->getAdress();
}


