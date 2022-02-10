#ifndef ADRESSE_H
#define ADRESSE_H

#include <QString>

class Adresse
{
private:
    QString libelle;
    QString complement;
    QString ville;
    int codePostal;


public:
    Adresse(QString,QString,int);
    Adresse(QString,QString,QString,int);

    QString getAdress();
    const QString &getLibelle() const;
    void setLibelle(const QString &newLibelle);
    const QString &getComplement() const;
    void setComplement(const QString &newComplement);
    const QString &getVille() const;
    void setVille(const QString &newVille);
    int getCodePostal() const;
    void setCodePostal(int newCodePostal);
};

#endif // ADRESSE_H
