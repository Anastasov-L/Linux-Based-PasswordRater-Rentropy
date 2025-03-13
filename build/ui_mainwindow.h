/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *firstName;
    QLineEdit *lastName;
    QLineEdit *birthDate;
    QLineEdit *password;
    QPushButton *calculateButton;
    QLabel *entropyLabel;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(426, 651);
        QFont font;
        font.setFamily(QString::fromUtf8("Lato"));
        font.setBold(true);
        font.setWeight(75);
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: #222222;"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(130, 200, 181, 241));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        firstName = new QLineEdit(verticalLayoutWidget);
        firstName->setObjectName(QString::fromUtf8("firstName"));
        firstName->setFont(font);

        verticalLayout->addWidget(firstName);

        lastName = new QLineEdit(verticalLayoutWidget);
        lastName->setObjectName(QString::fromUtf8("lastName"));
        lastName->setFont(font);

        verticalLayout->addWidget(lastName);

        birthDate = new QLineEdit(verticalLayoutWidget);
        birthDate->setObjectName(QString::fromUtf8("birthDate"));
        birthDate->setFont(font);

        verticalLayout->addWidget(birthDate);

        password = new QLineEdit(verticalLayoutWidget);
        password->setObjectName(QString::fromUtf8("password"));
        password->setFont(font);

        verticalLayout->addWidget(password);

        calculateButton = new QPushButton(verticalLayoutWidget);
        calculateButton->setObjectName(QString::fromUtf8("calculateButton"));
        calculateButton->setFont(font);

        verticalLayout->addWidget(calculateButton);

        entropyLabel = new QLabel(verticalLayoutWidget);
        entropyLabel->setObjectName(QString::fromUtf8("entropyLabel"));
        entropyLabel->setFont(font);

        verticalLayout->addWidget(entropyLabel);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(130, 140, 221, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Lato"));
        font1.setItalic(true);
        label->setFont(font1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 426, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Entropy Calculator Rentropy", nullptr));
        calculateButton->setText(QCoreApplication::translate("MainWindow", "Calculate", nullptr));
        entropyLabel->setText(QCoreApplication::translate("MainWindow", "Entropy Score:", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Your Details", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
