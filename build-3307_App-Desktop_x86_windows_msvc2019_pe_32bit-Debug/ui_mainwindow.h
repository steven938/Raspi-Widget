/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QPushButton *weatherButton;
    QPushButton *newsButton;
    QPushButton *stockButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(463, 299);
        MainWindow->setBaseSize(QSize(443, 286));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        formLayout = new QFormLayout(centralwidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::SpanningRole, label_2);

        weatherButton = new QPushButton(centralwidget);
        weatherButton->setObjectName(QString::fromUtf8("weatherButton"));
        weatherButton->setMinimumSize(QSize(80, 22));

        formLayout->setWidget(4, QFormLayout::FieldRole, weatherButton);

        newsButton = new QPushButton(centralwidget);
        newsButton->setObjectName(QString::fromUtf8("newsButton"));

        formLayout->setWidget(5, QFormLayout::FieldRole, newsButton);

        stockButton = new QPushButton(centralwidget);
        stockButton->setObjectName(QString::fromUtf8("stockButton"));
        stockButton->setMinimumSize(QSize(91, 0));

        formLayout->setWidget(3, QFormLayout::FieldRole, stockButton);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 463, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Welcome to Habari!", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "What kind of information would you like to see today?", nullptr));
        weatherButton->setText(QCoreApplication::translate("MainWindow", "Weather", nullptr));
        newsButton->setText(QCoreApplication::translate("MainWindow", "News", nullptr));
        stockButton->setText(QCoreApplication::translate("MainWindow", "Stocks", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
