#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "batteries.h"
#include"calendrier.h"
#include "smtp.h"
#include <QMessageBox>
#include <QDateTime>
#include <QDebug>
#include <QApplication>
#include <QtCore>
#include <QPixmap>
#include <QPrinter>
#include <QPdfWriter>
#include <QPainter>
#include<QDesktopServices>
#include<QUrl>
#include<QDir>
#include<QFileDialog>
#include<statistiques.h>
#include <QCalendarWidget>
#include <QSettings>
#include <QVBoxLayout>
#include <QPainter>
#include<QtCharts>
#include<QChartView>
#include<QPieSeries>
#include<QPieSlice>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/21655/Pictures/e_power/logo.png");
    ui->label_pic->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));
     ui->tableView->setModel(B.afficher());

     ui->cb_pdf->clear();

     // Add the "choisir" option at the beginning of the QComboBox
     ui->cb_pdf->addItem("choisir");

     // Retrieve the data from the database and populate the QComboBox
     QSqlQuery query;
     query.prepare("SELECT * FROM BATTERIES"); // replace "your_table_name" with the actual name of your database table
     if (query.exec()) {
         while (query.next()) {
             int id = query.value(0).toInt();
             ui->cb_pdf->addItem(QString::number(id)); }}
//ui->cb_pdf->setModel(B.getAllId());

//int i;

/*for(i=1;i<B.getNumIdsInDatabase();i++)
{
    ui->cb_pdf->setModel(B.getAllId());
}*/


 }

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_ajout_clicked()
{

    QString IDBATTERIE=ui->lineEdit_id->text();
    QString ETAT=ui->lineEdit_etat->text();
    QDateTime DATERECHARGE=ui->lineEdit_date->dateTime();
  batteries B(IDBATTERIE,ETAT,DATERECHARGE);
  connect(ui->lineEdit_id, SIGNAL(textChanged(const QString &)), this, SLOT(checkInput(const QString &)));
  connect(ui->lineEdit_etat, SIGNAL(textChanged(const QString &)), this, SLOT(checkInput1(const QString &)));
  bool control=B.checkInput(IDBATTERIE);
  bool control1=B.checkInput1(ETAT);
    if(control==true && control1==true)
 {

         bool test=B.ajouterbatterie();
            if(test)
            {
                //refresh
                ui->tableView->setModel(B.afficher());
                QMessageBox::information(nullptr, QObject::tr("ok"),
                            QObject::tr("succes.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
                ui->lineEdit_id->clear();
                ui->lineEdit_etat->clear();

           }
            else
            {

                QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                            QObject::tr(" failed.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
                ui->lineEdit_id->clear();
                ui->lineEdit_etat->clear();
            }



}
  else if(control==false && control1==true)
  {
      // Si un caractère non-alphabétique est trouvé, afficher un message d'erreur
                 QMessageBox::warning(this, "Erreur", "ID doit contenir des lettres et des entiers.");
                 // Réinitialiser la saisie
                 ui->lineEdit_id->clear();
                 ui->lineEdit_etat->clear();

  }
    else if(control==true && control1==false)
    {
        // Si un caractère non-alphabétique est trouvé, afficher un message d'erreur
                   QMessageBox::warning(this, "Erreur", "ETAT invalide.");
                   // Réinitialiser la saisie
                   ui->lineEdit_id->clear();
                   ui->lineEdit_etat->clear();

    }
    else
    {
        QMessageBox::warning(this, "Erreur", " saisie invalide ");
        // Réinitialiser la saisie
        ui->lineEdit_id->clear();
        ui->lineEdit_etat->clear();

    }
}
void MainWindow::on_pushButton_supprimer_clicked()
{
    if (ui->lineEdit_id->text().isEmpty())
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("id is empty\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
 else
    {
        QSqlQuery query;
         QString IDBATTERIE=ui->lineEdit_id->text();
        query.prepare("SELECT COUNT(*) FROM BATTERIES WHERE IDBATTERIE=:IDBATTERIE");
        query.bindValue(":IDBATTERIE", IDBATTERIE);

        if (query.exec() && query.next())
        {

            int count = query.value(0).toInt();
            if (count>0){


                    QString IDBATTERIE=ui->lineEdit_id->text();

                    QMessageBox::StandardButton reply = QMessageBox::question(
                                nullptr,
                                "Confirmation de suppression",
                                "Êtes-vous sûr de vouloir supprimer cette voiture ?",
                                QMessageBox::Yes | QMessageBox::No
                                );


                     if(reply==QMessageBox::No)
                     {
                         ui->lineEdit_id->clear();
                     }
                     if (reply == QMessageBox::Yes)
                     {
                         bool test=B.supprimer(IDBATTERIE);
                     if(test)
                     {
                        ui->tableView->setModel(B.afficher());
                         QMessageBox::information(nullptr, QObject::tr("ok"),
                                     QObject::tr("suppression avec succes.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
                         ui->lineEdit_id->clear();
                         ui->lineEdit_etat->clear();

                    }
                                                     }
            }

                }


        else
        {
                QMessageBox::information(nullptr, QObject::tr("ok"),
                                                  QObject::tr("id invalide.\n"
                                                              "Click Cancel to exit."), QMessageBox::Cancel);
        }
        }



}
void MainWindow::on_pushButton_modify_clicked()
{
    QString IDBATTERIE=ui->lineEdit_id->text();
    QString ETAT=ui->lineEdit_etat->text();
    QDateTime DATERECHARGE=ui->lineEdit_date->dateTime();
   if (ui->lineEdit_id->text().isEmpty())
   {
       QMessageBox::information(nullptr, QObject::tr("ok"),
                   QObject::tr("id is empty.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
   }
   else
   {
       QSqlQuery query;
       query.prepare("SELECT COUNT(*) FROM BATTERIES WHERE IDBATTERIE=:IDBATTERIE");
       query.bindValue(":IDBATTERIE", IDBATTERIE);

       if (query.exec() && query.next())
       {

           int count = query.value(0).toInt();
           if (count>0) {
               query.prepare("UPDATE BATTERIES SET IDBATTERIE=:IDBATTERIE,ETAT=:ETAT,DATERECHARGE=:DATERECHARGE where IDBATTERIE=:IDBATTERIE ");
               query.bindValue(":IDBATTERIE",IDBATTERIE);
               query.bindValue(":ETAT",ETAT);
               query.bindValue(":DATERECHARGE",DATERECHARGE);
               if(query.exec())
               {
                    ui->tableView->setModel(B.afficher());
                   QMessageBox::information(nullptr, QObject::tr("ok"),
                               QObject::tr("updated.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
                   ui->lineEdit_id->clear();
                   ui->lineEdit_etat->clear();
               }


       }

       else
       {
               QMessageBox::information(nullptr, QObject::tr("ok"),
                                                 QObject::tr("id invalide.\n"
                                                             "Click Cancel to exit."), QMessageBox::Cancel);


       }
       }
       else
           {

              QMessageBox::information(nullptr, QObject::tr("ok"),
                          QObject::tr("update failed\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
           }




}
}


void MainWindow::on_pushButton_clicked()
{
    QString ID = ui->lineEdit_recherche->text();
    if (ID.isEmpty()) {
        ui->tableView->setModel(B.afficher());
    } else {
        QSqlQuery query;
        query.prepare("SELECT * FROM BATTERIES WHERE IDBATTERIE = :ID");
        query.bindValue(":ID", ID);
        if (query.exec() && query.next()) {
         QSqlQueryModel *model=new  QSqlQueryModel();

                model->setQuery(query);

                // Set the table view's model
                ui->tableView->setModel(model);

                model->setHeaderData(0,Qt::Horizontal,QObject::tr("IDBATTERIE"));
                model->setHeaderData(1,Qt::Horizontal,QObject::tr("ETAT"));
                model->setHeaderData(2,Qt::Horizontal,QObject::tr("DATERECHARGE"));
                //ui->tableView->show();

        } else {
            QMessageBox::warning(nullptr, "ID Not Found", "ID was not found.");
             ui->lineEdit_recherche->clear();
        }
    }
}

void MainWindow::on_tri_clicked()
{
    QSqlQuery query;
   query.prepare("SELECT IDBATTERIE, ETAT, DATERECHARGE FROM BATTERIES ORDER BY DATERECHARGE DESC");
    if (query.exec()) {
     QSqlQueryModel *model=new  QSqlQueryModel();

            model->setQuery(query);

            // Set the table view's model
            ui->tableView->setModel(model);

            model->setHeaderData(0,Qt::Horizontal,QObject::tr("IDBATTERIE"));
            model->setHeaderData(1,Qt::Horizontal,QObject::tr("ETAT"));
            model->setHeaderData(2,Qt::Horizontal,QObject::tr("DATERECHARGE"));
            //ui->tableView->show();

}
}

void MainWindow::on_pdf_clicked()
{
    QString id=ui->cb_pdf->currentText();



   // int selectedValue = id->currentData().toInt(); // Retrieve current data from QComboBox

    QString nomFichier = QFileDialog::getSaveFileName(0, "test", QString(), "*.pdf");
    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(nomFichier);
    QPainter painter;
    if (!painter.begin(&printer)) {
        qDebug() << "Error: QPainter could not begin.";
        return;
    }

    int i = 250;

    // painter.drawPixmap(10,10,QPixmap("C:/Users/21655/Pictures/e_power/logo.png"));

    painter.drawText(25, 50, "ID"); // Adjusted y-coordinate
    painter.drawText(150, 50, "etat"); // Adjusted y-coordinate
    painter.drawText(300, 50, "Date charge"); // Adjusted y-coordinate

    QSqlQuery query;
    if (!id.isEmpty()) {
        query.prepare("SELECT * FROM BATTERIES WHERE IDBATTERIE = :id");
        query.bindValue(":id", id);
    } if(id=="choisir") {
        query.prepare("SELECT * FROM BATTERIES");
        // query.bindValue(":id",id);
    }
    if (query.exec()) {
        while (query.next()) {
            i += 20;
            painter.drawText(25, i, query.value(0).toString());
            painter.drawText(150, i, query.value(1).toString());
            painter.drawText(300, i, query.value(2).toString());
        }
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("PDF Enregistré!.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    } else {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                  QObject::tr("PDF Non Enregistré!.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
    }

    painter.end();

}

void MainWindow::on_stat_clicked()
{
    batteries V;
     //S.setModal(true);
     //S.exec();

    int width = 1000; // desired width in pixels
    int height = 600; // desired height in pixel
    // Create the pie series and add slices to it
        QPieSeries *series = new QPieSeries();
        series->append("charge", 6);
        series->append("non charge ",5);

        foreach (QPieSlice *slice, series->slices()) {
            QString label = QString("%1 %2%").arg(slice->label()).arg(100 * slice->percentage(), 0, 'f', 2);
            slice->setLabel(label);
        }

        // Create a chart view to display the pie chart
        QChartView *chartView = new QChartView();
        chartView->setRenderHint(QPainter::Antialiasing);
        chartView->scene()->setSceneRect(0, 0, width, height);

        chartView->chart()->addSeries(series);
        chartView->chart()->setTitle("ETAT statics");

        // Set some chart options
       //chartView->chart()->setTheme(QChart::ChartThemeLight);
        //chartView->chart()->setTheme(QChart::ChartThemeHighContrast);
        chartView->chart()->setAnimationOptions(QChart::SeriesAnimations);
        chartView->chart()->legend()->setAlignment(Qt::AlignRight);
        chartView->chart()->legend()->setFont(QFont("Arial", 15));
        // Set the size and position of the chart view
        QPropertyAnimation *animation = new QPropertyAnimation(series, "opacity");

        // Set the target object and property to animate
        animation->setTargetObject(series);
        animation->setPropertyName("opacity");

        // Set the duration and easing curve
        animation->setDuration(1000);
        animation->setEasingCurve(QEasingCurve::InOutQuad);
        animation->start();

        // Show the chart view
        chartView->show();
        chartView->update();
 }




void MainWindow::on_calendrier_clicked()
{
    calendrier c;
     c.setModal(true);
     c.exec();
}

void MainWindow::on_pushButton_2_clicked()
{


      smtp* ssmtp = new smtp("mohamedoussama.mejri@esprit.tn", "pjaqfodfuzsefjjk", "smtp.gmail.com", 465);

              connect(ssmtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

              QString email=ui->lineEdit->text();

              QString b=ui->lineEdit_2->text();

              QString ob=ui->textEdit->toPlainText();

               if(email!="" && b!="" && ob!="" )
                  {


                                    ssmtp->sendMail("mohamedoussama.mejri@esprit.tn", email , b,ob);
                                    QMessageBox::information(nullptr, QObject::tr("EMAIL"),
                                    QObject::tr("Email sent successfully.\n"
                                    "click Cancel to exit"),QMessageBox::Cancel);

                  }
               else
                  {
                          QMessageBox::critical(nullptr, QObject::tr("EMAIL"),
                          QObject::tr("something is empty.\n"
                          "click Cancel to exit."),QMessageBox::Cancel);

                  }

}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
 void MainWindow:: on_mail_clicked()
 {
     ui->stackedWidget->setCurrentIndex(1);

 }
