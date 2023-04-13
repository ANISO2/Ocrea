#include "calendrier.h"
#include "batteries.h"
#include "ui_calendrier.h"
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QInputDialog>
#include <QtWidgets/QMessageBox>
#include "QDateTime"
calendrier::calendrier(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::calendrier)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/21655/Pictures/e_power/logo.png");
    ui->label_pic->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));

}

calendrier::~calendrier()
{
    delete ui;
}

void calendrier::on_pushButton_clicked()
{
    close();
}

void calendrier::on_pushButton_2_clicked()
{
    QString ID =ui->lineEdit_rech->text();
    if (ID.isEmpty())
    {
    ui->dateTimeEdit_deb->clear();
    ui->dateTimeEdit_fin->clear();

    } else
    {
        QSqlQuery query;
        query.prepare("SELECT DATERECHARGE FROM BATTERIES WHERE IDBATTERIE = :ID");
        query.bindValue(":ID", ID);
        if (query.exec() && query.next())
        {

            QMessageBox::information(nullptr, QObject::tr("ok"),
                                              QObject::tr("id found.\n"
                                                          "Click Cancel to exit."), QMessageBox::Cancel);
            QDateTime datedeb=ui->dateTimeEdit_deb->dateTime();
            QDateTime datcharge = query.value(0).toDateTime();
                ui->dateTimeEdit_deb->setDateTime(datcharge);

            QDateTime datefin = ui->dateTimeEdit_fin->dateTime();
            datefin = datcharge.addDays(30); // Add 30 days to datefin
            ui->dateTimeEdit_fin->setDateTime(datefin);
            QDate calendarDatedeb = datedeb.date();
            QDate calendarDate = datefin.date();
            int year = calendarDatedeb.year();
            int month = calendarDatedeb.month();
            // Get the date part of the QDateTime
            //int year = calendarDate.year();
           // int month = calendarDate.month();
            //int day= calendarDate.day();
            QCalendarWidget *calendarWidget = ui->calendarWidget;
            calendarWidget->setCurrentPage(year, month);
            QTextCharFormat textFormat;
             textFormat.setBackground(Qt::red);
               calendarWidget->setDateTextFormat(calendarDate, textFormat);
              // Set the background color to red
                QTextCharFormat textFormat1;
                 textFormat1.setBackground(Qt::green);
                 calendarWidget->setDateTextFormat(calendarDatedeb, textFormat1);


        }
        else {
            QMessageBox::warning(nullptr, "Not Found", "ID was not found.");
             ui->lineEdit_rech->clear();
        }
    }
}
