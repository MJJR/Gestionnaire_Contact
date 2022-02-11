#include "prives.h"


/*QString Prives::getSituation() const
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
}*/

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
        qDebug() << "Invalide date naissance" ;
       }

}

Prives::Prives(QString n, QString p, char s, Adresse* a,/* char sit,*/ QString d)
    :Contacts(n,p,s,a)
{
   /* this->setSituation(sit);*/
    this->setDateNaissance(d);
}

void Prives::affiche()
{
    qDebug() << "Contact privé: "<< getNom() <<" "<< getPrenom() <<"\nSexe: "<<getSexe() /*<< "\nSituation: " << getSituation()*/ << "\nAdresse: " << adresse->getAdress() << "\nNée le: " << getDateNaissance()<<"\n";
}
