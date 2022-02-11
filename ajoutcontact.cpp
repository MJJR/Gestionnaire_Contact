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
    ui->lblDate->hide();
    ui->dateNaissance->hide();
}

void AjoutContact::on_rdoPrive_clicked()
{
    ui->grpPro->hide();
    ui->lblDate->show();
    ui->dateNaissance->show();
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

void AjoutContact::on_btnAjouter_clicked()
{

    QString nom = ui->txtNom->text();
    QString prenom = ui->txtPrenom->text();
    QString libelle = ui->txtAdresse->text();
    QString complement = ui->txtComplement->text();
    int codePostal = ui->txtCodePostal->text().toInt();
    QString ville = ui->txtVille->text();
    char sexe;

    if(ui->cboSexe->currentIndex() == 1)
    {
        sexe = 'F';
    }else {
        sexe = 'M';
    }

    if(ui->rdoPrive->isChecked() == true)
    {
        QString dateNaissance = ui->dateNaissance->date().toString("dd-MM-yyyy");
        Adresse a1(libelle,complement,ville,codePostal);
        if (a1.getErrorA() == VALIDE)
        {
            Contacts* c1 = new Prives(nom,prenom,sexe,&a1,dateNaissance); //TODO Recup donnés form && créer Contact
            c1->affiche();
            if (c1->getError() != VALIDE)
            {
                emit(erreur(c1->getError()));
            }
            else
            {
                //TODO SQL
            }
            delete c1;
        }
        else
        {
             emit(erreur(a1.getErrorA()));
        }

    }else {
        QString nomEntreprise = ui->txtNomEntreprise->text();
        QString email = ui->txtEmail->text();

        Adresse a1(libelle,complement,ville,codePostal); //TODO Recup donnés form && créer adresse
        if (a1.getErrorA() == VALIDE)
        {
            Contacts* c1 = new Professionnels(nom,prenom,sexe,&a1,nomEntreprise, email); //TODO Recup donnés form && créer Contact
            c1->affiche();
            if (c1->getError() != VALIDE)
            {
                emit(erreur(c1->getError()));
            }
            else
            {
                //TODO SQL
            }
            delete c1;
        }
        else
        {
             emit(erreur(a1.getErrorA()));
        }


    }
    //this->accept();
}

void AjoutContact::on_btnAnnuler_clicked()
{
    ui->txtNom->clear();
    ui->txtPrenom->clear();
    ui->txtAdresse->clear();
    ui->txtComplement->clear();
    ui->txtCodePostal->clear();
    ui->txtVille->clear();
    ui->txtNomEntreprise->clear();
    ui->txtEmail->clear();
}
