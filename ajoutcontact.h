#ifndef AJOUTCONTACT_H
#define AJOUTCONTACT_H

#include <QDialog>
#include <QDebug>
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
