#include "mainwindow.h"
#include <QApplication>
#include "professionnels.h"
#include "prives.h"
#include "adresse.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Adresse* a1 = new Adresse("126 rue jean mermoz","Toulouse", 31000);
    Contacts * p1 = new Prives("Jean","Michel",'M',a1,'C',"12/11/1985");
    Contacts * p2 = new Professionnels("Jean","Michel",'M',a1,"Abylsen","abylsen@gmail.com");

    p1->affiche();
    p2->affiche();

    delete a1;
    delete p1;
    delete p2;

    w.show();


    return a.exec();
}
