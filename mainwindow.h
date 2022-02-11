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

private slots:
    void on_radioPro_pressed();

    void on_RadioPriv_pressed();

    void on_radioAll_pressed();


private:
    Ui::MainWindow *ui;
    QSqlTableModel *model;
    int row;
};

#endif // MAINWINDOW_H
