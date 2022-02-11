#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSqlDatabase>
#include <QSqlTableModel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
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



