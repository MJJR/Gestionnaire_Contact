#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void load_Table();

private slots:
    void on_radioPro_pressed();

    void on_RadioPriv_pressed();

    void on_radioAll_pressed();

    void on_rechercheBtn_clicked();
    void on_actionFermer_triggered();

    void on_rechercheCancl_clicked();

    void on_ajouterContact_triggered();

protected:
    void closeEvent(QCloseEvent *);

private:
    Ui::MainWindow *ui;
    QSqlTableModel *model;
    QSqlDatabase db;
    int row;
};

#endif // MAINWINDOW_H
