#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include"batteries.h"
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

    void on_pushButton_ajout_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_modify_clicked();

private:
    Ui::MainWindow *ui;
    batteries B;
};

#endif // MAINWINDOW_H
