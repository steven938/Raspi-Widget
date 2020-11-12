/********************************************************************************
** Form generated from reading UI file 'stockwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STOCKWINDOW_H
#define UI_STOCKWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_stockWindow
{
public:
    QGridLayout *gridLayout;
    QPushButton *BackButton;
    QFrame *horizontalFrame;
    QHBoxLayout *horizontalLayout;

    void setupUi(QWidget *stockWindow)
    {
        if (stockWindow->objectName().isEmpty())
            stockWindow->setObjectName(QString::fromUtf8("stockWindow"));
        stockWindow->resize(400, 300);
        gridLayout = new QGridLayout(stockWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        BackButton = new QPushButton(stockWindow);
        BackButton->setObjectName(QString::fromUtf8("BackButton"));

        gridLayout->addWidget(BackButton, 0, 0, 1, 1);

        horizontalFrame = new QFrame(stockWindow);
        horizontalFrame->setObjectName(QString::fromUtf8("horizontalFrame"));
        horizontalLayout = new QHBoxLayout(horizontalFrame);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        gridLayout->addWidget(horizontalFrame, 1, 0, 1, 1);


        retranslateUi(stockWindow);

        QMetaObject::connectSlotsByName(stockWindow);
    } // setupUi

    void retranslateUi(QWidget *stockWindow)
    {
        stockWindow->setWindowTitle(QCoreApplication::translate("stockWindow", "Form", nullptr));
        BackButton->setText(QCoreApplication::translate("stockWindow", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class stockWindow: public Ui_stockWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STOCKWINDOW_H
