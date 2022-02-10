#ifndef CONTACTS_H
#define CONTACTS_H

#include <QString>



class Contacts
{
protected:
    Contacts();
    int id;
    QString nom;
    QString prenom;
    bool sexe;
    QString adresse;

public:
    int getId() const;
    void setId(int value);
    QString getNom() const;
    void setNom(const QString &value);
    QString getPrenom() const;
    void setPrenom(const QString &value);
    bool getSexe() const;
    void setSexe(bool value);
    QString getAdresse() const;
    void setAdresse(const QString &value);

    virtual void affiche();
};

#endif // CONTACTS_H
