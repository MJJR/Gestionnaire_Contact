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
    model->setHeaderData(2,Qt::Horizontal, "Sexe");
    model->setHeaderData(3,Qt::Horizontal, "Entreprise");
    model->setHeaderData(4,Qt::Horizontal, "Libellé");
    model->setHeaderData(5,Qt::Horizontal, "Complément");
    model->setHeaderData(6,Qt::Horizontal, "Code Postal");
    model->setHeaderData(7,Qt::Horizontal, "Ville");
    model->setHeaderData(8,Qt::Horizontal, "Mail de Contact");
    model->setHeaderData(9,Qt::Horizontal, "Date de Naissance");
    model->setHeaderData(10,Qt::Horizontal, "Prénom");

    ui->tableView->setModel(model);


}

MainWindow::~MainWindow()
{
    delete ui;
    delete model;
}
