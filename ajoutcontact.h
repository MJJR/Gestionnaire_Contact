#ifndef AJOUTCONTACT_H
#define AJOUTCONTACT_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class AjoutContact;
}

class AjoutContact : public QDialog
{
    Q_OBJECT

public:
    explicit AjoutContact(QWidget *parent = nullptr);
    ~AjoutContact();

private slots:

    void on_rdoProfessionnel_clicked();

    void on_rdoPrive_clicked();

private:
    Ui::AjoutContact *ui;
};

#endif // AJOUTCONTACT_H
