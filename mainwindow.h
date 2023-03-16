#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "evenements.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow: public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //void on_pushButton_8_clicked();

private slots:


    void on_pushButton_event_clicked();


    void on_pushButton_supprimer_clicked();



    void on_pushButton_update_clicked();

private:
    Ui::MainWindow *ui;
    evenements e;

};
#endif // MAINWINDOW_H
