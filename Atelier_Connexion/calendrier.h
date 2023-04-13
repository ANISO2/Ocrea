#ifndef CALENDRIER_H
#define CALENDRIER_H

#include <QDialog>
#include <QStyledItemDelegate>
#include<QPainter>
#include<QCalendarWidget>
namespace Ui {
class calendrier;
}
class calendrier : public QDialog
{
    Q_OBJECT

public:
    explicit calendrier(QWidget *parent = nullptr);
    ~calendrier();

private slots:
    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

private:
    Ui::calendrier *ui;
};

#endif // CALENDRIER_H
