#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QMovie>
#include <QtGui>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include "voiture.h"
#include <QMessageBox>
#include<QVBoxLayout>
#include <QPrinter>
#include <QTextBrowser>
#include <QDebug>
#include <QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets>
#include <QSortFilterProxyModel>
#include <regex>
#include <QAxObject>
#include "arduino.h"






MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
     ui->setupUi(this);
     int ret=A.connect_arduino(); // lancer la connexion à arduino
     switch(ret){
     case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
         break;
     case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
        break;
     case(-1):qDebug() << "arduino is not available";
     }
      QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
      //le slot update_label suite à la reception du signal readyRead (reception des données).
    ui->tableView->setModel(Etmp.afficher_voiture());

   ui->lineEditcin->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));

   proxy = new QSortFilterProxyModel();
               proxy->setSourceModel(Etmp.afficher_voiture());
               proxy->setFilterCaseSensitivity(Qt::CaseInsensitive);
               proxy->setFilterKeyColumn(-1);
               ui->tableView->setModel(proxy);
                   ui->tableView->resizeRowsToContents();
                   ui->tableView->resizeColumnsToContents();



}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_8_clicked()
{
QString cin=ui->lineEditcin->text();
QString nomvoiture=ui->lineEditnomvoiture->text();
QString prenomvoiture=ui->lineEditprenomvoiture->text();
QString matriculevoiture=ui->lineEditmatriculevoiture->text();
QString IDBATTERIE=ui->lineEditIDBATTERIE->text();

voiture v(cin,nomvoiture,prenomvoiture,matriculevoiture,IDBATTERIE);
bool test=v.ajouter_voiture();
if (test)
{
    ui->tableView->setModel(Etmp.afficher_voiture());
    ui->lineEditcin->clear();
    ui->lineEditnomvoiture->clear();
    ui->lineEditprenomvoiture->clear();
    ui->lineEditmatriculevoiture->clear();
     ui->lineEditIDBATTERIE->clear();

    QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Ajout effectué\n" "Click Cancel to exit."),QMessageBox::Cancel);

}
else
{

    ui->lineEditcin->clear();
    ui->lineEditnomvoiture->clear();
    ui->lineEditprenomvoiture->clear();
    ui->lineEditmatriculevoiture->clear();
    ui->lineEditIDBATTERIE->clear();
    QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("Ajout non effectué\n" "Click Cancel to exit."),QMessageBox::Cancel);
}
//HISTORIQUE
                    QFile file("C:/Users/mjidr/OneDrive/Bureau/interface/historique.txt");
                            if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                                return;
                            QTextStream cout(&file);
                            QString d_info = QDateTime::currentDateTime().toString();
                            QString message2=d_info+" - Une voiture a ajouter  avec la référence "+cin+"\n";
                            cout << message2;
}


void MainWindow::on_pushButton_10_clicked()
{
    QString cin=ui->lineEdit_suppri->text();
    bool test=Etmp.supprimer_voiture(cin);


    if (test)
    {
        ui->tableView->setModel(Etmp.afficher_voiture());
        ui->lineEdit_suppri->clear();

        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Suppression effectué\n" "Click Cancel to exit."),QMessageBox::Cancel);
    }
    else
    {

              ui->lineEdit_suppri->clear();
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("Suppression non effectué\n" "Click Cancel to exit."),QMessageBox::Cancel);
    }
    //HISTORIQUE
                        QFile file("C:/Users/mjidr/OneDrive/Bureau/interface/historique.txt");
                                if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                                    return;
                                QTextStream cout(&file);
                                QString d_info = QDateTime::currentDateTime().toString();
                                QString message2=d_info+" - Une voiture a supprimer  avec la référence "+cin+" !\n";
                                cout << message2;
}






void MainWindow::on_pushButton_9_clicked()
{
    QString cin=ui->lineEditcin->text();
    QString nomvoiture=ui->lineEditnomvoiture->text();
    QString prenomvoiture=ui->lineEditprenomvoiture->text();
    QString matriculevoiture=ui->lineEditmatriculevoiture->text();
    QString IDBATTERIE=ui->lineEditIDBATTERIE->text();


    voiture v(cin,nomvoiture,prenomvoiture,matriculevoiture,IDBATTERIE);
    bool test=v.update(cin);

    if (test)
    {
        ui->tableView->setModel(v.afficher_voiture());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("modification effectué\n" "Click Cancel to exit."),QMessageBox::Cancel);
        ui->lineEditcin->clear();
        ui->lineEditnomvoiture->clear();
        ui->lineEditprenomvoiture->clear();
        ui->lineEditmatriculevoiture->clear();


            ui->lineEditIDBATTERIE->clear();
    }
    else
    {

        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("modification non effectué\n" "Click Cancel to exit."),QMessageBox::Cancel);
        ui->lineEditcin->clear();
        ui->lineEditnomvoiture->clear();
        ui->lineEditprenomvoiture->clear();
        ui->lineEditmatriculevoiture->clear();

            ui->lineEditIDBATTERIE->clear();
    }
    //HISTORIQUE
                        QFile file("C:/Users/mjidr/OneDrive/Bureau/interface/historique.txt");
                                if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                                    return;
                                QTextStream cout(&file);
                                QString d_info = QDateTime::currentDateTime().toString();
                                QString message2=d_info+" - Une voiture a modifier   avec la référence "+cin+"!\n";
                                cout << message2;


}



/*void MainWindow::on_pushButton_recherche_clicked()
{
    QString cin = ui->lineEdit_9->text();

       QSqlQueryModel * model = Etmp.rechercher_cin(cin);
       ui->tableView->setModel(model);

       //HISTORIQUE
                           QFile file("C:/Users/mjidr/OneDrive/Bureau/interface/historique.txt");
                                   if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                                       return;
                                   QTextStream cout(&file);
                                   QString d_info = QDateTime::currentDateTime().toString();
                                   QString message2=d_info+" - Une voiture a rechercher!\n";
                                   cout << message2;
}
*/







void MainWindow::on_pushButton_12_clicked()
{
    // Tri par cin
    QSqlQueryModel* model = new QSqlQueryModel();
    model = Etmp.tri_cin();
    ui->tableView->setModel(model);

    //HISTORIQUE
                        QFile file("C:/Users/mjidr/OneDrive/Bureau/interface/historique.txt");
                                if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                                    return;
                                QTextStream cout(&file);
                                QString d_info = QDateTime::currentDateTime().toString();
                                QString message2=d_info+" - faire le tri !\n";
                                cout << message2;
}

void MainWindow::on_pushButton_3_clicked()
{

        QString nomFichier = QFileDialog::getSaveFileName(0,"test",QString(),"*.pdf");
        QPrinter printer;
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(nomFichier);
        QPainter painter;
        if(!painter.begin(&printer)){
            qDebug() << "404";
            return;
        }






    int i=250;

        QSqlQuery query;



                            painter.drawText(25,200,"cin");
                            painter.drawText(150,200,"nomvoiture");
                            painter.drawText(300,200,"prenomvoiture");
                            painter.drawText(500,200,"matricule");

                                painter.drawText(700,200,"IDBATTERIE");


                      query.prepare("SELECT * FROM voitures");
                      if(query.exec())
                      {
                          while (query.next())
                          {
                              painter.drawText(25,i,query.value(0).toString());
                              painter.drawText(150,i,query.value(1).toString());
                              painter.drawText(300, i,query.value(2).toString());
                              painter.drawText(500,i,query.value(3).toString());
                              painter.drawText(700,i,query.value(4).toString());



                           i += 20;

                          }
                          QMessageBox::information(nullptr, QObject::tr("ok"),
                                      QObject::tr("PDF Enregistré!.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);
                      }

                      else
                      {
                          QMessageBox::information(nullptr, QObject::tr("ok"),
                                                QObject::tr("PDF Non Enregistré!.\n"
                                                            "Click Cancel to exit."), QMessageBox::Cancel);
                      }



       painter.end();



       //HISTORIQUE
                           QFile file("C:/Users/mjidr/OneDrive/Bureau/interface/historique.txt");
                                   if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                                       return;
                                   QTextStream cout(&file);
                                   QString d_info = QDateTime::currentDateTime().toString();
                                   QString message2=d_info+" - tranforme en pdf !\n";
                                   cout << message2;
    }




void MainWindow::on_pushButton_4_clicked()
{
    voiture v;
        QGridLayout *StatsLayout1 = ui->gridLayout;
        StatsLayout1->addWidget(v.statistique(), 0, 0);


        //HISTORIQUE
                            QFile file("C:/Users/mjidr/OneDrive/Bureau/interface/historique.txt");
                                    if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                                        return;
                                    QTextStream cout(&file);
                                    QString d_info = QDateTime::currentDateTime().toString();
                                    QString message2=d_info+" - voir statistique !\n";
                                    cout << message2;



}

void MainWindow::on_lineEdit_9_textChanged(const QString &arg1)
{
    proxy->setFilterFixedString(arg1);
}

void MainWindow::on_pushButton_7_clicked()

{

try{
    QString cinZ=ui->lineEditcin->text();
    int nbkwh = ui->lineEditfacture->text().toInt();

    QSqlQuery qry;
    qry.prepare("SELECT * FROM VOITURES WHERE CIN = :cinz ");
    qry.bindValue(":cinz",cinZ);
    qDebug()<<"prepar slect";
    qry.exec();
    if (qry.exec() && qry.next())
    {  int nbkwh = ui->lineEditfacture->text().toInt();

        float prixkwh;

        QString matricule= qry.value("MATRICULEVOITURE").toString();

        if (matricule == "TUN")
        {
           prixkwh=1.230;
           qDebug()<<"prepar TUN";
        }
        else if (matricule == "DUBAI")
        {
           prixkwh=2.230;

        }
        float prixtotal=nbkwh*prixkwh;
        QString prixtotalh = QString::number(prixtotal, 'f', 2);
        qDebug()<<prixtotalh;
        ui->label_8->setText(prixtotalh);
        ////////////////////////////////////

        QAxObject* excel = new QAxObject("Excel.Application");
         excel->setProperty("Visible", true);
        QAxObject* workbook = excel->querySubObject("Workbooks")->querySubObject("Add");
        // Get the active worksheet object
           QAxObject* worksheet = workbook->querySubObject("Worksheets(int)", 1);
           worksheet->querySubObject("Cells(int,int)", 1, 1)->setProperty("Value", "nom voiture");
            worksheet->querySubObject("Cells(int,int)", 1, 2)->setProperty("Value", "prenom voiture");
           worksheet->querySubObject("Cells(int,int)", 1, 3)->setProperty("Value", "matricule");
           worksheet->querySubObject("Cells(int,int)", 1, 4)->setProperty("Value", "prix");
           ui->label_8->setText(prixtotalh);

    int row = 2; // Start at row 2 (the first row is for column headers)


         worksheet->querySubObject("Cells(int,int)", row, 1)->setProperty("Value", qry.value("NOMVOITURE").toString());
           worksheet->querySubObject("Cells(int,int)", row, 2)->setProperty("Value", qry.value("PRENOMVOITURE").toString());
         worksheet->querySubObject("Cells(int,int)", row, 3)->setProperty("Value",qry.value("MATRICULEVOITURE").toString());
         worksheet->querySubObject("Cells(int,int)", row, 4)->setProperty("Value", prixtotalh);
         ui->label_8->setText(prixtotalh);



     QAxObject* usedRange = worksheet->querySubObject("UsedRange");
     QAxObject* columns = usedRange->querySubObject("Columns");

      columns->dynamicCall("AutoFit");
      // Save the workbook
             QString filePath = "C:/Users/mjidr/OneDrive/Bureau/interface/Benif.xlsx";
              QVariant result = workbook->dynamicCall("SaveAs(const QString&)", filePath);

              if (result.isNull()) {
                          // An error occurred, display a message to the user
                          QString errorMessage = "Error: " + workbook->property("LastError").toString();
                          ui->label_8->setText(prixtotalh);
                      }
              // Close the workbook and the Excel application
                      workbook->dynamicCall("Close()");
                      excel->dynamicCall("Quit()");
                      ui->label_8->setText(prixtotalh);

                  }

}catch (const std::exception& e) {
        // Handle the exception
        QString errorMessage = "Error: " + QString(e.what());
        QMessageBox::critical(nullptr, "Error", errorMessage);
        }




    //HISTORIQUE
                        QFile file("C:/Users/mjidr/OneDrive/Bureau/interface/historique.txt");
                                if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                                    return;
                                QTextStream cout(&file);
                                QString d_info = QDateTime::currentDateTime().toString();
                                QString message2=d_info+" - facture de voiture  !\n";
                                cout << message2;

}






void MainWindow::on_pushButton_2_clicked()
{
     qDebug()<<"batterie";
   QString niveau = A.read_from_arduino();                                                                                    //ta9ra elli b3athtou fel serial
       qDebug()<<niveau;
        ui->label_10->setText(niveau);                                                                                        // affiche le nom
        QString cinAr=ui->lineEditarduino->text();                                                                            //ta9ra lid elli ktebtou ena
        QSqlQuery qry;
        qry.prepare("SELECT * FROM VOITURES WHERE CIN = :cinAr ");
        qry.bindValue(":cinAr",cinAr);
        qDebug()<<"prepar slect";
        qry.exec();
        if (qry.exec() && qry.next())
        {
            QString nom= qry.value("NOMVOITURE").toString();
             QString cin= qry.value("CIN").toString();
                ui->label_11->setText(nom);
             QByteArray cinBytes = cin.toLocal8Bit();                                                                       //tbaddel el cin bch tab3thou lel arduino
            A.write_to_arduino(cinBytes);



        }

}
