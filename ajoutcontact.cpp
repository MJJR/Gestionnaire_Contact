#include "ajoutcontact.h"
#include "ui_ajoutcontact.h"

#include <QMessageBox>


AjoutContact::AjoutContact(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjoutContact) //Affiche le formulaire de contact
{
    ui->setupUi(this);

    if(ui->rdoPrive->isChecked() == true)
    {
        ui->grpPro->hide();
    }
    connect(this,SIGNAL(erreur(int)),this,SLOT(onFormulaireError(int))); // Liaison du signal erreur qui prendre en valeur, l'erreur renvoyé par un setter des classes contacts,
                                                                         // à l'évenement qui fait apparaitre le message d'erreur
}

AjoutContact::~AjoutContact() //Destructor
{
    delete ui;
}

void AjoutContact::on_rdoProfessionnel_clicked() //Cache les infos de privé
{
    ui->grpPro->show();
    ui->lblDate->hide();
    ui->dateNaissance->hide();
}

void AjoutContact::on_rdoPrive_clicked()//Cache les infos de professionnel
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

void AjoutContact::on_btnAjouter_clicked() //Ajoute un contact à la base de donnée
{

    QString nom = ui->txtNom->text();
    QString prenom = ui->txtPrenom->text();
    QString libelle = ui->txtAdresse->text();
    QString complement = ui->txtComplement->text();
    int codePostal = ui->txtCodePostal->text().toInt();
    QString ville = ui->txtVille->text();
    char sexe;

    if(ui->cboSexe->currentIndex() == 1)//Vérrification du sexe
    {
        sexe = 'F';
    }else {
        sexe = 'M';
    }

    if(ui->rdoPrive->isChecked() == true)//Vérrification du type de contact a ajouter
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
                //Insertion du contact Prive dans la base de donnee
                bool ok =insertPrive( c1->getNom(),c1->getPrenom(),
                             c1->getSexe(),c1->getAdresse()->getLibelle(),
                             c1->getAdresse()->getComplement(),
                             c1->getAdresse()->getVille(),
                             c1->getAdresse()->getCodePostal(),
                             dateNaissance);
                //Si l'insertion dans la base s'est bien deroule alors on ferme la fenetre
                //Sinon on emet une erreur et on reste sur la fenetre
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
                //Insertion du contact Professionnel dans la base de donnee
                bool ok = insertPro( c1->getNom(),c1->getPrenom(),
                             c1->getSexe(),c1->getAdresse()->getLibelle(),
                             c1->getAdresse()->getComplement(),
                             c1->getAdresse()->getVille(),
                             c1->getAdresse()->getCodePostal(),
                             nomEntreprise,email);
                //Si l'insertion dans la base s'est bien deroule alors on ferme la fenetre
                //Sinon on emet une erreur et on reste sur la fenetre
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
}


bool AjoutContact::insertPro(QString nom , QString prenom ,
                           char sexe , QString libelle , QString complement ,
                           QString ville , int codePostal , QString nomEntreprise ,
                           QString email){

    //Ajout de la base de donnee "QSQLITE" dans la classe QSqlDatabase
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("dbContacts.db");

    //Ouverture de la base de donnee si ce n'est pas deja fait
    if (!db.isOpen())
    {
        db.open();
    }

    //Ecriture de la requete sql pour inserer un contact
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

    //Execution de la requete et on retorunera si la requete s'est bien deroule
    bool isValid = query.exec();

    //Fermeture de la base de donnee si la base de donnee est toujours ouverte
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

    //Ajout de la base de donnee "QSQLITE" dans la classe QSqlDatabase
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("dbContacts.db");

    //Ouverture de la base de donnee si ce n'est pas deja fait
    if (!db.isOpen())
    {
        db.open();
    }

    //Ecriture de la requete sql pour inserer un contact
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

    //Execution de la requete et on retorunera si la requete s'est bien deroule
    bool isValid = query.exec();

    //Fermeture de la base de donnee si la base de donnee est toujours ouverte
    if (db.isOpen())
    {
        db.close();
    }

    return isValid;
}


void AjoutContact::on_btnAnnuler_clicked() //Clear les lineEdits
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
