#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ajoutcontact.h"

#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QCloseEvent>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("dbContacts.db");

    model = new QSqlTableModel();

    model->setTable("contacts");
    model->select();

    model->setHeaderData(0,Qt::Horizontal, "Identifiant");
    model->setHeaderData(1,Qt::Horizontal, "Nom");
    model->setHeaderData(2,Qt::Horizontal, "Prenom");
    model->setHeaderData(3,Qt::Horizontal, "Sexe");
    model->setHeaderData(4,Qt::Horizontal, "Entreprise");
    model->setHeaderData(5,Qt::Horizontal, "Libellé");
    model->setHeaderData(6,Qt::Horizontal, "Complément");
    model->setHeaderData(7,Qt::Horizontal, "Code Postal");
    model->setHeaderData(8,Qt::Horizontal, "Ville");
    model->setHeaderData(9,Qt::Horizontal, "Mail de Contact");
    model->setHeaderData(10,Qt::Horizontal, "Date de Naissance");


    ui->tableView->setModel(model);

    row = model->rowCount();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete model;
}

void MainWindow::on_radioPro_pressed()
{
    for (int i=0; i<row; i++)
    {
        ui->tableView->showRow(i);
    }
    ui->tableView->showColumn(9);
    ui->tableView->showColumn(4);
    auto index = model->index(0,4);
    for (int i=0; i<row; i++)
    {
        index = model->index(i,4);
        if (index.data() == "")
        {
            ui->tableView->hideRow(i);
        }
        else
        {
            ui->tableView->hideColumn(10);
        }
    }
}


void MainWindow::on_RadioPriv_pressed()
{
    for (int i=0; i<row; i++)
    {
        ui->tableView->showRow(i);
    }
    ui->tableView->showColumn(10);
    auto index = model->index(0,10);
    for (int i=0; i<row; i++)
    {
        index = model->index(i,10);
        if (index.data() == "")
        {
            ui->tableView->hideRow(i);
        }
        else
        {
            ui->tableView->hideColumn(9);
            ui->tableView->hideColumn(4);
        }
    }
}



void MainWindow::on_radioAll_pressed()
{
    for (int i=0; i<row; i++)
    {
        ui->tableView->showRow(i);
    }
    ui->tableView->showColumn(10);
    ui->tableView->showColumn(9);
    ui->tableView->showColumn(4);
}


void MainWindow::on_actionFermer_triggered()
{
    this->close();
}

void MainWindow::closeEvent(QCloseEvent * eventClose)
{
    QMessageBox msgBox(this);
    msgBox.setText("Voulez vous Quitter ?");
    msgBox.setInformativeText("Quitter ?");
    msgBox.setIcon(QMessageBox::Question);
    msgBox.setStandardButtons(QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Cancel);

    int reponse = msgBox.exec();

    switch(reponse)
    {
        case QMessageBox::Yes:
            eventClose->accept();
            break;
        default:
            eventClose->ignore();
            break;
    }
}
void MainWindow::on_rechercheBtn_clicked()
{
    for (int i=0; i<row; i++)
    {
        ui->tableView->showRow(i);
    }
    ui->tableView->showColumn(10);
    ui->tableView->showColumn(9);
    ui->tableView->showColumn(4);
    auto index = model->index(0,1);
    for (int i=0; i<row; i++)
    {
        index = model->index(i,1);
        if (index.data() != ui->rechercheEdit->text().toUpper())
        {
            ui->tableView->hideRow(i);
        }
    }
}


void MainWindow::on_rechercheCancl_clicked()
{
    for (int i=0; i<row; i++)
    {
        ui->tableView->showRow(i);
    }
    ui->tableView->showColumn(10);
    ui->tableView->showColumn(9);
    ui->tableView->showColumn(4);
}


void MainWindow::on_ajouterContact_triggered()
{
    AjoutContact ajoutContact;

    ajoutContact.exec();
}

/*
 * //TEST DES REQUETES
void MainWindow::on_pushButton_clicked()
{

    if(insertPro(43,"LOL","Juju", 'F',"-1, rue negatif","c'est negatif, quoi", "kekpar", 1001, "CSerieuOuais", "darkJujudu35@gogol.fr"))
        qDebug()<<"Insertion Pro est passe";
    else
        qDebug()<<"Insertion Pro invalide";

}

void MainWindow::on_pushButton_2_clicked()
{
    if(insertPrive(44,"OUI","Jaja", 'M',"-2, rue negatif","c'est negatif, comme mon QI", "kekpar", 1001, "02/02/2002"))
        qDebug()<<"Insertion Prive est passe";
    else
        qDebug()<<"Insertion Prive invalide";
}
*/

bool MainWindow::insertPro(int id , QString nom , QString prenom ,
                           char sexe , QString libelle , QString complement ,
                           QString ville , int codePostal , QString nomEntreprise ,
                           QString email){

    if (!db.isOpen())
    {
        db.open();
    }

    QSqlQuery query(db);

    QString test(" INSERT INTO Contacts( IDContact , Nom , Prenom , Sexe , rue , Complement , Ville , cp , Entreprise , mail )"
                 "VALUES( :id , :nom , :prenom , :sexe , :libelle , :complement , :ville , :codePostal , :nomEntreprise , :email );");

    query.prepare(test);

    query.bindValue(":id",id);
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

bool MainWindow::insertPrive(int id, QString nom, QString prenom,
                             char sexe, QString libelle, QString complement,
                             QString ville, int codePostal,
                             QString dateNaissance){
    if (!db.isOpen())
    {
        db.open();
    }

    QSqlQuery query(db);

    QString test(" INSERT INTO Contacts( IDContact , Nom , Prenom , Sexe , rue , Complement , Ville , cp , dtNaissance )"
                 "VALUES( :id , :nom , :prenom , :sexe , :libelle , :complement , :ville , :codePostal , :dateNaissance );");

    query.prepare(test);

    query.bindValue(":id",id);
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


