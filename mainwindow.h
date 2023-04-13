#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "voiture.h"
#include <QFileDialog>
#include <QPrinter>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QSortFilterProxyModel *proxy;

private slots:
    void on_pushButton_8_clicked();


    void on_pushButton_10_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_recherche_clicked();


    void on_pushButton_12_clicked();

    void on_pushButton_3_clicked();
     void on_pushButton_4_clicked();

    void readfile();
    void on_le_rech_textChanged(const QString &arg1);


    void on_lineEdit_9_textChanged(const QString &arg1);

    void on_pushButton_7_clicked();

private:
    Ui::MainWindow *ui;
    voiture Etmp;

};
#endif // MAINWINDOW_H
