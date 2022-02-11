#include "professionnels.h"

QString Professionnels::getEmail() const
{
    return email;
}

void Professionnels::setEmail(const QString &value)
{

    //Expression régulière pour vérifier si le code postal français est valide
    QRegularExpression testCP("^[^@\\s]+@[^@\\s]+\\.[^@\\s]+$");
    if(testCP.match(value).hasMatch()){
        email = value;
    }
    else{
        error=MAIL;
    }
}

QString Professionnels::getNomEntreprise() const
{
    return nomEntreprise;
}

void Professionnels::setNomEntreprise(const QString &value)
{
    if(value.size() > 50)
    {
      error=ENTR;

    }else {
        nomEntreprise = value.toUpper();
    }
}

Professionnels::Professionnels(QString nom, QString prenom, char sexe, Adresse* adresse, QString nEntreprise, QString email)
    :Contacts(nom,prenom,sexe,adresse)
{
    this->setNomEntreprise(nEntreprise);
    this->setEmail(email);
}

void Professionnels::affiche()
{

    qDebug() << "Contact professionnel :" << getNom() << " " << getPrenom() << "\nAdresse : " << adresse->getAdress() <<"\nSexe: " << getSexe()
             << "\nNom Entreprise: " << getNomEntreprise() << "\nEmail: " << getEmail() << "\n";
}

