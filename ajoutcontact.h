#ifndef AJOUTCONTACT_H
#define AJOUTCONTACT_H

#include <QDialog>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>

#include "prives.h"
#include "adresse.h"
#include "professionnels.h"

#include "professionnels.h"
#include "prives.h"
#include "adresse.h"

namespace Ui {
class AjoutContact;
}

class AjoutContact : public QDialog
{
    Q_OBJECT

public:
    explicit AjoutContact(QWidget *parent = nullptr);
    ~AjoutContact();

    bool insertPro(QString nom, QString prenom, char sexe, QString libelle, QString complement, QString ville, int codePostal, QString nomEntreprise, QString email);
    bool insertPrive(QString nom, QString prenom, char sexe, QString libelle, QString complement, QString ville, int codePostal, QString dateNaissance);


private slots:

    void on_rdoProfessionnel_clicked();

    void on_rdoPrive_clicked();

    void on_btnAjouter_clicked();

private:
    Ui::AjoutContact *ui;

private slots:
    void onFormulaireError(int);

    void on_testBtn_clicked();

signals:
    void erreur(int);
};

#endif // AJOUTCONTACT_H
