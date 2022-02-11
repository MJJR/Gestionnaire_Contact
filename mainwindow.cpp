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



void MainWindow::on_choiceContact()
{
    qDebug() << "Police !!!";

        //sender() : élément déclencheur

        qDebug() << "sender() : élément déclencheur " <<  sender()->objectName();

        QAbstractButton *rb = dynamic_cast<QAbstractButton*>(sender());

        if(rb != nullptr)
        {
            qDebug() << rb->text();
        }
}
