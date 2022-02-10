#ifndef CONTACTS_H
#define CONTACTS_H

#include <QString>



class Contacts
{
private:
    int id;

protected:
    Contacts();
    Contacts(QString,QString,char,QString);
    virtual ~Contacts();


    QString nom;
    QString prenom;
    char sexe;
    QString adresse;

    static int nbContact;


public:
    int getId() const;
    QString getNom() const;
    void setNom(const QString &value);
    QString getPrenom() const;
    void setPrenom(const QString &value);
    char getSexe() const;
    void setSexe(char value);
    QString getAdresse() const;
    void setAdresse(const QString &value);

    virtual void affiche();

};

#endif // CONTACTS_H
