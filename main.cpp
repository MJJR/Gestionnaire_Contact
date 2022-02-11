#include "mainwindow.h"
#include <QApplication>
#include "professionnels.h"
#include "prives.h"
#include "adresse.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    Adresse a1("lol","gneugneu",1);
    Contacts* p1= new Prives("prout","r2d2",'X',&a1,'1',"1a3/09/1955");
    Contacts* p2= new Professionnels("BWAAAAH","lol",'T',&a1,"Abylsen","abylsen@jean.com");

    w.show();

    delete p1;
    delete p2;

    return a.exec();
}
