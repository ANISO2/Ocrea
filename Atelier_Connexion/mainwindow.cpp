#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "batteries.h"
#include <QMessageBox>
#include <QDateTime>
#include <QDebug>
#include <QApplication>
#include <QtCore>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(B.afficher());
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

        QString IDBATTERIE=ui->lineEdit_id->text();
        QSqlQuery query;
        query.prepare("SELECT COUNT(*) FROM BATTERIES WHERE IDBATTERIE=:IDBATTERIE");
        query.bindValue(":IDBATTERIE", IDBATTERIE);

        if (query.exec() && query.next())
        {

            int count = query.value(0).toInt();
            if (count>0){


                    QString IDBATTERIE=ui->lineEdit_id->text();
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

        else
        {
                QMessageBox::information(nullptr, QObject::tr("ok"),
                                                  QObject::tr("id invalide.\n"
                                                              "Click Cancel to exit."), QMessageBox::Cancel);
        }
        }

    else
    {


             QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                         QObject::tr(" failed.\n"
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

