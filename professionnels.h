#ifndef PROFESSIONNELS_H
#define PROFESSIONNELS_H

#include <QString>
#include "Contacts.h"

class Professionnels : public Contacts
{

private:
    QString nomEntreprise;
    QString email;

public:
    Professionnels();
    ~Professionnels() override;
    void affiche() override;

    QString getEmail() const;
    void setEmail(const QString &value);

    QString getNomEntreprise() const;
    void setNomEntreprise(const QString &value);
};

#endif // PROFESSIONNELS_H
