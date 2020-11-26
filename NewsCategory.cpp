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
/*
Name: NewsCategory
Description: It will do nothing but create an instance of that class
Parameter Descriptions: N/A
Return Description: N/A
*/
NewsCategory::NewsCategory(){
    NewsCategory::requestArticlesBySector("business"); // sample request articles by sector
    NewsCategory::requestArticles("Covid vaccine"); // sample request articles by subject
    NewsCategory::requestArticles("Trump CNN"); // sample request articles by topic and source
}
/*
Name: Destructor
Description: Destroys the object
Parameter Descriptions: N/A
Return Description: N/A
*/
NewsCategory::~NewsCategory(){

}
/*
Name: getRecords
Description: Getter for collection of NewsRecords
Parameter Descriptions: N/A
Return Description: Returns the vector of NewsRecords
*/
vector<NewsRecord> NewsCategory::getRecords(){
    return this->records;
}

/*
Name: search
Description: Searches articles related to the requested search
Parameter Descriptions: Topic to search 
Return Description: NewsRecords related to the search
*/
Record NewsCategory::search(string searchString){
    searchString = "";
    Record r;
    return r;
}


/*
Name: sort
Description: sort the NewsRecords in the requested order
Parameter Descriptions: type is what to sort by, and asend is if we should sort in ascending order
Return Description: N/A
*/
void NewsCategory::sort(int type, bool asend){
    type = 0;
    asend = false;
}


/*
Name: changeTime
Description: Change the time period for NewsRecords in the vector, do another search if necessary
Parameter Descriptions: The timeframe you would like to change it to, prelist of timeframes represented by ints (1 = last week)
Return Description: the vector with the NewsRecords that follow the time period
*/
vector<NewsRecord> NewsCategory::changeTime(int time){
    time = 0;
    return this->records;
}

/*
Name: changeTopic
Description: Change the topic for NewsRecords in the vector, do another search if necessary
Parameter Descriptions: The topic you would like to change it to, prelist of topics represented by ints (1 = sports)
Return Description: the vector with the NewsRecords that follow the topic
*/
vector<NewsRecord> NewsCategory::changeTopic(int time){
    time = 0;
    return this->records;
}

/*
Name: changeNewsSource
Description: Change the news source for NewsRecords in the vector, do another search if necessary
Parameter Descriptions: The topic you would like to change it to, prelist of news sources represented by ints (1 = CNN)
Return Description: the vector with the NewsRecords that are from the given news source
*/
vector<NewsRecord> NewsCategory::changeNewsSource(int source){
    source = 0;
    return this->records;
}

/*
Name: displayRecords
Description: Helper function that will display the NewsRecords on the screen (called inside every function)
Parameter Descriptions: A vector with the NewsRecords to be displayed
Return Description: N/A
*/
void NewsCategory::displayRecords(vector<Record> toDisplay){
    toDisplay = {};
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
