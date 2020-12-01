/*
Author: Dhyey Patel
Description: Code file that define NewsCategory.h
Date: 2020-11-04
*/
#include "NewsCategory.h"
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QSslConfiguration>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QApplication>

using namespace std;


/*!
 * \brief NewsCategory::NewsCategory constructor creates a NewsCategory object.
 *
 * This is a constructor to create an instance of the NewsCategory class. Included for completeness, does not perform operations
 */
NewsCategory::NewsCategory(){
    //NewsCategory::requestArticlesBySector("business"); // sample request articles by sector
    //NewsCategory::requestArticles("Covid vaccine"); // sample request articles by subject
    //NewsCategory::requestArticles("Trump CNN"); // sample request articles by topic and source
}
/*!
 * \brief NewsCategory::~NewsCategory destructor destroys a NewsCategory object
 *
 * Since NewsCategory has no dynamically allocated memory, this does not do anything. Included for completeness.
 */
NewsCategory::~NewsCategory(){

}
/*!
* \brief getRecords, getter for the vector of Record s
*
* returns the records vector
*  @return records, the vector holding WeatherRecord s
*/
vector<NewsRecord> NewsCategory::getRecords(){
    return this->records;
}

/*!
* \brief search: returns a desired news record representing articles for a given query
*
* Creates a news record, passing the search string from the search bar to the new news record. This will call the news API and find articles related to the query
* @param searchString a string that represents the articles being searched for
* @return a news record with the articles for the search query
*
*/
Record NewsCategory::search(string searchString){
    searchString = "";
    Record r;
    return r;
}


/**
 * @brief NewsCategory::requestArticles function takes in a searchString and generates an API request to find articles related to the string.
 * NewsRecord objects are instatiated for each news article resulting from the search. Then NewsRecord Objects are loaded into this->records vector.
 * @param searchString can contain subject of interest (eg. "Trump", "covid-19") AND/OR the Source (eg. "CBC", "Trump CNN")
 */
void NewsCategory::requestArticles(string searchString){
    QNetworkRequest request;
    QString endpoint = "https://newsapi.org/v2/everything?q=" + QString::fromStdString(searchString) + "&pageSize=50&apiKey=4971830d2b5f43adab95290101902d24";

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setSslConfiguration(QSslConfiguration::defaultConfiguration());
    request.setUrl(QUrl(endpoint));

    QJsonObject json;
    QNetworkAccessManager nam;
    QNetworkReply *reply = nam.get(request);
    qDebug() << "called get request";
    while(!reply->isFinished())
    {
        qApp->processEvents();
    }
    qDebug() << "finished processing";
    if (reply->error() == QNetworkReply::NoError)
    {

        QByteArray response_data = reply->readAll();
        QJsonDocument document = QJsonDocument::fromJson(response_data);
        qDebug() << "Json Response Loaded : " << endpoint;
        QJsonObject obj = document.object();

        QJsonArray articles = obj["articles"].toArray();
        int numArticles = obj["totalResults"].toInt();

        NewsCategory::parseArticles(articles, numArticles);
    }else{
        qDebug() << "Json File Failed to Parse : " << endpoint;
        qDebug() << "Error : " << reply->errorString();
    }
    reply->deleteLater();
}

// sector must be one of: business entertainment general health science sports technology
/**
 * @brief NewsCategory::requestArticlesBySector function takes in a string representing a sector/category and retreives articles from API.
 * The articles are loaded into this->record.
 * @param sector MUST BE ONE FOLLOWING: "business", "entertainment", "general", "health", "science", "sports", or "technology"
 */
void NewsCategory::requestArticlesBySector(string sector){
    QNetworkRequest request;
    QString endpoint = "https://newsapi.org/v2/top-headlines?category=" + QString::fromStdString(sector) + "&pageSize=50&apiKey=4971830d2b5f43adab95290101902d24&country=us";

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setSslConfiguration(QSslConfiguration::defaultConfiguration());
    request.setUrl(QUrl(endpoint));

    QJsonObject json;
    QNetworkAccessManager nam;
    QNetworkReply *reply = nam.get(request);
    qDebug() << "called get request";
    while(!reply->isFinished())
    {
        qApp->processEvents();
    }
    qDebug() << "finished processing";
    if (reply->error() == QNetworkReply::NoError)
    {

        QByteArray response_data = reply->readAll();
        QJsonDocument document = QJsonDocument::fromJson(response_data);
        qDebug() << "Json Response Loaded : " << endpoint;
        QJsonObject obj = document.object();

        QJsonArray articles = obj["articles"].toArray();
        int numArticles = obj["totalResults"].toInt();

        NewsCategory::parseArticles(articles, numArticles);
    }else{
        qDebug() << "Json File Failed to Parse : " << endpoint;
        qDebug() << "Error : " << reply->errorString();
    }
    reply->deleteLater();
}

/**
 * @brief NewsCategory::parseArticles helper function for parsing news articles in JSON
 * @param articles  QJSonArray that holds multiple news articles in json object form
 * @param numArticles the max number of articles found
 */
void NewsCategory::parseArticles(QJsonArray& articles, int numArticles){
    for(int i=0; i< min(numArticles, 50); i++){
        QJsonObject article = articles.at(i).toObject();

        QString source = article["source"].toObject()["name"].toString();
        QString author = article["author"].toString();
        QString title = article["title"].toString();
        QString description = article["description"].toString();
        QString url = article["url"].toString();
        string dateText = article["publishedAt"].toString().toStdString();
        int year = stoi(dateText.substr(0, 4));
        int month = stoi(dateText.substr(5, 2));
        int day = stoi(dateText.substr(8, 2));

        NewsRecord newsArticle(Date(day, month, year), author.toStdString(), title.toStdString(), description.toStdString(), source.toStdString(), url.toStdString());
        this->records.push_back(newsArticle);

        qDebug() << "\n" << QString::fromStdString(records.back().getDate().getStr());
        qDebug() << QString::fromStdString(records.back().getSource()) << "\n";
        qDebug() << QString::fromStdString(records.back().getAuthor()) << "\n";
        qDebug() << QString::fromStdString(records.back().getTitle()) << "\n";
        qDebug() << QString::fromStdString(records.back().getDescription()) << "\n";
        qDebug() << QString::fromStdString(records.back().getURL()) << "\n";
        qDebug() << "_______________________________________" << "\n\n";
    }
}
