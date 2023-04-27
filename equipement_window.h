#ifndef EQUIPEMENT_WINDOW_H
#define EQUIPEMENT_WINDOW_H
#include "equipement.h"
#include <QMainWindow>
#include <QWidget>
#include <QDialog>
#include <QSqlQuery>
#include <QtCharts>
#include "arduino.h"
QT_BEGIN_NAMESPACE
namespace Ui { class equipement_window; }
QT_END_NAMESPACE

class equipement_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit equipement_window(QWidget *parent = nullptr);
    ~equipement_window();
private:
    Ui::equipement_window *ui;
    equipement e;

    int selectedRow;

     // Déclarer Mod en tant que variable membre de la classe Equipement_Window
     QSqlQueryModel *Mod;

     void updateTableView();

   QByteArray data; // variable contenant les données reçues
   Arduino A;
   QVector<equipement> inventaire;
   QLabel *labelLOGOPIC;
   QTableView *tableView;
    private slots:
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();
    bool controlQUANTITE(int tes);
    bool controlID_EQUIPEMENT(int tes);
    bool controlVide(QString tes);
    void on_pushButton_SEARCH_clicked();
    void on_pushButton_TRI_clicked();
    void on_pushButton_P_clicked();
    void on_pushButton_Stat_clicked();
    void on_pushButton_image_clicked();
    void on_pushButton_codeQR_clicked();
    void on_pushButton_arduino_clicked();
};
#endif // EQUIPEMENT_WINDOW_H
