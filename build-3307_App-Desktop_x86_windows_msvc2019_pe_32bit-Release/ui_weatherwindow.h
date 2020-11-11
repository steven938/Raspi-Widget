/********************************************************************************
** Form generated from reading UI file 'weatherwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEATHERWINDOW_H
#define UI_WEATHERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WeatherWindow
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout_2;
    QLabel *label_4;
    QLabel *label;
    QPushButton *BackButton;
    QLCDNumber *humidity;
    QLCDNumber *windSpeed;
    QPushButton *torontoButton;
    QLabel *label_2;
    QPushButton *beijingButton;
    QPushButton *parisButton;
    QLabel *label_3;
    QLineEdit *searchBar;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QLCDNumber *temp;

    void setupUi(QWidget *WeatherWindow)
    {
        if (WeatherWindow->objectName().isEmpty())
            WeatherWindow->setObjectName(QString::fromUtf8("WeatherWindow"));
        WeatherWindow->resize(466, 386);
        horizontalLayoutWidget = new QWidget(WeatherWindow);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(9, 9, 16, 16));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout_2 = new QGridLayout(WeatherWindow);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_4 = new QLabel(WeatherWindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 9, 0, 1, 1);

        label = new QLabel(WeatherWindow);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("FreeSans"));
        label->setFont(font);

        gridLayout_2->addWidget(label, 1, 0, 1, 1);

        BackButton = new QPushButton(WeatherWindow);
        BackButton->setObjectName(QString::fromUtf8("BackButton"));

        gridLayout_2->addWidget(BackButton, 0, 0, 1, 1);

        humidity = new QLCDNumber(WeatherWindow);
        humidity->setObjectName(QString::fromUtf8("humidity"));
        humidity->setStyleSheet(QString::fromUtf8("QLCDNumber{\n"
"    color: rgb(255, 89, 242);    \n"
"    background-color: rgb(0, 85, 0);\n"
"}"));

        gridLayout_2->addWidget(humidity, 8, 0, 1, 1, Qt::AlignLeft);

        windSpeed = new QLCDNumber(WeatherWindow);
        windSpeed->setObjectName(QString::fromUtf8("windSpeed"));
        windSpeed->setStyleSheet(QString::fromUtf8("QLCDNumber{\n"
"    color: rgb(255, 89, 242);    \n"
"    background-color: rgb(0, 85, 0);\n"
"}"));

        gridLayout_2->addWidget(windSpeed, 10, 0, 1, 1, Qt::AlignLeft);

        torontoButton = new QPushButton(WeatherWindow);
        torontoButton->setObjectName(QString::fromUtf8("torontoButton"));

        gridLayout_2->addWidget(torontoButton, 2, 1, 1, 1);

        label_2 = new QLabel(WeatherWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 5, 0, 1, 1);

        beijingButton = new QPushButton(WeatherWindow);
        beijingButton->setObjectName(QString::fromUtf8("beijingButton"));

        gridLayout_2->addWidget(beijingButton, 5, 1, 1, 1);

        parisButton = new QPushButton(WeatherWindow);
        parisButton->setObjectName(QString::fromUtf8("parisButton"));

        gridLayout_2->addWidget(parisButton, 4, 1, 1, 1);

        label_3 = new QLabel(WeatherWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 7, 0, 1, 1);

        searchBar = new QLineEdit(WeatherWindow);
        searchBar->setObjectName(QString::fromUtf8("searchBar"));
        searchBar->setFont(font);

        gridLayout_2->addWidget(searchBar, 1, 1, 1, 1);

        groupBox = new QGroupBox(WeatherWindow);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        gridLayout->addWidget(radioButton, 0, 0, 1, 1);

        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        gridLayout->addWidget(radioButton_2, 1, 0, 1, 1);


        gridLayout_2->addWidget(groupBox, 2, 0, 1, 1);

        temp = new QLCDNumber(WeatherWindow);
        temp->setObjectName(QString::fromUtf8("temp"));
        temp->setEnabled(true);
        temp->setAcceptDrops(false);
        temp->setStyleSheet(QString::fromUtf8("QLCDNumber{\n"
"    color: rgb(255, 89, 242);    \n"
"    background-color: rgb(0, 85, 0);\n"
"}"));

        gridLayout_2->addWidget(temp, 6, 0, 1, 1, Qt::AlignLeft);


        retranslateUi(WeatherWindow);

        QMetaObject::connectSlotsByName(WeatherWindow);
    } // setupUi

    void retranslateUi(QWidget *WeatherWindow)
    {
        WeatherWindow->setWindowTitle(QCoreApplication::translate("WeatherWindow", "Habari | Weather", nullptr));
        label_4->setText(QCoreApplication::translate("WeatherWindow", "Wind Speed", nullptr));
        label->setText(QCoreApplication::translate("WeatherWindow", "What location's weather would you like to see?", nullptr));
        BackButton->setText(QCoreApplication::translate("WeatherWindow", "Back", nullptr));
        torontoButton->setText(QCoreApplication::translate("WeatherWindow", "Toronto, Canada", nullptr));
        label_2->setText(QCoreApplication::translate("WeatherWindow", "Temperature", nullptr));
        beijingButton->setText(QCoreApplication::translate("WeatherWindow", "Beijing, China", nullptr));
        parisButton->setText(QCoreApplication::translate("WeatherWindow", "Paris, France", nullptr));
        label_3->setText(QCoreApplication::translate("WeatherWindow", "Humidity", nullptr));
        groupBox->setTitle(QCoreApplication::translate("WeatherWindow", "Temperature Selection", nullptr));
        radioButton->setText(QCoreApplication::translate("WeatherWindow", "Celcius", nullptr));
        radioButton_2->setText(QCoreApplication::translate("WeatherWindow", "Farenheit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WeatherWindow: public Ui_WeatherWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEATHERWINDOW_H
