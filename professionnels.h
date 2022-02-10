#ifndef PROFESSIONNELS_H
#define PROFESSIONNELS_H

#include <QString>
#include "contacts.h"
#include <QRegularExpression>


using namespace std;

class Professionnels : public Contacts
{

private:
    QString nomEntreprise;
    QString email;

public:
    Professionnels(QString, QString, char, Adresse*, QString, QString);
    void affiche() override;

    QString getEmail() const;
    void setEmail(const QString &value);

    QString getNomEntreprise() const;
    void setNomEntreprise(const QString &value);
};

#endif // PROFESSIONNELS_H
