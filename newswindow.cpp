/*
Author: Dhyey Patel
Description: CPP for NewsWindow, the window that displays information about the news
Date: 2020-11-11
*/
#include <iostream>

#include "newswindow.h"
#include "ui_newswindow.h"

/*
Name: NewsWindow THIS ENTIRE CLASS NEEDS TO BE COMPLETED- JUST A TEMPLATE IS BUILD SO FAR
Description: This is a constructor to create an instance of the NewsWindow class
Parameter Descriptions: It needs a reference to the main window, and needs to get its widgets
Return Description: N/A
*/
NewsWindow::NewsWindow(MainWindow * Window, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewsWindow)
{
    ui->setupUi(this);
    parentWindow = Window;

}

/*
Name: ~NewsWindow
Description: This is a deconstructor to destroy the instance of the NewsWindow class
Parameter Descriptions: N/A
Return Description: N/A
*/
NewsWindow::~NewsWindow()
{
    // Delete the ui created in the constructor
    delete ui;
}

/*
Name: on_BackButton_clicked
Description: Method will execute when the back button is clicked
Parameter Descriptions: N/A
Return Description: N/A
*/
void NewsWindow::on_BackButton_clicked(){
    parentWindow->close();
    parentWindow = new MainWindow();
    QFont font = QFont("FreeSans",10,1);
    parentWindow->setFont(font);
    parentWindow->show();
    parentWindow->show();
    close();

}


void NewsWindow::on_SubmitButton_clicked(){
    NewsCategory *newsCat = new NewsCategory();
    std::string category = (ui->category->text()).toStdString();
    newsCat->requestArticlesBySector(category);

    QString qstr1 = QString::fromStdString(newsCat->getRecords()[0].getURL());
    ui->url1->setText(qstr1);

    QString qstr2 = QString::fromStdString(newsCat->getRecords()[1].getURL());
    ui->url2->setText(qstr2);

    QString qstr3 = QString::fromStdString(newsCat->getRecords()[2].getURL());
    ui->url3->setText(qstr3);

    QString qstr4 = QString::fromStdString(newsCat->getRecords()[3].getURL());
    ui->url4->setText(qstr4);

    QString qstr5 = QString::fromStdString(newsCat->getRecords()[4].getURL());
    ui->url5->setText(qstr5);
}
