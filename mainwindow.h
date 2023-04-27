#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "evenements.h"
#include <QMainWindow>
#include<QMediaPlayer>
#include <QVideoWidget>
#include <QPrinter>
#include <QPainter>
#include <QSortFilterProxyModel>
#include "map.h"
#include"arduino.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QMediaplayer;
class QVideoWidget;

class MainWindow: public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QSortFilterProxyModel *proxy;

    //void on_pushButton_8_clicked();

private slots:


    void on_pushButton_event_clicked();


    void on_pushButton_supprimer_clicked();



    void on_pushButton_update_clicked();

    /*void on_pushButton_11_clicked();*/

    void on_pushButton_12_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_8_clicked();

    void on_le_rech_textChanged(const QString &arg1);


    void on_pushButton_4_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_6_clicked();

    void on_pushButton_clicked();
    void on_pushButton_9_clicked();


    void on_pushButton_2_clicked();
    void update_label();

private:
    Ui::MainWindow *ui;
    evenements e;
    map *m;
       QLabel *labelLOGOPIC;
       QByteArray data; // variable contenant les données reçues

           Arduino A;
};
#endif // MAINWINDOW_H
