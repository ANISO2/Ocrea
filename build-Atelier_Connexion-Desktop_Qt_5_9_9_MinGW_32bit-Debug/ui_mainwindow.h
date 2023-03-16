/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QLineEdit *lineEdit_id;
    QPushButton *pushButton_7;
    QPushButton *pushButton_4;
    QPushButton *pushButton_6;
    QPushButton *pushButton_ajout;
    QPushButton *pushButton_supprimer;
    QLabel *label_6;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit_9;
    QLabel *label_3;
    QLineEdit *lineEdit_etat;
    QLabel *label;
    QPushButton *pushButton_modify;
    QPushButton *pushButton_12;
    QDateTimeEdit *lineEdit_date;
    QTableView *tableView;
    QWidget *tab_4;
    QWidget *tab_5;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1115, 574);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(20, 20, 1041, 481));
        tabWidget->setStyleSheet(QStringLiteral(""));
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        lineEdit_id = new QLineEdit(tab_3);
        lineEdit_id->setObjectName(QStringLiteral("lineEdit_id"));
        lineEdit_id->setGeometry(QRect(180, 20, 113, 22));
        lineEdit_id->setStyleSheet(QLatin1String("\n"
"background-color: rgb(184, 247, 213);\n"
"\n"
"\n"
""));
        pushButton_7 = new QPushButton(tab_3);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(60, 347, 91, 41));
        pushButton_7->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: rgb(88, 255, 158);\n"
"	border-style: solid;\n"
"	border-width: 2px;\n"
"	border-color: #9999aa;\n"
"	border-radius: 14px;\n"
"	color: black;\n"
"	/*background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(0, 0, 255, 255), stop:1 rgba(255, 255, 255, 255));*/\n"
"}\n"
"\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(0, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"		color: #fffffe;\n"
"}\n"
"\n"
"\n"
"QPushButton:hover:!pressed {\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(255, 0, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"		color: #0c2f70;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"		background-color: #aaaaaa;\n"
"		color: #ffffff;\n"
"}"));
        QIcon icon;
        icon.addFile(QStringLiteral("../../../Downloads/275722247_3127640084221767_4987571222713071970_n.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_7->setIcon(icon);
        pushButton_7->setIconSize(QSize(23, 23));
        pushButton_4 = new QPushButton(tab_3);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(60, 267, 91, 41));
        pushButton_4->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: rgb(88, 255, 158);\n"
"	border-style: solid;\n"
"	border-width: 2px;\n"
"	border-color: #9999aa;\n"
"	border-radius: 14px;\n"
"	color: black;\n"
"	/*background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(0, 0, 255, 255), stop:1 rgba(255, 255, 255, 255));*/\n"
"}\n"
"\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(0, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"		color: #fffffe;\n"
"}\n"
"\n"
"\n"
"QPushButton:hover:!pressed {\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(255, 0, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"		color: #0c2f70;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"		background-color: #aaaaaa;\n"
"		color: #ffffff;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QStringLiteral("../../../Downloads/1170718.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon1);
        pushButton_4->setIconSize(QSize(20, 20));
        pushButton_6 = new QPushButton(tab_3);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(180, 307, 91, 41));
        pushButton_6->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: rgb(88, 255, 158);\n"
"	border-style: solid;\n"
"	border-width: 2px;\n"
"	border-color: #9999aa;\n"
"	border-radius: 14px;\n"
"	color: black;\n"
"	/*background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(0, 0, 255, 255), stop:1 rgba(255, 255, 255, 255));*/\n"
"}\n"
"\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(0, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"		color: #fffffe;\n"
"}\n"
"\n"
"\n"
"QPushButton:hover:!pressed {\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(255, 0, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"		color: #0c2f70;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"		background-color: #aaaaaa;\n"
"		color: #ffffff;\n"
"}\n"
""));
        QIcon icon2;
        icon2.addFile(QStringLiteral("../../../Downloads/32223.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon2);
        pushButton_6->setIconSize(QSize(20, 20));
        pushButton_ajout = new QPushButton(tab_3);
        pushButton_ajout->setObjectName(QStringLiteral("pushButton_ajout"));
        pushButton_ajout->setGeometry(QRect(480, 50, 131, 41));
        pushButton_ajout->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: rgb(88, 255, 158);\n"
"	border-style: solid;\n"
"	border-width: 2px;\n"
"	border-color: #9999aa;\n"
"	border-radius: 14px;\n"
"	color: black;\n"
"	/*background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(0, 0, 255, 255), stop:1 rgba(255, 255, 255, 255));*/\n"
"}\n"
"\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(0, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"		color: #fffffe;\n"
"}\n"
"\n"
"\n"
"QPushButton:hover:!pressed {\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(255, 0, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"		color: #0c2f70;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"		background-color: #aaaaaa;\n"
"		color: #ffffff;\n"
"}"));
        QIcon icon3;
        icon3.addFile(QStringLiteral("../../../Downloads/64579.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_ajout->setIcon(icon3);
        pushButton_ajout->setIconSize(QSize(20, 20));
        pushButton_supprimer = new QPushButton(tab_3);
        pushButton_supprimer->setObjectName(QStringLiteral("pushButton_supprimer"));
        pushButton_supprimer->setGeometry(QRect(830, 50, 131, 41));
        pushButton_supprimer->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: rgb(88, 255, 158);\n"
"	border-style: solid;\n"
"	border-width: 2px;\n"
"	border-color: #9999aa;\n"
"	border-radius: 14px;\n"
"	color: black;\n"
"	/*background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(0, 0, 255, 255), stop:1 rgba(255, 255, 255, 255));*/\n"
"}\n"
"\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(0, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"		color: #fffffe;\n"
"}\n"
"\n"
"\n"
"QPushButton:hover:!pressed {\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(255, 0, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"		color: #0c2f70;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"		background-color: #aaaaaa;\n"
"		color: #ffffff;\n"
"}"));
        QIcon icon4;
        icon4.addFile(QStringLiteral("../../../Downloads/121113.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_supprimer->setIcon(icon4);
        pushButton_supprimer->setIconSize(QSize(20, 20));
        label_6 = new QLabel(tab_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(70, 20, 41, 21));
        pushButton_3 = new QPushButton(tab_3);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(180, 217, 91, 41));
        pushButton_3->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: rgb(88, 255, 158);\n"
"	border-style: solid;\n"
"	border-width: 2px;\n"
"	border-color: #9999aa;\n"
"	border-radius: 14px;\n"
"	color: black;\n"
"	/*background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(0, 0, 255, 255), stop:1 rgba(255, 255, 255, 255));*/\n"
"}\n"
"\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(0, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"		color: #fffffe;\n"
"}\n"
"\n"
"\n"
"QPushButton:hover:!pressed {\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(255, 0, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"		color: #0c2f70;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"		background-color: #aaaaaa;\n"
"		color: #ffffff;\n"
"}"));
        QIcon icon5;
        icon5.addFile(QStringLiteral("../../../Downloads/PDF_file_icon.svg.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon5);
        pushButton_3->setIconSize(QSize(20, 20));
        lineEdit_9 = new QLineEdit(tab_3);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));
        lineEdit_9->setGeometry(QRect(870, 130, 151, 20));
        lineEdit_9->setStyleSheet(QLatin1String("background-color: rgb(183, 232, 201);\n"
""));
        label_3 = new QLabel(tab_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(70, 80, 51, 41));
        lineEdit_etat = new QLineEdit(tab_3);
        lineEdit_etat->setObjectName(QStringLiteral("lineEdit_etat"));
        lineEdit_etat->setGeometry(QRect(180, 50, 113, 22));
        lineEdit_etat->setStyleSheet(QLatin1String("\n"
"background-color: rgb(184, 247, 213);\n"
"\n"
""));
        label = new QLabel(tab_3);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 50, 51, 21));
        pushButton_modify = new QPushButton(tab_3);
        pushButton_modify->setObjectName(QStringLiteral("pushButton_modify"));
        pushButton_modify->setGeometry(QRect(650, 50, 141, 41));
        pushButton_modify->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: rgb(88, 255, 158);\n"
"	border-style: solid;\n"
"	border-width: 2px;\n"
"	border-color: #9999aa;\n"
"	border-radius: 14px;\n"
"	color: black;\n"
"	/*background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(0, 0, 255, 255), stop:1 rgba(255, 255, 255, 255));*/\n"
"}\n"
"\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(0, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"		color: #fffffe;\n"
"}\n"
"\n"
"\n"
"QPushButton:hover:!pressed {\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(255, 0, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"		color: #0c2f70;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"		background-color: #aaaaaa;\n"
"		color: #ffffff;\n"
"}"));
        QIcon icon6;
        icon6.addFile(QStringLiteral("../../../Downloads/45706.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_modify->setIcon(icon6);
        pushButton_modify->setIconSize(QSize(20, 20));
        pushButton_12 = new QPushButton(tab_3);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setGeometry(QRect(60, 190, 91, 41));
        pushButton_12->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: rgb(88, 255, 158);\n"
"	border-style: solid;\n"
"	border-width: 2px;\n"
"	border-color: #9999aa;\n"
"	border-radius: 14px;\n"
"	color: black;\n"
"	/*background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(0, 0, 255, 255), stop:1 rgba(255, 255, 255, 255));*/\n"
"}\n"
"\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(0, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"		color: #fffffe;\n"
"}\n"
"\n"
"\n"
"QPushButton:hover:!pressed {\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(255, 0, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"		color: #0c2f70;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"		background-color: #aaaaaa;\n"
"		color: #ffffff;\n"
"}"));
        QIcon icon7;
        icon7.addFile(QStringLiteral("../../../Downloads/271743198_464449928646161_2550356874147298555_n.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_12->setIcon(icon7);
        pushButton_12->setIconSize(QSize(25, 25));
        lineEdit_date = new QDateTimeEdit(tab_3);
        lineEdit_date->setObjectName(QStringLiteral("lineEdit_date"));
        lineEdit_date->setGeometry(QRect(180, 80, 151, 31));
        lineEdit_date->setStyleSheet(QLatin1String("background-color: rgb(184, 247, 213);\n"
"font: 9pt \"MS Shell Dlg 2\";\n"
""));
        tableView = new QTableView(tab_3);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(450, 160, 571, 281));
        tableView->viewport()->setProperty("cursor", QVariant(QCursor(Qt::UpArrowCursor)));
        tableView->setStyleSheet(QLatin1String("background-color: rgb(184, 247, 213);\n"
""));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        tabWidget->addTab(tab_5, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1115, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gestion des Clients", Q_NULLPTR));
        lineEdit_id->setText(QString());
        lineEdit_id->setPlaceholderText(QApplication::translate("MainWindow", "your id please....", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("MainWindow", "mail", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "Statistique", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("MainWindow", "Historique", Q_NULLPTR));
        pushButton_ajout->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        pushButton_supprimer->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">id</span></p></body></html>", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "Pdf", Q_NULLPTR));
        lineEdit_9->setPlaceholderText(QApplication::translate("MainWindow", "rechercher", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">date</span></p></body></html>", Q_NULLPTR));
        lineEdit_etat->setPlaceholderText(QApplication::translate("MainWindow", "etat batterie....", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">etat </span></p></body></html>", Q_NULLPTR));
        pushButton_modify->setText(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        pushButton_12->setText(QApplication::translate("MainWindow", "Tri", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "ajout", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "consulter ", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "elimner", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
