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

void NewsWindow::clearResults() {
    QList<QLabel*> list = this->findChildren<QLabel *>();
    foreach(QLabel *w, list) {
        if (w->text()[0] == '<' && w->text()[1] == 'a' && w->text()[2] == ' ') {
            w->setText("");
        }
    }
}

void NewsWindow::displayArticles(std::vector<NewsRecord> records, NewsCategory *newsCategory) {
    int y = 0;
    QLabel *url;

    for (int i = 0; i < records.size(); i++) {
        url = new QLabel(this);
        url->move(10, 220 + y);
        url->setMinimumWidth(100);

        // Make the string for the QLabel be an active hyperlink
        QString urlStr = QString::fromStdString(newsCategory->getRecords()[i].getURL());
        url->setTextInteractionFlags(Qt::TextBrowserInteraction);
        url->setOpenExternalLinks(true);
        url->setTextFormat(Qt::RichText);
        QString s = "<a href=\"" + urlStr + "\">" + urlStr + "</a>";
        url->setText(s);

        url->setObjectName("url");
        url->setAlignment(Qt::AlignBottom | Qt::AlignRight);

        url->show();
        y += 20;
    }
}

void NewsWindow::on_SearchByWordButton_clicked(){
    clearResults();
    NewsCategory *newsCat = new NewsCategory();
    std::string wordInput = (ui->wordInput->text()).toStdString();
    newsCat->requestArticles(wordInput);

    std::vector<NewsRecord> tempRec;
    tempRec = newsCat->getRecords();

    displayArticles(tempRec, newsCat);
}

void NewsWindow::on_SearchByTopicButton_clicked(){
    clearResults();
    NewsCategory *newsCat = new NewsCategory();
    std::string topic = (ui->topic->currentText()).toStdString();
    newsCat->requestArticlesBySector(topic);

    std::vector<NewsRecord> tempRec;
    tempRec = newsCat->getRecords();

    displayArticles(tempRec, newsCat);
}
