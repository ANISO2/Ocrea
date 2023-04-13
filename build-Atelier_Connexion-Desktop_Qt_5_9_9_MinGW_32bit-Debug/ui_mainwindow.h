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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QPushButton *pushButton_supprimer;
    QPushButton *stat;
    QPushButton *pdf;
    QPushButton *mail;
    QPushButton *calendrier;
    QLabel *label_7;
    QPushButton *tri;
    QLabel *label_6;
    QLabel *label;
    QTableView *tableView;
    QPushButton *pushButton_ajout;
    QPushButton *pushButton_modify;
    QLineEdit *lineEdit_recherche;
    QPushButton *pushButton;
    QComboBox *cb_pdf;
    QLabel *label_3;
    QLineEdit *lineEdit_etat;
    QDateTimeEdit *lineEdit_date;
    QLineEdit *lineEdit_id;
    QLabel *label_pic;
    QWidget *page_2;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QTextEdit *textEdit;
    QPushButton *pushButton_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;
    QToolBar *toolBar_2;
    QToolBar *toolBar_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1235, 682);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(20, 10, 1091, 561));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        pushButton_supprimer = new QPushButton(page);
        pushButton_supprimer->setObjectName(QStringLiteral("pushButton_supprimer"));
        pushButton_supprimer->setGeometry(QRect(30, 390, 161, 31));
        pushButton_supprimer->setStyleSheet(QLatin1String("QPushButton {\n"
"		background-color: rgb(184, 247, 213);\n"
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
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(0, 255, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"		color: #0c2f70;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"		background-color: #aaaaaa;\n"
"		color: #ffffff;\n"
"}"));
        QIcon icon;
        icon.addFile(QStringLiteral("../../../Downloads/121113.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_supprimer->setIcon(icon);
        pushButton_supprimer->setIconSize(QSize(20, 20));
        stat = new QPushButton(page);
        stat->setObjectName(QStringLiteral("stat"));
        stat->setGeometry(QRect(540, 130, 111, 41));
        stat->setStyleSheet(QLatin1String("QPushButton {\n"
"			background-color: rgb(184, 247, 213);\n"
"	border-style: solid;\n"
"	border-width: 2px;\n"
"	border-color: #9999aa;\n"
"	border-radius: 14px;\n"
"\n"
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
"QPushButton:hover:!pressed {\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(0, 255, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"		color: #0c2f70;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"		background-color: #aaaaaa;\n"
"		color: #ffffff;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QStringLiteral("../../../Downloads/1170718.png"), QSize(), QIcon::Normal, QIcon::Off);
        stat->setIcon(icon1);
        stat->setIconSize(QSize(20, 20));
        pdf = new QPushButton(page);
        pdf->setObjectName(QStringLiteral("pdf"));
        pdf->setGeometry(QRect(390, 130, 111, 41));
        pdf->setStyleSheet(QLatin1String("QPushButton {\n"
"			background-color: rgb(184, 247, 213);\n"
"	border-style: solid;\n"
"	border-width: 2px;\n"
"	border-color: #9999aa;\n"
"	border-radius: 18px;\n"
"	\n"
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
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(0, 255, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"		color: #0c2f70;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"		background-color: #aaaaaa;\n"
"		color: #ffffff;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QStringLiteral("../../../Downloads/PDF_file_icon.svg.png"), QSize(), QIcon::Normal, QIcon::Off);
        pdf->setIcon(icon2);
        pdf->setIconSize(QSize(20, 20));
        mail = new QPushButton(page);
        mail->setObjectName(QStringLiteral("mail"));
        mail->setGeometry(QRect(690, 130, 101, 41));
        mail->setStyleSheet(QLatin1String("QPushButton {\n"
"	\n"
"	\n"
"		background-color: rgb(184, 247, 213);\n"
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
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(0, 255, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"		color: #0c2f70;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"		background-color: #aaaaaa;\n"
"		color: #ffffff;\n"
"}"));
        QIcon icon3;
        icon3.addFile(QStringLiteral("../../../Downloads/275722247_3127640084221767_4987571222713071970_n.png"), QSize(), QIcon::Normal, QIcon::Off);
        mail->setIcon(icon3);
        mail->setIconSize(QSize(23, 23));
        calendrier = new QPushButton(page);
        calendrier->setObjectName(QStringLiteral("calendrier"));
        calendrier->setGeometry(QRect(690, 80, 111, 31));
        calendrier->setStyleSheet(QLatin1String("QPushButton {\n"
"		background-color: rgb(184, 247, 213);\n"
"	border-style: solid;\n"
"	border-width: 2px;\n"
"	border-color: #9999aa;\n"
"	border-radius: 14px;\n"
"\n"
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
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(0, 255, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"		color: #0c2f70;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"		background-color: #aaaaaa;\n"
"		color: #ffffff;\n"
"}\n"
""));
        QIcon icon4;
        icon4.addFile(QStringLiteral("../../../Downloads/32223.png"), QSize(), QIcon::Normal, QIcon::Off);
        calendrier->setIcon(icon4);
        calendrier->setIconSize(QSize(20, 20));
        label_7 = new QLabel(page);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(350, 80, 41, 41));
        tri = new QPushButton(page);
        tri->setObjectName(QStringLiteral("tri"));
        tri->setGeometry(QRect(540, 80, 111, 31));
        tri->setStyleSheet(QLatin1String("QPushButton {\n"
"		background-color: rgb(184, 247, 213);\n"
"	border-style: solid;\n"
"	border-width: 2px;\n"
"	border-color: #9999aa;\n"
"	border-radius: 14px;\n"
"\n"
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
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(0, 255, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"		color: #0c2f70;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"		background-color: #aaaaaa;\n"
"		color: #ffffff;\n"
"}"));
        QIcon icon5;
        icon5.addFile(QStringLiteral("../../../Downloads/271743198_464449928646161_2550356874147298555_n.png"), QSize(), QIcon::Normal, QIcon::Off);
        tri->setIcon(icon5);
        tri->setIconSize(QSize(25, 25));
        label_6 = new QLabel(page);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 70, 41, 21));
        label = new QLabel(page);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 100, 51, 21));
        tableView = new QTableView(page);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(360, 190, 681, 281));
        tableView->viewport()->setProperty("cursor", QVariant(QCursor(Qt::UpArrowCursor)));
        tableView->setStyleSheet(QStringLiteral("background-color: rgb(184, 247, 213);"));
        pushButton_ajout = new QPushButton(page);
        pushButton_ajout->setObjectName(QStringLiteral("pushButton_ajout"));
        pushButton_ajout->setGeometry(QRect(30, 250, 161, 31));
        pushButton_ajout->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: rgb(184, 247, 213);\n"
"	\n"
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
"QPushButton:hover:!pressed {\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(0, 255, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"		color: #0c2f70;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"		background-color: #aaaaaa;\n"
"		color: #ffffff;\n"
"}"));
        QIcon icon6;
        icon6.addFile(QStringLiteral("../../../Downloads/64579.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_ajout->setIcon(icon6);
        pushButton_ajout->setIconSize(QSize(20, 20));
        pushButton_modify = new QPushButton(page);
        pushButton_modify->setObjectName(QStringLiteral("pushButton_modify"));
        pushButton_modify->setGeometry(QRect(30, 320, 161, 31));
        pushButton_modify->setStyleSheet(QLatin1String("QPushButton {\n"
"		background-color: rgb(184, 247, 213);\n"
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
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(0, 255, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"		color: #0c2f70;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"		background-color: #aaaaaa;\n"
"		color: #ffffff;\n"
"}"));
        QIcon icon7;
        icon7.addFile(QStringLiteral("../../../Downloads/45706.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_modify->setIcon(icon7);
        pushButton_modify->setIconSize(QSize(20, 20));
        lineEdit_recherche = new QLineEdit(page);
        lineEdit_recherche->setObjectName(QStringLiteral("lineEdit_recherche"));
        lineEdit_recherche->setGeometry(QRect(900, 160, 151, 20));
        lineEdit_recherche->setStyleSheet(QStringLiteral(""));
        pushButton = new QPushButton(page);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(950, 480, 93, 28));
        pushButton->setStyleSheet(QLatin1String("QPushButton:hover:!pressed {\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(0, 255, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"		color: #0c2f70;\n"
"}\n"
""));
        cb_pdf = new QComboBox(page);
        cb_pdf->setObjectName(QStringLiteral("cb_pdf"));
        cb_pdf->setGeometry(QRect(390, 80, 101, 41));
        cb_pdf->setStyleSheet(QLatin1String("background-color: rgb(184, 247, 213);\n"
"  color: black;\n"
"  padding: 10px;\n"
"  text-align: center;\n"
"font-family:calibri;\n"
"  font-size: 13px;\n"
"  margin: 2px 1px;\n"
"  border-radius : 16px;"));
        label_3 = new QLabel(page);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, 130, 51, 51));
        lineEdit_etat = new QLineEdit(page);
        lineEdit_etat->setObjectName(QStringLiteral("lineEdit_etat"));
        lineEdit_etat->setGeometry(QRect(70, 100, 113, 31));
        lineEdit_etat->setStyleSheet(QStringLiteral("background-color: rgb(184, 247, 213);"));
        lineEdit_date = new QDateTimeEdit(page);
        lineEdit_date->setObjectName(QStringLiteral("lineEdit_date"));
        lineEdit_date->setGeometry(QRect(60, 140, 151, 31));
        lineEdit_date->setStyleSheet(QLatin1String("background-color: rgb(184, 247, 213);\n"
"font: 9pt \"MS Shell Dlg 2\";\n"
""));
        lineEdit_id = new QLineEdit(page);
        lineEdit_id->setObjectName(QStringLiteral("lineEdit_id"));
        lineEdit_id->setGeometry(QRect(70, 60, 113, 31));
        lineEdit_id->setStyleSheet(QStringLiteral("background-color: rgb(184, 247, 213);"));
        label_pic = new QLabel(page);
        label_pic->setObjectName(QStringLiteral("label_pic"));
        label_pic->setGeometry(QRect(960, 20, 81, 71));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        pushButton_2 = new QPushButton(page_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(250, 390, 93, 28));
        pushButton_2->setStyleSheet(QLatin1String("QPushButton:hover:!pressed {\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(0, 255, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"		color: #0c2f70;\n"
"}"));
        lineEdit = new QLineEdit(page_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(110, 40, 381, 22));
        lineEdit->setStyleSheet(QStringLiteral("background-color: rgb(184, 247, 213);"));
        lineEdit_2 = new QLineEdit(page_2);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(110, 80, 251, 41));
        lineEdit_2->setStyleSheet(QStringLiteral("background-color: rgb(184, 247, 213);"));
        textEdit = new QTextEdit(page_2);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(120, 140, 391, 231));
        textEdit->setStyleSheet(QStringLiteral("background-color: rgb(184, 247, 213);"));
        pushButton_3 = new QPushButton(page_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(960, 30, 93, 28));
        pushButton_3->setStyleSheet(QLatin1String("QPushButton:hover:!pressed {\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(0, 255, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"		color: #0c2f70;\n"
"}"));
        stackedWidget->addWidget(page_2);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1235, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        toolBar_2 = new QToolBar(MainWindow);
        toolBar_2->setObjectName(QStringLiteral("toolBar_2"));
        MainWindow->addToolBar(Qt::LeftToolBarArea, toolBar_2);
        toolBar_3 = new QToolBar(MainWindow);
        toolBar_3->setObjectName(QStringLiteral("toolBar_3"));
        MainWindow->addToolBar(Qt::RightToolBarArea, toolBar_3);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gestion des Clients", Q_NULLPTR));
        pushButton_supprimer->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        stat->setText(QApplication::translate("MainWindow", "Statistique", Q_NULLPTR));
        pdf->setText(QApplication::translate("MainWindow", "Pdf", Q_NULLPTR));
        mail->setText(QApplication::translate("MainWindow", "mail", Q_NULLPTR));
        calendrier->setText(QApplication::translate("MainWindow", "calendrier", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">id</span></p></body></html>", Q_NULLPTR));
        tri->setText(QApplication::translate("MainWindow", "Tri", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">id</span></p></body></html>", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">etat </span></p></body></html>", Q_NULLPTR));
        pushButton_ajout->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        pushButton_modify->setText(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        lineEdit_recherche->setPlaceholderText(QApplication::translate("MainWindow", "rechercher", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "confirmer", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">date</span></p></body></html>", Q_NULLPTR));
        lineEdit_etat->setPlaceholderText(QApplication::translate("MainWindow", "etat batterie....", Q_NULLPTR));
        lineEdit_id->setText(QString());
        lineEdit_id->setPlaceholderText(QApplication::translate("MainWindow", "your id please....", Q_NULLPTR));
        label_pic->setText(QString());
        pushButton_2->setText(QApplication::translate("MainWindow", "send", Q_NULLPTR));
        lineEdit->setPlaceholderText(QApplication::translate("MainWindow", "email", Q_NULLPTR));
        lineEdit_2->setPlaceholderText(QApplication::translate("MainWindow", "subject", Q_NULLPTR));
        textEdit->setPlaceholderText(QApplication::translate("MainWindow", "your text.........", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "return", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", Q_NULLPTR));
        toolBar_2->setWindowTitle(QApplication::translate("MainWindow", "toolBar_2", Q_NULLPTR));
        toolBar_3->setWindowTitle(QApplication::translate("MainWindow", "toolBar_3", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
