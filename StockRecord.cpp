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


/*!
 * \brief StockRecord::StockRecord constructor
 *
 * Given a ticker symbol, creates a StockRecord and processes three API calls to get financial information
 *
 * \param ticker the ticker symbol for the stock
 */
StockRecord::StockRecord(const string TICKER){
    this->ticker = TICKER;
    try{                            //encapsulated in a try-catch block because all three calls need to work for the StockRecord to be successfully initialized. If any fail, then the StockRecord cannot be initailized
        requestCompanyInfo();       //gets information such as company name
        requestStockPrices();       //gets stock price
        requestFinancials();        //gets non-stock financial information, like gross margin
    }catch(...){
        throw "No stock with this ticker exists";
    }
}

/*!
 * \brief StockRecord::getTicker getter for ticker
 *
 * returns the ticker symbol for the stock
 *
 * \return the ticker, a string
 */
string StockRecord::getTicker() const{
    return ticker;
}


/*!
 * \brief StockRecord::getCompanyName getter for company name
 *
 * returns the company name, a string
 *
 * \return companyName, a string
 */
string StockRecord::getCompanyName()const{
    return companyName;
}

/*!
 * \brief StockRecord::getExchange getter for the exchange
 * \return the exchange where the stock is traded
 */
string StockRecord::getExchange()const{
    return exchange;
}

/*!
 * \brief StockRecord::getMarketCap getter for market cap
 *
 *
 * \return the market capitalization of the stock, defined as (num shares * stock price)
 */
double StockRecord::getMarketCap() const{
    return this->marketCap;
}

/*!
 * \brief StockRecord::getOpen getter of the open price of the stock x days ago
 * \param DAYS_AGO the number of days before the current day to look
 * \return the open price DAYS_AGO days ago, from the DailyStock for DAYS_AGO days
 */
float StockRecord::getOpen(const int DAYS_AGO) const{
    return days[DAYS_AGO].getOpen();
}

/*!
 * \brief StockRecord::getLow gets the low price some number of days ago
 *
 * Gets the low price of the DailyStock representing DAYS_AGO days ago
 *
 * \param DAYS_AGO the number of days before the current day to look
 * \return the low price DAYS_AGO days ago, from the DailyStock for that day
 */
float StockRecord::getLow(const int DAYS_AGO) const{
    return days[DAYS_AGO].getLow();
}

/*!
 * \brief StockRecord::getHigh gets the high price some number of days ago
 *
 *
 * Gets the high price of the DailyStock representing DAYS_AGO days ago
 *
 * \param DAYS_AGO the number of days before the current day to look
 * \return the high price DAYS_AGO days ago, from the DailyStock for that day
 */
float StockRecord::getHigh(const int DAYS_AGO)const{
    return days[DAYS_AGO].getHigh();
}


/*!
 * \brief StockRecord::getLow gets the low price some number of days ago
 *
 *
 * Gets the low price of the DailyStock representing DAYS_AGO days ago
 *
 * \param DAYS_AGO the number of days before the current day to look
 * \return the low price DAYS_AGO days ago, from the DailyStock for that day
 */
float StockRecord::getClose(const int DAYS_AGO) const{
    return days[DAYS_AGO].getClose();
}

/*!
 * \brief StockRecord::getVolume gets the volume of trades of the stock on a given day
 *
 * Gets the number of trades that occured for a given stock on a given day (represented by a DailyStock)
 *
 * \param DAYS_AGO  the number of days before the current day to look
 * \return the volume of trades DAYS_AGO days
 */
long long int StockRecord::getVolume(const int DAYS_AGO) const{
    return days[DAYS_AGO].getVolume();
}



/*!
 * \brief StockRecord::getDate gets the date DAYS_AGO days ago
 * \param DAYS_AGO the number of days before the current day to look
 * \return the date DAYS_AGO days ago
 */
string StockRecord::getDate(const int DAYS_AGO) const{
    return this->days[DAYS_AGO].getDate();
}

/*!
 * \brief StockRecord::getEBITShare getter for the EBIT/Share of the stock
 * \return the EBIT/Share of the stock (Earnings before interest and tax)
 */
float StockRecord::getEBITShare()const{
    return this->ebitShare;
}

/*!
 * \brief StockRecord::getPayoutRatio getter for the payout ratio (divided/earnings) of the stock
 * \return the payout ratio of the stock
 */
float StockRecord::getPayoutRatio()const{
    return this->payoutRatio;
}

/*!
 * \brief StockRecord::getCurrentRatio getter for the current ratio (current assets/current liabilities) of the stock
 * \return the current ratio of the stock
 */
float StockRecord::getCurrentRatio()const{
    return this->currentRatio;
}

/*!
 * \brief StockRecord::getGrossMargin getter for the gross margin (gross profits/revenues) of the stock
 * \return the gross margin of the stock
 */
float StockRecord::getGrossMargin()const{
    return this->grossMargin;
}

/*!
 * \brief StockRecord::requestStockPrices API call to get stock prices
 *
 * Private helper function that makes an API call to determine stock price information, such as open, close, high, and low.
 *
 */
void StockRecord::requestStockPrices(){
    QNetworkRequest request;
    //set up the API call
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
        throw "API Call Failed - no stock with this ticker";
    }
    reply->deleteLater();
}
/*!
 * \brief StockRecord::requestCompanyInfo API call to get Company info
 *
 *
 *
 * Private helper function that makes an API call to determine company information, such as name and exchange
 *
 */
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
        throw "API Call Failed - no stock with this ticker";

    }
    reply->deleteLater();
}
/*!
 * \brief StockRecord::requestFinancials API call to get financial information
 *
 * Private helper function that makes an API call to determine financials, such as EBIT per share, gross margin, and payout ratio
 *
 */


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
        if (ebitShare == 0 && currentRatio == 0 && grossMargin == 0 && payoutRatio ==0){
            throw "API Call failed - no stock with this ticker";
        }
        qDebug() << "Financials: " << ebitShare << "   " << currentRatio << "   " << grossMargin << "    " << payoutRatio << "\n";
    }
    else // something went wrong
    {
        qDebug() << "Json File Failed to Parse : " << endpoint;
        qDebug() << "Error : " << reply->errorString();
        throw "API Call Failed - no stock with this ticker";

    }
    reply->deleteLater();
}

/*!
 * \brief StockRecord::~StockRecord desctructor
 *
 * Does not do anything, since StockRecord does not manage dynamic memory
 *
 */
StockRecord::~StockRecord(){
    ;
}




