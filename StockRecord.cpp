/*
Author: Steven Chen
Description: Cpp file for StockRecord representing information about a single stock/company
Date: 2020-11-04
*/

#include "StockRecord.h"
#include "Date.h"
#include <string.h>
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
Name: constructor
Description: initializes query to the stock API to initialize stock information
Parameter Descriptions: 
Return Description: 
*/
StockRecord::StockRecord(string ticker){
    this->ticker = ticker;

    // API CALL 1: Get Stock Price Information
    // NOTE: Limit of 5 API requests per minute

    QNetworkRequest request;
    QString endpoint = "https://www.alphavantage.co/query?function=TIME_SERIES_DAILY_ADJUSTED&symbol=" + QString::fromStdString(ticker) + "&apikey=AI83R8IOLM46LIP2";

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setSslConfiguration(QSslConfiguration::defaultConfiguration());
    request.setUrl(QUrl(endpoint));

    QJsonObject json;
    QNetworkAccessManager nam;
    QNetworkReply *reply = nam.get(request);
    while(!reply->isFinished())
    {
        qApp->processEvents();
    }

    if (reply->error() == QNetworkReply::NoError)
    {
        QByteArray response_data = reply->readAll();
        QJsonDocument document = QJsonDocument::fromJson(response_data);
        qDebug() << "Json Response Loaded : " << endpoint;
        QJsonObject obj = document.object();
        QJsonObject stockData = obj["Time Series (Daily)"].toObject();

        foreach(const QString& dateText, stockData.keys()){
            int year = stoi(dateText.toStdString().substr(0, 4));
            int month = stoi(dateText.toStdString().substr(5, 2));
            int day = stoi(dateText.toStdString().substr(8, 2));
            Date curDate(day, month, year);

            QJsonObject dailyData = stockData[dateText].toObject();

            float open = dailyData["1. open"].toString().toFloat();
            float high = dailyData["2. high"].toString().toFloat();
            float low = dailyData["3. low"].toString().toFloat();
            float close = dailyData["4. close"].toString().toFloat();
            long long int volume = dailyData["5. volume"].toString().toInt();


            this->days.emplace_back(open, close, high, low, volume, curDate);
        }
        // reverse array since dates are read in reverse order
        reverse(this->days.begin(), this->days.end());

    }
    else // something went wrong
    {
        qDebug() << "Json File Failed to Parse : " << endpoint;
        qDebug() << "Error : " << reply->errorString();
    }
    reply->deleteLater();




    // API CALL 2: Get Company Information

    QNetworkRequest request2;
    QString endpoint2 = "https://finnhub.io/api/v1/stock/profile2?symbol=" + QString::fromStdString(ticker) + "&token=bulhelv48v6p4m01r9jg";

    request2.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request2.setSslConfiguration(QSslConfiguration::defaultConfiguration());
    request2.setUrl(QUrl(endpoint2));

    QJsonObject json2;
    QNetworkAccessManager nam2;
    QNetworkReply *reply2 = nam2.get(request2);
    while(!reply2->isFinished())
    {
        qApp->processEvents();
    }

    if (reply2->error() == QNetworkReply::NoError)
    {
        QByteArray response_data2 = reply2->readAll();
        QJsonDocument document2 = QJsonDocument::fromJson(response_data2);
        qDebug() << "Json Response Loaded : " << endpoint2;
        QJsonObject obj2 = document2.object();
        this->companyName = obj2["name"].toString().toStdString();
        this->exchange = obj2["exchange"].toString().toStdString();
        double marketCapMillion = obj2["marketCapitalization"].toDouble() * 1000000;
        QString marketCapStr = QString::number(marketCapMillion);
        this->marketCap = marketCapStr.toStdString();

        qDebug() << QString::fromStdString(this->companyName) << " " << QString::fromStdString(this->exchange) << QString::fromStdString(this->marketCap);
    }
    else // something went wrong
    {
        qDebug() << "Json File Failed to Parse : " << endpoint2;
        qDebug() << "Error : " << reply2->errorString();
    }
    reply2->deleteLater();
}

/*
Name: getTicker
Description: 
Parameter Descriptions: get the ticker name of the stock
Return Description: ticker
*/
string StockRecord::getTicker(){
    return ticker;
}

/*
Name: getCompanyName
Description: gets the company name
Parameter Descriptions: 
Return Description: company name
*/
string StockRecord::getCompanyName(){
    return companyName;
}

/*
Name: getExchange
Description: gets the exchange on which stock is traded on
Parameter Descriptions:
Return Description:
*/
string StockRecord::getExchange(){
    return exchange;
}

/*
Name: getMarketCap
Description: gets market capitalization of the stock
Parameter Descriptions: 
Return Description: market cap
*/
string StockRecord::getMarketCap(){
    return this->marketCap;
}

/*
Name: getOpen
Description: gets the open price some number of days ago
Parameter Descriptions: the number days to look back
Return Description: open price
*/
float StockRecord::getOpen(int daysAgo){
    return days[daysAgo].getOpen();
}

/*
Name: getLow
Description: gets the low price some number of days ago
Parameter Descriptions: the number days to look back
Return Description: low price
*/
float StockRecord::getLow(int daysAgo){
    return days[daysAgo].getLow();
}

/*
Name: getHigh
Description: gets the high price some number of days ago
Parameter Descriptions: the number days to look back
Return Description: high price
*/
float StockRecord::getHigh(int daysAgo){
    return days[daysAgo].getHigh();
}

/*
Name: getClose
Description: gets the closing price some number of days ago
Parameter Descriptions: the number days to look back
Return Description: closing price
*/
float StockRecord::getClose(int daysAgo){
    return days[daysAgo].getClose();
}

/*
Name: getVolume
Description: gets the volume of trades on certain day
Parameter Descriptions: the number days to look back
Return Description: the volume of trades
*/
long long int StockRecord::getVolume(int daysAgo){
    return days[daysAgo].getVolume();
}

/*
Name: getDate
Description: gets the Date on certain day
Parameter Descriptions: the number days to look back
Return Description: Date object with the date
*/
string StockRecord::getDate(int daysAgo){
    return this->days[daysAgo].getDate();
}
/*
Name: destructor
Description:
Parameter Descriptions: 
Return Description: open price
*/
StockRecord::~StockRecord(){
    ;
}




