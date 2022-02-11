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
    connect(this,SIGNAL(erreur(int)),this,SLOT(onFormulaireError(int))); // Liaison du signal erreur qui prendre en valeur, l'erreur renvoyé par un setter des classes contacts,
                                                                         // à l'évenement qui fait apparaitre le message d'erreur
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

void AjoutContact::onFormulaireError(int e) //Affiche un message d'erreur en fonction de la valeur de l'erreur
{
    QMessageBox msgBox(this);
    msgBox.setWindowTitle("Erreur saisie");
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

        case SQL:
        msgBox.setText("Erreur SQL");
        break;

        case POST:
        msgBox.setText("Erreur code postal");
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
            Contacts* c1 = new Prives(nom,prenom,sexe,&a1,dateNaissance);
            if (c1->getError() != VALIDE)
            {
                emit(erreur(c1->getError())); //Envoie le signal d'erreur en cas d'erreur dans la création de notre Contact
            }
            else
            {
                bool ok =insertPrive( c1->getNom(),c1->getPrenom(),
                             c1->getSexe(),c1->getAdresse()->getLibelle(),
                             c1->getAdresse()->getComplement(),
                             c1->getAdresse()->getVille(),
                             c1->getAdresse()->getCodePostal(),
                             dateNaissance);
                if (ok) this->accept();
                else  emit(erreur(SQL)); //Envoie le signal d'erreur en cas d'erreur dans la requete SQL
            }
            delete c1;
        }
        else
        {
             emit(erreur(a1.getErrorA())); //Envoie le signal d'erreur en cas d'erreur dans la création de notre adresse
        }

    }else {
        QString nomEntreprise = ui->txtNomEntreprise->text();
        QString email = ui->txtEmail->text();

        Adresse a1(libelle,complement,ville,codePostal);
        if (a1.getErrorA() == VALIDE)
        {
            Contacts* c1 = new Professionnels(nom,prenom,sexe,&a1,nomEntreprise, email);
            if (c1->getError() != VALIDE)
            {
                emit(erreur(c1->getError())); //Envoie le signal d'erreur en cas d'erreur dans la création de notre Contact
            }
            else
            {
               bool ok = insertPro( c1->getNom(),c1->getPrenom(),
                             c1->getSexe(),c1->getAdresse()->getLibelle(),
                             c1->getAdresse()->getComplement(),
                             c1->getAdresse()->getVille(),
                             c1->getAdresse()->getCodePostal(),
                             nomEntreprise,email);
                if (ok) this->accept();
                else  emit(erreur(SQL)); //Envoie le signal d'erreur en cas d'erreur dans la requete SQL
            }
            delete c1;
        }
        else
        {
             emit(erreur(a1.getErrorA())); //Envoie le signal d'erreur en cas d'erreur dans la création de notre adresse
        }


    }
    //
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
