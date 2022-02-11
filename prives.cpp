#include "prives.h"


const QString &Prives::getDateNaissance() const
{
    return dateNaissance;
}

void Prives::setDateNaissance(const QString &newDateNaissance)
{
       QRegularExpression testCP("^(0[1-9]|[12][0-9]|3[01])[- /.](0[1-9]|1[012])[- /.](19|20)\\d\\d$");
       if(testCP.match(newDateNaissance).hasMatch()){
           dateNaissance = newDateNaissance;
       }
       else{
        error=DATE;
       }

}

Prives::Prives(QString n, QString p, char s, Adresse* a, QString d)
    :Contacts(n,p,s,a)
{
    this->setDateNaissance(d);
}

void Prives::affiche()
{
    qDebug() << "Contact privé: "<< getNom() <<" "<< getPrenom() <<"\nSexe: "<<getSexe() /*<< "\nSituation: " << getSituation()*/ << "\nAdresse: " << adresse->getAdress() << "\nNée le: " << getDateNaissance()<<"\n";
}



