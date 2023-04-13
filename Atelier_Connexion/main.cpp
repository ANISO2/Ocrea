#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include <QSplashScreen>
#include <QPixmap>
#include <QTimer>
#include <QApplication>
#include <QPixmap>
#include <QSplashScreen>
#include <QTimer>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
    bool test = c.createconnect();
    MainWindow w;

    QPixmap pixmap("C:/Users/21655/Pictures/e_power/logo.png"); // Specify the path to your splash screen image


    QSplashScreen *splash = new QSplashScreen(pixmap);


    splash->setWindowTitle("CRUD");
    splash->show();



    QTimer::singleShot(3000, splash, &QSplashScreen::close);


    QTimer timer;
       timer.setSingleShot(true);
       QObject::connect(&timer, &QTimer::timeout, &w, &MainWindow::show);
       timer.start(3100);

   /* if (test)
    {
        QMessageBox::information(nullptr, "Database is open",
                                 "Connection successful.\nClick Cancel to exit.",
                                 QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, "Database is not open",
                              "Connection failed.\nClick Cancel to exit.",
                              QMessageBox::Cancel);
    }*/

    return a.exec();
}
