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
    QPushButton *BackButton;
    QPushButton *prevButton;
    QLabel *label;
    QLabel *label_3;
    QLineEdit *searchBar;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QRadioButton *celcButton;
    QRadioButton *farenButton;
    QPushButton *nextButton;
    QLabel *label_2;
    QLabel *label_5;
    QLCDNumber *temp;
    QLabel *locationLabel;
    QLabel *descLabel;
    QLabel *dateLabel;

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

        gridLayout_2->addWidget(label_4, 6, 0, 1, 1);

        BackButton = new QPushButton(WeatherWindow);
        BackButton->setObjectName(QString::fromUtf8("BackButton"));

        gridLayout_2->addWidget(BackButton, 0, 0, 1, 1);

        prevButton = new QPushButton(WeatherWindow);
        prevButton->setObjectName(QString::fromUtf8("prevButton"));
        prevButton->setCheckable(false);

        gridLayout_2->addWidget(prevButton, 8, 1, 1, 1);

        label = new QLabel(WeatherWindow);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("FreeSans"));
        label->setFont(font);

        gridLayout_2->addWidget(label, 1, 0, 1, 1);

        label_3 = new QLabel(WeatherWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 5, 0, 1, 1);

        searchBar = new QLineEdit(WeatherWindow);
        searchBar->setObjectName(QString::fromUtf8("searchBar"));
        searchBar->setFont(font);

        gridLayout_2->addWidget(searchBar, 1, 1, 1, 1);

        groupBox = new QGroupBox(WeatherWindow);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        celcButton = new QRadioButton(groupBox);
        celcButton->setObjectName(QString::fromUtf8("celcButton"));
        celcButton->setChecked(false);

        gridLayout->addWidget(celcButton, 0, 0, 1, 1);

        farenButton = new QRadioButton(groupBox);
        farenButton->setObjectName(QString::fromUtf8("farenButton"));
        farenButton->setChecked(true);

        gridLayout->addWidget(farenButton, 1, 0, 1, 1);


        gridLayout_2->addWidget(groupBox, 2, 0, 1, 1);

        nextButton = new QPushButton(WeatherWindow);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));

        gridLayout_2->addWidget(nextButton, 8, 2, 1, 1);

        label_2 = new QLabel(WeatherWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 4, 0, 1, 1);

        label_5 = new QLabel(WeatherWindow);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 7, 0, 1, 1);

        temp = new QLCDNumber(WeatherWindow);
        temp->setObjectName(QString::fromUtf8("temp"));
        temp->setEnabled(true);
        temp->setAcceptDrops(false);
        temp->setStyleSheet(QString::fromUtf8("QLCDNumber{\n"
"    color: rgb(255, 89, 242);    \n"
"    background-color: rgb(0, 85, 0);\n"
"}"));

        gridLayout_2->addWidget(temp, 5, 1, 1, 1);

        locationLabel = new QLabel(WeatherWindow);
        locationLabel->setObjectName(QString::fromUtf8("locationLabel"));

        gridLayout_2->addWidget(locationLabel, 4, 1, 1, 1);

        descLabel = new QLabel(WeatherWindow);
        descLabel->setObjectName(QString::fromUtf8("descLabel"));

        gridLayout_2->addWidget(descLabel, 6, 1, 1, 1);

        dateLabel = new QLabel(WeatherWindow);
        dateLabel->setObjectName(QString::fromUtf8("dateLabel"));

        gridLayout_2->addWidget(dateLabel, 7, 1, 1, 1);


        retranslateUi(WeatherWindow);

        QMetaObject::connectSlotsByName(WeatherWindow);
    } // setupUi

    void retranslateUi(QWidget *WeatherWindow)
    {
        WeatherWindow->setWindowTitle(QCoreApplication::translate("WeatherWindow", "Habari | Weather", nullptr));
        label_4->setText(QCoreApplication::translate("WeatherWindow", "Description", nullptr));
        BackButton->setText(QCoreApplication::translate("WeatherWindow", "Back", nullptr));
        prevButton->setText(QCoreApplication::translate("WeatherWindow", "Previous Day", nullptr));
        label->setText(QCoreApplication::translate("WeatherWindow", "What location's weather would you like to see?", nullptr));
        label_3->setText(QCoreApplication::translate("WeatherWindow", "Temperature", nullptr));
        groupBox->setTitle(QCoreApplication::translate("WeatherWindow", "Temperature Selection", nullptr));
        celcButton->setText(QCoreApplication::translate("WeatherWindow", "Celcius", nullptr));
        farenButton->setText(QCoreApplication::translate("WeatherWindow", "Farenheit", nullptr));
        nextButton->setText(QCoreApplication::translate("WeatherWindow", "Next Day", nullptr));
        label_2->setText(QCoreApplication::translate("WeatherWindow", "Location", nullptr));
        label_5->setText(QCoreApplication::translate("WeatherWindow", "Date", nullptr));
        locationLabel->setText(QString());
        descLabel->setText(QString());
        dateLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WeatherWindow: public Ui_WeatherWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEATHERWINDOW_H
