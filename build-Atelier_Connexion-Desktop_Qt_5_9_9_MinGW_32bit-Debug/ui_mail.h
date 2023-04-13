/********************************************************************************
** Form generated from reading UI file 'mail.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIL_H
#define UI_MAIL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_mail
{
public:
    QLineEdit *semail;
    QLineEdit *ssubject;
    QTextEdit *smsg;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *mail)
    {
        if (mail->objectName().isEmpty())
            mail->setObjectName(QStringLiteral("mail"));
        mail->resize(1048, 530);
        semail = new QLineEdit(mail);
        semail->setObjectName(QStringLiteral("semail"));
        semail->setGeometry(QRect(50, 60, 491, 21));
        ssubject = new QLineEdit(mail);
        ssubject->setObjectName(QStringLiteral("ssubject"));
        ssubject->setGeometry(QRect(50, 100, 491, 51));
        smsg = new QTextEdit(mail);
        smsg->setObjectName(QStringLiteral("smsg"));
        smsg->setGeometry(QRect(50, 190, 531, 161));
        pushButton_2 = new QPushButton(mail);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(360, 410, 93, 28));
        pushButton_3 = new QPushButton(mail);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(890, 410, 93, 28));

        retranslateUi(mail);

        QMetaObject::connectSlotsByName(mail);
    } // setupUi

    void retranslateUi(QDialog *mail)
    {
        mail->setWindowTitle(QApplication::translate("mail", "Dialog", Q_NULLPTR));
        semail->setPlaceholderText(QApplication::translate("mail", "recipient", Q_NULLPTR));
        ssubject->setPlaceholderText(QApplication::translate("mail", "subject", Q_NULLPTR));
        smsg->setPlaceholderText(QApplication::translate("mail", "type your message here ...", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("mail", "send", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("mail", "return", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class mail: public Ui_mail {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIL_H
