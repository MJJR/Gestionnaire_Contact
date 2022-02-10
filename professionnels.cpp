#include "professionnels.h"

QString Professionnels::getEmail() const
{
    return email;
}

void Professionnels::setEmail(const QString &value)
{
    email = value;
}

QString Professionnels::getNomEntreprise() const
{
    return nomEntreprise;
}

void Professionnels::setNomEntreprise(const QString &value)
{
    nomEntreprise = value;
}

Professionnels::Professionnels()
{

}
