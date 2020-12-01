/*
Author: Dhyey Patel
Description: CPP for NewsWindow, the window that displays information about the news
Date: 2020-11-11
*/
#include <iostream>

#include "newswindow.h"
#include "ui_newswindow.h"

/*!
 * \brief NewsWindow::NewsWindow constructor to create an instance of the NewsWindow class.
 *
 * constructor creates a NewsWindow object.
 * \param Window is a reference to the main window.
 * \param parent is a reference to get the associated widgets.
 */
NewsWindow::NewsWindow(MainWindow * Window, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewsWindow)
{
    ui->setupUi(this);
    parentWindow = Window;

}

/*!
 * \brief NewsWindow::~NewsWindow destructor destroys a NewsWindow object.
 *
 * Deletes the ui created in the constructor
 */
NewsWindow::~NewsWindow()
{
    delete ui;
}

/*!
 * \brief NewsWindow::on_BackButton_clicked returns to the main page.
 *
 * When BackButton is pressed the newswindow closes.
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

/*!
 * \brief NewsWindow::clearResults clears the article results found by the API from the form view.
 *
 * Sets the values of article title/links, author names, and news sources to nothing, thereby
 * clearing them from view.
 */
void NewsWindow::clearResults() {
    QList<QLabel*> list = this->findChildren<QLabel *>();
    foreach(QLabel *w, list) {
        if (w->objectName() == "url" || w->objectName() == "author" || w->objectName() == "source") {
            w->setText("");
        }
    }
}

/*!
 * \brief NewsWindow::displayArticles show the articles found by the API based on user input to the form
 *
 * Visually show to the user the article names, author names, news sources, and create a hyperlink to the article.
 * \param records is a vector of NewsRecords representing all the articles that the user searched for.
 * \param newsCategory is the NewsCategory object that stores the vector of records
 */
void NewsWindow::displayArticles(std::vector<NewsRecord> records, NewsCategory *newsCategory) {
    int y = 0;
    QLabel *url;
    QLabel *author;
    QLabel *source;

    for (int i = 0; i < records.size(); i++) {
        url = new QLabel(this);
        url->move(10, 240 + y);
        url->setMaximumWidth(300);

        NewsRecord record = newsCategory->getRecords()[i];

        // Make the string for the QLabel be an active hyperlink
        QString urlStr = QString::fromStdString(record.getURL());
        QString titleStr = QString::fromStdString(record.getTitle());
        url->setTextInteractionFlags(Qt::TextBrowserInteraction);
        url->setOpenExternalLinks(true);
        url->setTextFormat(Qt::RichText);
        QString s = "<a href=\"" + urlStr + "\">" + titleStr + "</a>";
        url->setText(s);

        url->setObjectName("url");
        url->setAlignment(Qt::AlignBottom | Qt::AlignRight);

        url->show();

        author = new QLabel(this);
        author->move(350, 240 + y);
        author->setMaximumWidth(120);
        QString authorStr = QString::fromStdString(record.getAuthor());
        author->setText(authorStr);
        author->setObjectName("author");


        author->show();

        source = new QLabel(this);
        source->move(500, 240 + y);
        source->setMaximumWidth(150);
        QString sourceStr = QString::fromStdString(record.getSource());
        source->setText(sourceStr);
        source->setObjectName("source");


        source->show();

        y += 20;
    }
}

/*!
 * \brief NewsWindow::on_SearchByWordButton_clicked finds articles related to the provided words and displays them
 *
 * Finds the relevant NewsRecords based on user input to the text box and shows the information about them on the form
 */
void NewsWindow::on_SearchByWordButton_clicked(){
    clearResults();
    NewsCategory *newsCat = new NewsCategory();
    std::string wordInput = (ui->wordInput->text()).toStdString();
    newsCat->requestArticles(wordInput);

    std::vector<NewsRecord> tempRec;
    tempRec = newsCat->getRecords();

    displayArticles(tempRec, newsCat);
}

/*!
 * \brief NewsWindow::on_SearchByTopicButton_clicked finds articles related to the provided topic and displays them
 *
 *  Finds the relevant NewsRecords based on category selected and shows the information about them on the form
 */
void NewsWindow::on_SearchByTopicButton_clicked(){
    clearResults();
    NewsCategory *newsCat = new NewsCategory();
    std::string topic = (ui->topic->currentText()).toStdString();
    newsCat->requestArticlesBySector(topic);

    std::vector<NewsRecord> tempRec;
    tempRec = newsCat->getRecords();

    displayArticles(tempRec, newsCat);
}
