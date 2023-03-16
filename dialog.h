#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "Employe.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_10_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_9_clicked();

private:
    Ui::Dialog *ui;
    EMPLOYE Etmp;
};

#endif // DIALOG_H
