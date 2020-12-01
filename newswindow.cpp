/*
Author: Dhyey Patel
Description: CPP for NewsWindow, the window that displays information about the news
Date: 2020-11-11
*/
#include <iostream>

#include "newswindow.h"
#include "ui_newswindow.h"
#include <algorithm>

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
    // Create a list of all QLabels in the form
    QList<QLabel*> list = this->findChildren<QLabel *>();

    // Iterate through all QLabel objects and if their object name
    // is "url", "author", or "source then set their text to nothing,
    // thereby clearing them from view.
    foreach(QLabel *w, list) {
        if (w->objectName() == "url" || w->objectName() == "author" || w->objectName() == "source") {
            w->setText("");
        }
    }
}

/*!
 * \brief NewsWindow::displayArticles show articles found by the API based on user input to the form
 *
 * Visually show to the user the article names, author names, news sources, and create a hyperlink to the article.
 * \param records is a vector of NewsRecords representing all the articles that the user searched for.
 */
void NewsWindow::displayArticles(std::vector<NewsRecord> records) {
    // Variable y will be used as reference when determining
    // the positiong of the y-coordinate of the QLabel
    int y = 0;

    // Initialize QLabels for all the data about the articles
    QLabel *url;
    QLabel *author;
    QLabel *source;

    // The form will display a maximum of 13 articles, so the
    // number of articles to display is the minimum of articles found and 13.
    int numOfArticlesToDisplay = std::min(13, (int) records.size());


    // Iterate through each article
    for (int i = 0; i < numOfArticlesToDisplay; i++) {
        // Make a NewsRecord object to access the information
        // about the current article in records at position i
        NewsRecord record = records[i];

        // Instantiate a QLabel object to represent the url of the articles.
        url = new QLabel(this);
        // Set the positioning and size
        // Using variable y to ensure this url is the proper amount below the previous one
        url->move(10, 240 + y);
        url->setMaximumWidth(300);

        // Get the string representation of the articles url and title from records
        QString urlStr = QString::fromStdString(record.getURL());
        QString titleStr = QString::fromStdString(record.getTitle());

        // Add formatting for the url QLabel
        url->setTextInteractionFlags(Qt::TextBrowserInteraction);
        url->setOpenExternalLinks(true);
        url->setTextFormat(Qt::RichText);
        url->setAlignment(Qt::AlignBottom | Qt::AlignRight);

        // Create a QString that will represent the text of the url QLabel
        // href storing the url link and the the title string being set as displayed info
        QString s = "<a href=\"" + urlStr + "\">" + titleStr + "</a>";
        url->setText(s);

        // Set the object name to "author" so it can be referenced later in the clearResults function
        url->setObjectName("url");

        // Display the url data for this article to the form
        url->show();

        // Instantiate a QLabel object to represent the author of the articles.
        author = new QLabel(this);

        // Set the positioning and size
        // Using variable y to ensure this author name is the proper amount below the previous one
        author->move(355, 240 + y);
        author->setMaximumWidth(120);

        // Get the string representation of the author from records
        QString authorStr = QString::fromStdString(record.getAuthor());

        author->setText(authorStr);

        // Set the object name to "author" so it can be referenced later in the clearResults function
        author->setObjectName("author");

        // Display the author data for this article to the form
        author->show();

        // Instantiate a QLabel object to represent the source of the articles.
        source = new QLabel(this);

        // Set the positioning and size
        // Using variable y to ensure this source is the proper amount below the previous one
        source->move(485, 240 + y);
        source->setMaximumWidth(150);

        // Get the string representation of the source from records
        QString sourceStr = QString::fromStdString(record.getSource());

        source->setText(sourceStr);

        // Set the object name to "source" so it can be referenced later in the clearResults function
        source->setObjectName("source");

        // Display the source data for this article to the form
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
    // Clear the results so there is no overlap of new results on the old ones
    clearResults();

    NewsCategory *newsCat = new NewsCategory();
    std::string wordInput = (ui->wordInput->text()).toStdString();
    newsCat->requestArticles(wordInput);

    // Display the articles found from the API call
    displayArticles(newsCat->getRecords());
}

/*!
 * \brief NewsWindow::on_SearchByTopicButton_clicked finds articles related to the provided topic and displays them
 *
 *  Finds the relevant NewsRecords based on category selected and shows the information about them on the form
 */
void NewsWindow::on_SearchByTopicButton_clicked(){
    // Clear the results so there is no overlap of new results on the old ones
    clearResults();

    NewsCategory *newsCat = new NewsCategory();
    std::string topic = (ui->topic->currentText()).toStdString();
    newsCat->requestArticlesBySector(topic);

    // Display the articles found from the API call
    displayArticles(newsCat->getRecords());
}
