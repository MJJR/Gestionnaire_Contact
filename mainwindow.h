#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QSqlQuery>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool insertPro(int id, QString nom, QString prenom, char sexe, QString libelle, QString complement, QString ville, int codePostal, QString nomEntreprise, QString email);
    bool insertPrive(int id, QString nom, QString prenom, char sexe, QString libelle, QString complement, QString ville, int codePostal, QString dateNaissance);


private slots:
    void on_radioPro_pressed();

    void on_RadioPriv_pressed();

    void on_radioAll_pressed();

    void on_rechercheBtn_clicked();
    void on_actionFermer_triggered();

    void on_rechercheCancl_clicked();

    void on_ajouterContact_triggered();

    void on_choiceContact();

protected:
    void closeEvent(QCloseEvent *);

private:
    Ui::MainWindow *ui;
    QSqlTableModel *model;
    QSqlDatabase db;
    int row;
};

#endif // MAINWINDOW_H
