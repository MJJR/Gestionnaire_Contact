#ifndef PRIVES_H
#define PRIVES_H

#include <QString>
#include "Contacts.h"



class Prives : public Contacts
{
private:
    char situation;
    QString dateNaissance;


public:
    Prives();
    void affiche() override;


    char getSituation() const;
    void setSituation(char newSituation);

    const QString &getDateNaissance() const;
    void setDateNaissance(const QString &newDateNaissance);
};

#endif // PRIVES_H
