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

    std::vector<NewsRecord> tempRec;
    tempRec = newsCat->getRecords();

    int y = 0;
    std::string source = (ui->source->text()).toStdString();
    QLabel *url;

    for (int i = 0; i < tempRec.size(); i++) {
        if (tempRec[i].getSource() == source) {
            url = new QLabel(this);
            url->move(10, 200 + y);
            url->setMinimumWidth(100);
            QString urlStr = QString::fromStdString(newsCat->getRecords()[i].getURL());
            url->setText(urlStr);
            url->setObjectName("url");
            url->setAlignment(Qt::AlignBottom | Qt::AlignRight);
            url->show();
            y += 20;
         }
    }
}
