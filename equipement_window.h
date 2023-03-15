#ifndef EQUIPEMENT_WINDOW_H
#define EQUIPEMENT_WINDOW_H
#include "equipement.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class equipement_window; }
QT_END_NAMESPACE

class equipement_window : public QMainWindow
{
    Q_OBJECT

public:
    equipement_window(QWidget *parent = nullptr);
    ~equipement_window();


private :
    Ui::equipement_window *ui;
    equipement e;


private slots:

    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();

};
#endif // EQUIPEMENT_WINDOW_H
