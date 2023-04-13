#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include"batteries.h"
#include "smtp.h"

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

    void on_pushButton_clicked();

    void on_tri_clicked();

    void on_pdf_clicked();

    void on_stat_clicked();

    void on_mail_clicked();


    void on_calendrier_clicked();




    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    batteries B;

};

#endif // MAINWINDOW_H
