#include "mainwindow.h"
#include <QApplication>
#include "professionnels.h"
#include "prives.h"
#include "adresse.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    Adresse a1("125, rue","Toulouse",36000);
    Contacts* p1= new Prives("Jean","Phillipe",'F',&a1,'C',"13/09/1955");
    Contacts* p2= new Professionnels("Jean","Phillipe",'F',&a1,"Abylsen","abylsen@jean.com");

    w.show();

    delete p1;
    delete p2;

    return a.exec();
}
