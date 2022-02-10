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
    delete this->adresse;
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
    qDebug() << "Contact :"
           << "\nIdentifiant : "<< getId()
           << "\nNom : "<< getNom()
           << "\nPrenom : "<<getPrenom()
           << "\nSexe : "<< getSexe()
           << "\nAdresse : "<<adresse->getAdress();
}


