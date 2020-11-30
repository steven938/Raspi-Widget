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
#include <iostream>
using namespace std;

/*
Name: constructor
Description: initializes query to the stock API to initialize stock information
Parameter Descriptions: 
Return Description: 
*/
StockRecord::StockRecord(string ticker){
    this->ticker = ticker;
    requestCompanyInfo();
    requestStockPrices();
    requestFinancials();
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
double StockRecord::getMarketCap(){
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
Name: getEBITShare
Description: gets EBIT/Share of the stock
Parameter Descriptions:
Return Description: EBIT/Share
*/
float StockRecord::getEBITShare(){
    return this->ebitShare;
}

/*
Name: getPayoutRatio
Description: gets Payout Ratio of the stock
Parameter Descriptions:
Return Description: Payout Ratio
*/
float StockRecord::getPayoutRatio(){
    return this->payoutRatio;
}

/*
Name: getCurrentRatio
Description: gets Current Ratio of the stock
Parameter Descriptions:
Return Description: Current Ratio
*/
float StockRecord::getCurrentRatio(){
    return this->currentRatio;
}

/*
Name: getGrossMargin
Description: gets Gross Margin of the stock
Parameter Descriptions:
Return Description: Gross Margin
*/
float StockRecord::getGrossMargin(){
    return this->grossMargin;
}


void StockRecord::requestStockPrices(){
    QNetworkRequest request;
    QString endpoint = "https://www.alphavantage.co/query?function=TIME_SERIES_DAILY_ADJUSTED&symbol=" + QString::fromStdString(this->ticker) + "&apikey=AI83R8IOLM46LIP2";

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
}

void StockRecord::requestCompanyInfo(){
    QNetworkRequest request;
    QString endpoint = "https://finnhub.io/api/v1/stock/profile2?symbol=" + QString::fromStdString(this->ticker) + "&token=bulhelv48v6p4m01r9jg";

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
        this->companyName = obj["name"].toString().toStdString();
        this->exchange = obj["exchange"].toString().toStdString();
        this->marketCap = obj["marketCapitalization"].toDouble() * 1000000;
        qDebug() << QString::fromStdString(this->companyName) << " " << QString::fromStdString(this->exchange) << " " << this->marketCap;
    }
    else // something went wrong
    {
        qDebug() << "Json File Failed to Parse : " << endpoint;
        qDebug() << "Error : " << reply->errorString();
    }
    reply->deleteLater();
}

void StockRecord::requestFinancials(){
    QNetworkRequest request;
    QString endpoint = "https://finnhub.io/api/v1/stock/metric?symbol=" + QString::fromStdString(this->ticker) + "&token=bulhelv48v6p4m01r9jg";

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

        QJsonObject metrics = obj["metric"].toObject();
        this->ebitShare = metrics["ebitdPerShareTTM"].toDouble();
        this->currentRatio = metrics["currentRatioAnnual"].toDouble();
        this->grossMargin = metrics["grossMarginTTM"].toDouble();
        this->payoutRatio = metrics["payoutRatioTTM"].toDouble();
        qDebug() << "Financials: " << ebitShare << "   " << currentRatio << "   " << grossMargin << "    " << payoutRatio << "\n";
    }
    else // something went wrong
    {
        qDebug() << "Json File Failed to Parse : " << endpoint;
        qDebug() << "Error : " << reply->errorString();
    }
    reply->deleteLater();
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




