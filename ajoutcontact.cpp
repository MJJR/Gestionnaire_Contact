#include "ajoutcontact.h"
#include "ui_ajoutcontact.h"

#include <QMessageBox>


AjoutContact::AjoutContact(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjoutContact)
{
    ui->setupUi(this);

    if(ui->rdoPrive->isChecked() == true)
    {
        ui->grpPro->hide();
    }
    connect(this,SIGNAL(erreur(int)),this,SLOT(onFormulaireError(int)));
}

AjoutContact::~AjoutContact()
{
    delete ui;
}

void AjoutContact::on_rdoProfessionnel_clicked()
{
    ui->grpPro->show();
    ui->lblDate->show();
    ui->dateNaissance->show();
}

void AjoutContact::on_rdoPrive_clicked()
{
    ui->grpPro->hide();
    ui->lblDate->hide();
    ui->dateNaissance->hide();
}

void AjoutContact::onFormulaireError(int e)
{
    QMessageBox msgBox(this);
    msgBox.setIcon(QMessageBox::Critical);
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);
    switch (e)
    {
        case MAIL:
        msgBox.setText("Adresse mail invalide");
        break;

        case LIBELLE:
        msgBox.setText("Libelle invalide");
        break;

        case VILLE:
        msgBox.setText("Ville invalide");
        break;

        case PRENOM:
        msgBox.setText("Prenom invalide");
        break;

        case NOM:
        msgBox.setText("Nom invalide");
        break;

        case DATE:
        msgBox.setText("Date invalide");
        break;

        case ENTR:
        msgBox.setText("Nom entreprise invalide");
        break;
    }
    msgBox.exec();
}

void AjoutContact::on_testBtn_clicked()
{
    if(ui->rdoPrive->isChecked() == true)
    {
        Adresse a1("125, rue","Toulouse",36000); //TODO Recup donnés form && créer adresse
        if (a1.getErrorA() == VALIDE)
        {
            Contacts* p1= new Prives("Jean","Phillipe",'F',&a1,"13/09/1955"); //TODO Recup donnés form && créer Contact
            if (p1->getError() != VALIDE)
            {
                emit(erreur(p1->getError()));
            }
            else
            {
                //TODO SQL
            }
            delete p1;
        }
        else
        {
             emit(erreur(a1.getErrorA()));
        }

    }
    else
    {
        Adresse a1("125, rue","Toulouse",36000); //TODO Recup donnés form && créer adresse
        if (a1.getErrorA() == VALIDE)
        {
            Contacts* p1= new Professionnels("Jean","Phillipe",'F',&a1,"Abylsen","jean@jean.com"); //TODO Recup donnés form && créer Contact
            if (p1->getError() != VALIDE)
            {
                emit(erreur(p1->getError()));
            }
            else
            {
                //TODO SQL
            }
            delete p1;
        }
        else
        {
             emit(erreur(a1.getErrorA()));
        }
    }

}

