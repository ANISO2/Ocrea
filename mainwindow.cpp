#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "evenements.h"
#include <QMediaPlayer>
#include <QMessageBox>
#include <QtDebug>
#include<QApplication>
#include <QSortFilterProxyModel>
#include <QTableView>
#include <QStandardItemModel>
#include <QFileDialog>
#include <QMovie>
#include <QtGui>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QVBoxLayout>
#include <QPrinter>
#include <QTextBrowser>
#include <QtWidgets/QMainWindow>
#include <QtWidgets>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
     ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->tableView_2->setModel(e.afficher());
    ui->leidevenement->setMaxLength(6);
    ui->lenomevenement->setMaxLength(6);
    QPixmap pix("C:/Users/user/Pictures/logo.png");
        ui->label_pic->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));
    proxy = new QSortFilterProxyModel();
            proxy->setSourceModel(e.afficher());
            proxy->setFilterCaseSensitivity(Qt::CaseInsensitive);
            proxy->setFilterKeyColumn(-1);
            ui->tableView_2->setModel(proxy);
                ui->tableView_2->resizeRowsToContents();
                ui->tableView_2->resizeColumnsToContents();

}

MainWindow::~MainWindow()
{
    delete ui;

}






void MainWindow::on_pushButton_event_clicked()
{

    QString idevenement=ui->leidevenement->text();
    QString nomevenement=ui->lenomevenement->text();
    QDateTime datedebut=ui->dateTimeEdit_event->dateTime();
    QString etat=ui->leetat->text();
    QString urlvideo=ui->leurlvideo->text();

    evenements e(idevenement,nomevenement,datedebut,etat,urlvideo);
    bool test=e.ajouter_evenements();

    if (test)
    {
        ui->tableView_2->setModel(e.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Ajout effectué\n" "Click Cancel to exit."),QMessageBox::Cancel);
        ui->leidevenement->clear();
        ui->lenomevenement->clear();
        ui->dateTimeEdit_event->setDateTime(QDateTime::currentDateTime());
        ui->leetat->clear();
        ui->leurlvideo->clear();
    }
    else
    {

        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("Ajout non effectué\n" "Click Cancel to exit."),QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_supprimer_clicked()
{
    QString idevenement=ui->leidevenement_supp->text();
    bool test=e.supprimer(idevenement);
    if(test)
    {
         ui->tableView_2->setModel(e.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("supression effectue\n" "Click Cancel to exit."),QMessageBox::Cancel);
        ui->leidevenement_supp->clear();

    }
    else
    {

        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("suppression non effectué\n" "Click Cancel to exit."),QMessageBox::Cancel);
        ui->leidevenement_supp->clear();

    }
}






void MainWindow::on_pushButton_update_clicked()
{
    QString idevenement=ui->leidevenement->text();
    QString nomevenement=ui->lenomevenement->text();
    QDateTime datedebut=ui->dateTimeEdit_event->dateTime();
    QString duree=ui->leetat->text();
    QString urlvideo=ui->leurlvideo->text();

    evenements e(idevenement,nomevenement,datedebut,duree,urlvideo);
    bool test=e.update(idevenement);

    if (test)
    {
        ui->tableView_2->setModel(e.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("modification effectué\n" "Click Cancel to exit."),QMessageBox::Cancel);
        ui->leidevenement->clear();
        ui->lenomevenement->clear();
        ui->dateTimeEdit_event->setDateTime(QDateTime::currentDateTime());
        ui->leetat->clear();
        ui->leurlvideo->clear();
    }
    else
    {

        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("modification non effectué\n" "Click Cancel to exit."),QMessageBox::Cancel);

    }
}


/*void MainWindow::on_pushButton_11_clicked()
{
    QString nomevenement = ui->le_rech->text();

       QSqlQueryModel* model = e.rechercher_nom(nomevenement);
       ui->tableView_2->setModel(model);
}*/

void MainWindow::on_pushButton_12_clicked()
{
    // Tri par date
    QSqlQueryModel* model = new QSqlQueryModel();
    model = e.tri_date();
    ui->tableView_2->setModel(model);
}


void MainWindow::on_pushButton_3_clicked()
{

    // Création d'un dialogue pour enregistrer le PDF
    QString fileName = QFileDialog::getSaveFileName(this, "Enregistrer PDF", QString(), "*.pdf");
    if (fileName.isNull()) {
    return;
    }
    // Création du fichier PDF
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);

    // Création du painter pour dessiner dans le PDF
    QPainter painter(&printer);

    // Dessin du tableau
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 10));
    int tableWidth = ui->tableView_2->width();
    int x = printer.pageRect().width() / 2 - tableWidth / 2;
    int y = 100;
    for (int i = 0; i < ui->tableView_2->model()->rowCount(); i++) {
        for (int j = 0; j < ui->tableView_2->model()->columnCount(); j++) {
            QModelIndex index = ui->tableView_2->model()->index(i, j);
            QRect cellRect = ui->tableView_2->visualRect(index);
            painter.drawRect(x, y, cellRect.width(), cellRect.height());
            painter.drawText(x + 2, y + 10, cellRect.width() - 4, cellRect.height() - 4, Qt::AlignLeft, ui->tableView_2->model()->data(index).toString());
            x += cellRect.width();
        }
        x = printer.pageRect().width() / 2 - tableWidth / 2;
        y += ui->tableView_2->rowHeight(i);

    }

    // Convertir le PDF en image
    QImage image(printer.pageRect().size(), QImage::Format_ARGB32);
    QPainter imagePainter(&image);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("");
    imagePainter.setRenderHint(QPainter::Antialiasing, true);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    QRect rect = image.rect();
    rect.setWidth(rect.width() - 1);
    rect.setHeight(rect.height() - 1);
    painter.setViewport(rect);
    painter.setWindow(0, 0, rect.width(), rect.height());
    painter.drawPixmap(0, 0, rect.width(), rect.height(), QPixmap::fromImage(image));

    // Créer une vue QGraphicsView pour afficher l'image

    QGraphicsView* view = new QGraphicsView(this);
    view->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    view->setScene(new QGraphicsScene(view));

    // Ajouter l'image à la vue QGraphicsView
    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    view->scene()->addItem(item);

    // Centrer l'image dans la vue
    item->setPos(-item->boundingRect().width() / 2, -item->boundingRect().height() / 2);

    }


void MainWindow::on_pushButton_7_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,
                                                      tr("Sélectionnez une vidéo"),
                                                      "",
                                                      tr("Fichiers vidéo (*.avi *.wmv *.mov *.mkv)"));

      if (filename != "") {
          QUrl videoUrl = QUrl::fromLocalFile(filename);

          QMediaPlayer *player = new QMediaPlayer;
          QVideoWidget *videoWidget = new QVideoWidget;

          player->setMedia(videoUrl);
          player->setVideoOutput(videoWidget);

          // Modification de la résolution de la fenêtre vidéo
          videoWidget->setFixedSize(640, 480);

          videoWidget->show();

          player->play();

          connect(player, &QMediaPlayer::stateChanged, [=](QMediaPlayer::State state){
              if(state == QMediaPlayer::StoppedState){
                  player->stop();
              }
          });
      }


}

void MainWindow::on_le_rech_textChanged(const QString &arg1)
{
proxy->setFilterFixedString(arg1);}




void MainWindow::on_pushButton_4_clicked()
{
    evenements e;
            QGridLayout *StatsLayout1 = ui->gridLayout;
            StatsLayout1->addWidget(e.statistique(), 0, 0);
}

void MainWindow::on_pushButton_6_clicked()
{
    m=new map();
    m->show();
}
