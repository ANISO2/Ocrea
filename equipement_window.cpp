#include "equipement_window.h"
#include "ui_equipement_window.h"
#include <QMessageBox>
#include "equipement.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QValidator>
#include <QDebug>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QtPrintSupport/QPrinter>
#include <QWidget>
#include <QDialog>
#include <QLineEdit>
#include <QPrinter>
#include <QVBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QBarSet>
#include <QtCharts>
#include <QtCharts/QChart>
#include <QSqlTableModel>



equipement_window::equipement_window(QWidget *parent) :
      QMainWindow(parent),
      ui(new Ui::equipement_window)
{
    ui->setupUi(this);
    tableView = ui->tableView;

    ui->lineEdit_7->addItem(QIcon("C:\\Users\\Ghailen\\Desktop\\qttttt\\yes.png"),"bon etat");
    ui->lineEdit_7->addItem(QIcon("C:\\Users\\Ghailen\\Desktop\\qttttt\\no.jpg"),"necessite une maintennance");
    ui->lineEdit_7->setCurrentIndex(-1);

    ui->lineEdit_4->addItem(QIcon("C:\\Users\\Ghailen\\Desktop\\qttttt\\yes.png"),"actuellement disponible");
    ui->lineEdit_4->addItem(QIcon("C:\\Users\\Ghailen\\Desktop\\qttttt\\no.jpg"),"en cours d'utilisation");
    ui->lineEdit_4->setCurrentIndex(-1);

    QPixmap pix2("C:\\Users\\Ghailen\\Desktop\\Nouveau dossier\\oooo.png");
    ui->labelLOGOPIC->setPixmap(pix2);

    ui->tableView->setModel((e.afficher()));

    // Configure les contrôles de saisie pour les champs QUANTITE, ID_EQUIPEMENT, NOM_EQUIPEMENT et DESCRIPTION
    ui->lineEdit_6->setValidator(new QIntValidator(100000, 999999, this)); // pour ID_EQUIPEMENT
    ui->lineEdit_3->setValidator(new QIntValidator(1000, 9999, this)); // pour QUANTITE
    ui->lineEdit->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z]{0,7}"), this)); // pour NOM_EQUIPEMENT
    ui->lineEdit_5->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z]{0,70}"), this)); // pour DESCRIPTION
}

bool equipement_window::controlQUANTITE(int tes)
{
    QString QUANTIT = QString::number(tes);
    return QUANTIT.length() == 4;
}

bool equipement_window::controlID_EQUIPEMENT(int tes)
{
    QString num = QString::number(tes);
    return num.length() == 6;
}

bool equipement_window::controlVide(QString tes)
{
    return !tes.isEmpty();
}


equipement_window::~equipement_window()
{
    delete ui;
}

void equipement_window::on_pushButton_10_clicked()
{
    // supprimer
    bool ok;
    int ID_EQUIPEMENT = ui->lineEdit_6->text().toInt(&ok);
    if (!ok || ID_EQUIPEMENT <= 0) {
        QMessageBox::critical(nullptr, QObject::tr("Error"),
            QObject::tr("Invalid ID_EQUIPEMENT: %1\n"
                        "Please enter a valid integer ID.")
            .arg(ui->lineEdit_6->text()));
        return;
    }

    // Call the supprimer function to delete the equipment
    bool test = e.supprimer(ID_EQUIPEMENT);

    // Show a message box based on whether the deletion was successful
    if (test) {
        ui->tableView->setModel(e.afficher());
        QMessageBox::information(nullptr, QObject::tr("Success"),
            QObject::tr("Suppression effectuée.\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);
        ui->lineEdit_6->clear();
        ui->lineEdit_3->clear();
        ui->lineEdit->clear();
        ui->lineEdit_7->setCurrentIndex(-1); // initialiser la combobox "ETAT_EQUIPEMENT" à vide
        ui->lineEdit_4->setCurrentIndex(-1); // initialiser la combobox "DISPONIBILITE" à vide
        ui->lineEdit_5->clear();

    } else {
        QMessageBox::critical(nullptr, QObject::tr("Error"),
            QObject::tr("Suppression non effectuée.\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);
        ui->lineEdit_6->clear();
        ui->lineEdit_3->clear();
        ui->lineEdit->clear();
        ui->lineEdit_7->setCurrentIndex(-1); // initialiser la combobox "ETAT_EQUIPEMENT" à vide
        ui->lineEdit_4->setCurrentIndex(-1); // initialiser la combobox "DISPONIBILITE" à vide
        ui->lineEdit_5->clear();
    }
}

void equipement_window::on_pushButton_8_clicked()
{
    //ajouter

    int ID_EQUIPEMENT = ui->lineEdit_6->text().toInt();
    int QUANTITE = ui->lineEdit_3->text().toInt();
    QString NOM_EQUIPEMENT = ui->lineEdit->text();
    QString ETAT_EQUIPEMENT = ui->lineEdit_7->currentText();
    QString DISPONIBILITE = ui->lineEdit_4->currentText();
    QString DESCRIPTION = ui->lineEdit_5->text();
    equipement e(ID_EQUIPEMENT, QUANTITE, NOM_EQUIPEMENT, ETAT_EQUIPEMENT ,DISPONIBILITE,DESCRIPTION);

    bool test = e.ajouter();

    if (test)
    {
        ui->tableView->setModel(e.afficher());
        QMessageBox::information(nullptr, QObject::tr("ok"),
            QObject::tr("ajout effectué\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);
        ui->lineEdit_6->clear();
        ui->lineEdit_3->clear();
        ui->lineEdit->clear();
        ui->lineEdit_7->setCurrentIndex(-1); // initialiser la combobox "ETAT_EQUIPEMENT" à vide
        ui->lineEdit_4->setCurrentIndex(-1); // initialiser la combobox "DISPONIBILITE" à vide
        ui->lineEdit_5->clear();
    }
    else
    {

        QMessageBox::critical(nullptr, QObject::tr("not ok"),
            QObject::tr("ajout non effectué.\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);
        ui->lineEdit_6->clear();
        ui->lineEdit_3->clear();
        ui->lineEdit->clear();
        ui->lineEdit_7->setCurrentIndex(-1); // initialiser la combobox "ETAT_EQUIPEMENT" à vide
        ui->lineEdit_4->setCurrentIndex(-1); // initialiser la combobox "DISPONIBILITE" à vide
        ui->lineEdit_5->clear();

    }
}



void equipement_window::on_pushButton_9_clicked()
{
    // modifier


    int ID_EQUIPEMENT = ui->lineEdit_6->text().toInt();
    int QUANTITE = ui->lineEdit_3->text().toInt();
    QString NOM_EQUIPEMENT = ui->lineEdit->text();
    QString ETAT_EQUIPEMENT = ui->lineEdit_7->currentText();
    QString DISPONIBILITE = ui->lineEdit_4->currentText();
    QString DESCRIPTION = ui->lineEdit_5->text();
     equipement e (ID_EQUIPEMENT,QUANTITE,NOM_EQUIPEMENT,ETAT_EQUIPEMENT,DISPONIBILITE,DESCRIPTION);
    QMessageBox msgBox;
    if(e.rech(ID_EQUIPEMENT))
       {
    if (e.modifier(ID_EQUIPEMENT, QUANTITE, NOM_EQUIPEMENT, ETAT_EQUIPEMENT ,DISPONIBILITE,DESCRIPTION))
    {
        ui->tableView->setModel((e.afficher()));
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                        QObject::tr("UPDATE successfully.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        ui->lineEdit_6->clear();
        ui->lineEdit_3->clear();
        ui->lineEdit->clear();
        ui->lineEdit_7->setCurrentIndex(-1); // initialiser la combobox "ETAT_EQUIPEMENT" à vide
        ui->lineEdit_4->setCurrentIndex(-1); // initialiser la combobox "DISPONIBILITE" à vide
        ui->lineEdit_5->clear();
}
        else
           { QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                        QObject::tr("UPDATE failed \n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        ui->lineEdit_6->clear();
        ui->lineEdit_3->clear();
        ui->lineEdit->clear();
        ui->lineEdit_7->setCurrentIndex(-1); // initialiser la combobox "ETAT_EQUIPEMENT" à vide
        ui->lineEdit_4->setCurrentIndex(-1); // initialiser la combobox "DISPONIBILITE" à vide
        ui->lineEdit_5->clear();
    }
  }  else{ QMessageBox::critical(nullptr, QObject::tr("Not found"),
                                   QObject::tr("Not found \n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);

        ui->lineEdit_6->clear();
        ui->lineEdit_3->clear();
        ui->lineEdit->clear();
        ui->lineEdit_7->setCurrentIndex(-1); // initialiser la combobox "ETAT_EQUIPEMENT" à vide
        ui->lineEdit_4->setCurrentIndex(-1); // initialiser la combobox "DISPONIBILITE" à vide
        ui->lineEdit_5->clear();
}
}

void equipement_window::on_pushButton_SEARCH_clicked()
{
    QString searchValue = ui->lineEdit_9->text();

    // Recherche de l'équipement en fonction de la valeur de recherche
    QSqlQueryModel* model = e.afficherRecherche(searchValue);

    // Tri des résultats de recherche par ID_EQUIPEMENT
    model->sort(0, Qt::AscendingOrder);

    // Afficher les résultats triés dans le tableView
    ui->tableView->setModel(model);
}


void equipement_window::on_pushButton_TRI_clicked()
{
    // Créer une instance de la classe equipement
    equipement* e = new equipement();

    // Trier les données selon l'ID_EQUIPEMENT
    QSqlQueryModel* model = e->tri_ID_EQUIPEMENT();

    // Afficher les données triées dans le tableView
    ui->tableView->setModel(model);

    // Ne pas oublier de libérer la mémoire de l'instance equipement
    delete e;
}
void equipement_window::on_pushButton_P_clicked()
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
int tableWidth = ui->tableView->width();
int x = printer.pageRect().width() / 2 - tableWidth / 2;
int y = 100;
for (int i = 0; i < ui->tableView->model()->rowCount(); i++) {
    for (int j = 0; j < ui->tableView->model()->columnCount(); j++) {
        QModelIndex index = ui->tableView->model()->index(i, j);
        QRect cellRect = ui->tableView->visualRect(index);
        painter.drawRect(x, y, cellRect.width(), cellRect.height());
        painter.drawText(x + 2, y + 10, cellRect.width() - 4, cellRect.height() - 4, Qt::AlignLeft, ui->tableView->model()->data(index).toString());
        x += cellRect.width();
    }
    x = printer.pageRect().width() / 2 - tableWidth / 2;
    y += ui->tableView->rowHeight(i);

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

void equipement_window::on_pushButton_Stat_clicked()
{
connect(ui->pushButton_Stat, SIGNAL(clicked()), this, SLOT(on_Button_Stat_clicked()));
QSqlQueryModel *query = new QSqlQueryModel();

// Compter lequipement en bon etat
query->setQuery("SELECT SUM(QUANTITE) FROM EQUIPEMENT WHERE ETAT_EQUIPEMENT='bon etat'");
int nbStock = query->data(query->index(0, 0)).toInt();

// Compter lequipement necessite une maintennance
query->setQuery("SELECT SUM(QUANTITE) FROM EQUIPEMENT WHERE ETAT_EQUIPEMENT='necessite une maintennance'");
int nbRupture = query->data(query->index(0, 0)).toInt();

// Calculer les pourcentages
int total = nbStock + nbRupture;
float pourcentagebonetat = (nbStock * 100.0) / total;
float pourcentagemaintenance = (nbRupture * 100.0) / total;

// Créer la série de données du graphique
QPieSeries *series = new QPieSeries();
series->append("bon etat", nbStock);
series->append("necessite une maintennance", nbRupture);

// Créer le graphique
QChart *chart = new QChart();
chart->addSeries(series);
chart->setTitle("Pourcentage Par ETAT DE EQUIPEMENT : " + QString::number(pourcentagebonetat, 'f', 2) + "% equipements en bon etat, " + QString::number(pourcentagemaintenance, 'f', 2) + "% equipements necessitent une maintenance. Total: " + QString::number(total) + " equipements.");


// Créer la vue du graphique et la placer dans le widget QLabel
QChartView *chartView = new QChartView(chart, ui->label_stat);
chartView->setRenderHint(QPainter::Antialiasing);
chartView->resize(ui->label_stat->size());
chartView->show();

QPieSlice *slice1 = series->slices().at(0);
slice1->setBrush(QColor("#27da45"));

QPieSlice *slice2 = series->slices().at(1);
slice2->setBrush(QColor("#006d31"));
}

void equipement_window::on_pushButton_image_clicked()
{
    // Récupérer l'ID_EQUIPEMENT depuis la QLineEdit
    QString id = QString::number(ui->lineEdit_6->text().toInt());

    // Vérifier si l'ID_EQUIPEMENT existe dans le tableau tableview
    QModelIndexList indexList = ui->tableView->model()->match(ui->tableView->model()->index(0, 0), Qt::DisplayRole, id, -1, Qt::MatchExactly);
    if (indexList.isEmpty()) {
        QMessageBox::warning(this, tr("Erreur"), tr("L'ID_EQUIPEMENT entré n'existe pas."));
        return;
    }
    QModelIndex index = indexList.first();

    if (!index.isValid()) {
        QMessageBox::warning(this, tr("Erreur"), tr("L'ID_EQUIPEMENT entré n'existe pas."));
        return;
    }

    QString filename = QFileDialog::getOpenFileName(this,
                                                      tr("Sélectionnez une image"),
                                                      "",
                                                      tr("Fichiers d'image (*.png *.jpg *.bmp)"));

    if (filename != "") {
        QPixmap pixmap(filename);
        if (!pixmap.isNull()) {
            QLabel *imageLabel = new QLabel;
            imageLabel->setPixmap(pixmap.scaled(640, 480, Qt::KeepAspectRatio));
            imageLabel->show();

            QString path = QDir::currentPath() + "/images/"; // Chemin du dossier d'images
            QDir().mkpath(path); // Créer le dossier d'images s'il n'existe pas

            QString imageFilename = path + "equipement_" + id + ".jpg"; // Nom du fichier d'image avec l'ID_EQUIPEMENT
            QFile imageFile(imageFilename);

            if (imageFile.exists()) {
                // Si l'image existe déjà, la remplacer par la nouvelle
                imageFile.remove();
            }

            QImage image = pixmap.toImage(); // Convertir le QPixmap en QImage
            image.save(imageFilename); // Enregistrer l'image en utilisant la méthode QImage::save()
        }
    }
}
void equipement_window::on_pushButton_codeQR_clicked()
{
    // Récupérer la ligne sélectionnée dans la vue de la table
    QModelIndex index = ui->tableView->currentIndex();

    // Vérifier si une ligne est sélectionnée
    if (index.isValid()) {
        // Récupérer l'ID de l'équipement de la ligne sélectionnée
        int equipementID = ui->tableView->model()->data(ui->tableView->model()->index(index.row(), 0)).toInt();

        // Générer le QR code en utilisant l'API Google Charts
        QString message = " est le code qr qui correspond à cet équipement";
        QString url = QString("https://chart.googleapis.com/chart?cht=qr&chs=300x300&chl=%1%2").arg(equipementID).arg(message);

        // Ouvrir l'URL dans le navigateur web par défaut
        QDesktopServices::openUrl(QUrl(url));
    }
}

