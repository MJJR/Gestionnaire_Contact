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

void AjoutContact::on_testBtn_clicked()
{
    if(ui->rdoPrive->isChecked() == true)
    {
        Adresse a1("125, rue","Toulouse",36000); //TODO Recup donnés form && créer adresse

    }
    else
    {

    }

}



void AjoutContact::on_btnAjouter_clicked()
{
    QString nom = ui->txtNom->text();
    QString prenom = ui->txtPrenom->text();
    QString sexe = ui->cboSexe->currentText();
    QString libelle = ui->txtAdresse->text();
    QString complement = ui->txtComplement->text();
    int codePostal = ui->txtCodePostal->text().toInt();
    QString ville = ui->txtVille->text();


    if(ui->rdoPrive->isChecked() == true)
    {
        QString dateNaissance = ui->dateNaissance->date().toString("dd-MM-yyyy");
        Adresse a1(libelle,complement,ville,codePostal);
        if (a1.getErrorA() == VALIDE)
        {
            Contacts* c1 = new Prives(nom,prenom,'M',&a1,dateNaissance); //TODO Recup donnés form && créer Contact
            if (c1->getError() != VALIDE)
            {
                emit(erreur(c1->getError()));
            }
            else
            {
                insertPrive( c1->getNom(),c1->getPrenom(),
                             c1->getSexe(),c1->getAdresse()->getLibelle(),
                             c1->getAdresse()->getComplement(),
                             c1->getAdresse()->getVille(),
                             c1->getAdresse()->getCodePostal(),
                             dateNaissance);

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
            Contacts* c1 = new Professionnels(nom,prenom,'M',&a1,nomEntreprise, email); //TODO Recup donnés form && créer Contact
            c1->affiche();
            if (c1->getError() != VALIDE)
            {
                emit(erreur(c1->getError()));
            }
            else
            {
                insertPro( c1->getNom(),c1->getPrenom(),
                             c1->getSexe(),c1->getAdresse()->getLibelle(),
                             c1->getAdresse()->getComplement(),
                             c1->getAdresse()->getVille(),
                             c1->getAdresse()->getCodePostal(),
                             nomEntreprise,email);

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

bool AjoutContact::insertPro(QString nom , QString prenom ,
                           char sexe , QString libelle , QString complement ,
                           QString ville , int codePostal , QString nomEntreprise ,
                           QString email){

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("dbContacts.db");


    if (!db.isOpen())
    {
        db.open();
    }

    QSqlQuery query(db);

    QString test(" INSERT INTO Contacts( Nom , Prenom , Sexe , rue , Complement , Ville , cp , Entreprise , mail )"
                 "VALUES( :nom , :prenom , :sexe , :libelle , :complement , :ville , :codePostal , :nomEntreprise , :email );");

    query.prepare(test);

    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":sexe",QString(sexe));
    query.bindValue(":libelle",libelle);
    query.bindValue(":complement",complement);
    query.bindValue(":ville",ville);
    query.bindValue(":codePostal",codePostal);
    query.bindValue(":nomEntreprise",nomEntreprise);
    query.bindValue(":email",email);

    bool isValid = query.exec();

    if (db.isOpen())
    {
        db.close();
    }

    return isValid;

}

bool AjoutContact::insertPrive(QString nom, QString prenom,
                             char sexe, QString libelle, QString complement,
                             QString ville, int codePostal,
                             QString dateNaissance){

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("dbContacts.db");

    if (!db.isOpen())
    {
        db.open();
    }

    QSqlQuery query(db);

    QString test(" INSERT INTO Contacts( Nom , Prenom , Sexe , rue , Complement , Ville , cp , dtNaissance )"
                 "VALUES( :nom , :prenom , :sexe , :libelle , :complement , :ville , :codePostal , :dateNaissance );");

    query.prepare(test);

    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":sexe",QString(sexe));
    query.bindValue(":libelle",libelle);
    query.bindValue(":complement",complement);
    query.bindValue(":ville",ville);
    query.bindValue(":codePostal",codePostal);
    query.bindValue(":dateNaissance",dateNaissance);

    bool isValid = query.exec();

    if (db.isOpen())
    {
        db.close();
    }

    return isValid;
}
