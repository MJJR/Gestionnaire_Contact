#include "ajoutcontact.h"
#include "ui_ajoutcontact.h"

AjoutContact::AjoutContact(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjoutContact)
{
    ui->setupUi(this);
}

AjoutContact::~AjoutContact()
{
    delete ui;
}
