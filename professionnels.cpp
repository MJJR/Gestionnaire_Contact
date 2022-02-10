#include "professionnels.h"

QString Professionnels::getEmail() const
{
    return email;
}

void Professionnels::setEmail(const QString &value)
{

    //Expression régulière pour vérifier si le code postal français est valide
    QRegExp testCP("^[^@\\s]+@[^@\\s]+\\.[^@\\s]+$");
    QString codePostalString (value);
    if(testCP.exactMatch(codePostalString)){
        email = value;
    }
    else{
        email = "default.email@gmail.com";
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
        //Implementer la gestion de l'erreur
        qDebug() << "Error Nom de l'entreprise trop long !!!";
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

