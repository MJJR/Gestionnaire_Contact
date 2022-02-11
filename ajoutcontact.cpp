#include "ajoutcontact.h"
#include "ui_ajoutcontact.h"

AjoutContact::AjoutContact(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjoutContact)
{
    ui->setupUi(this);

    if(ui->rdoPrive->isChecked() == true)
    {
        ui->grpPro->hide();
    }
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
