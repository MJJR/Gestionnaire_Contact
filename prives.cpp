#include "prives.h"

char Prives::getSituation() const
{
    return situation;
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

Prives::Prives()
{

}

void Prives::affiche()
{

}
