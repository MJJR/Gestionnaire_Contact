#ifndef AJOUTCONTACT_H
#define AJOUTCONTACT_H

#include <QDialog>

namespace Ui {
class AjoutContact;
}

class AjoutContact : public QDialog
{
    Q_OBJECT

public:
    explicit AjoutContact(QWidget *parent = nullptr);
    ~AjoutContact();

private:
    Ui::AjoutContact *ui;
};

#endif // AJOUTCONTACT_H
