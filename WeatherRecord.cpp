// TO FIX:
// Handling invalid location input or API bad responses
// Restructure the API request code: const for the API key for example

#include "WeatherRecord.h"
#include "Date.h"
#include <string.h>
#include <iostream>
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
 * \brief WeatherRecord::WeatherRecord creates a WeatherRecord for a given city
 *
 *  Initializes query to the weather API to initialize weather for requested location, creates a WeatherRecord with 5 days of Weather data (in the form of DailyWeather) for that day
 * \param location
 */
WeatherRecord::WeatherRecord(const std::string LOCATION) {
    this->location = LOCATION;                      //initializes location

    QNetworkRequest request;
    QString endpoint = "https://api.openweathermap.org/data/2.5/forecast?cnt=40&units=imperial&q=" + QString::fromStdString(location) + "&appid=26387a928cb676aab24801bcc3d40f69";

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

        QJsonArray weatherReports = obj["list"].toArray();

        Date prevDate;
        int tempSum = 0;
        int count = 0;
        QString description;

        for(int i=0;i<40;i++){
            QJsonObject report = weatherReports.at(i).toObject();
            string dateText = report["dt_txt"].toString().toStdString();

            int year = stoi(dateText.substr(0, 4));
            int month = stoi(dateText.substr(5, 2));
            int day = stoi(dateText.substr(8, 2));

            Date curDate(day, month, year);
            description = report["weather"].toArray().at(0).toObject()["description"].toString();

            if(i==0){
                prevDate = curDate;
            }

            if(prevDate != curDate){
                float avgTemp = tempSum/count;

                days.emplace_back(avgTemp, convertTemp(avgTemp,'f'), description.toStdString(), prevDate);

                tempSum = 0;
                count = 0;
                prevDate = curDate;
            }

            double tempFaren = report["main"].toObject()["temp"].toDouble();
            tempSum += tempFaren;
            count += 1;
        }
        float avgTemp = tempSum/count;
        days.emplace_back(avgTemp, convertTemp(avgTemp,'f'), description.toStdString(), prevDate);

    }
    else // something went wrong
    {
        // ADD Error Box
        qDebug() << "Json File Failed to Parse : " << endpoint;
        qDebug() << "Error : " << reply->errorString();
        throw "API Request Failed";
    }
    reply->deleteLater();
}

/*!
 * \brief WeatherRecord::WeatherRecord Shallow Copy constructor
 *
 * Constructs a WeatherRecord that references the days and location of the original WeatherRecord. This is a shallow copy.
 * \param WR2 the WeatherRecord that is being copied
 */
WeatherRecord::WeatherRecord(const WeatherRecord &WR2){
    this->location = WR2.location;
    this->days = WR2.days;
}

/*!
 * \brief WeatherRecord::convertTemp convertes temperatures from celsius to fahrenheit
 *
 * Private Helper function that converts a temperature from celcius to farenheit
 * \param TEMP const, the temperature being converted
 * \param FROM const, 'f' if TEMP is in fahrenheit, 'c' if TEMPT is in celcius
 * \return the converted temperature on success, -1 on failure
 */
float  WeatherRecord::convertTemp(const float TEMP, const char FROM) const{
    if (FROM == 'f'){
        return (TEMP-32)*5.0/9;
    }  else if (FROM == 'c') return (FROM * 9/5.0)+32;
    throw "Please specify either f or c";
    return -1;

}

/*!
 * \brief WeatherRecord::~WeatherRecord destructor
 *
 * WeatherRecord has no dynamic memory to deallocate, so nothing is done here.
 */
WeatherRecord::~WeatherRecord() {

}

/*!
 * \brief WeatherRecord::getDays getter for days
 * \return days, the days vector of DailyWeather
 */
std::vector<DailyWeather> WeatherRecord::getDays() const {
    return days;
}

/*!
 * \brief WeatherRecord::getLocation getter for location
 * \return location, the city that the WeatherRecord describes
 */
std::string WeatherRecord::getLocation() const{
    return location;
}

/*
Name: getTempFahren
Description: returns the temperature for a specified day in Fahrenheit
Parameter Descriptions: an index representing which day the user wants the temperature for
Return Description: the temperature for that day in Fahrenheit
*/
/*!
 * \brief WeatherRecord::getTempFahren getter for the temperature in farenheit of a specific day
 *
 * Getter for the fahrenheit temperature of a specific day, specified by INDEX,
 *
 * \param INDEX const, the index of the day that is being returned
 * \return the fahrenheit temperature of the day specificed by INDEX
 */
float WeatherRecord::getTempFahren(const int INDEX) const {
    return getDays()[INDEX].getTempFaren();
}

/*!
 * \brief WeatherRecord::getTempCelsius getter for the temperature in celsius of a specific day
 *
 * Getter for the celsius temperature of a specific day, specified by INDEX,
 *
 * \param INDEX const, the index of the day that is being returned
 * \return the celsius temperature of the day specificed by INDEX
 */
float WeatherRecord::getTempCelsius(const int INDEX) const {
    return getDays()[INDEX].getTempCelsius();
}

/*!
 * \brief WeatherRecord::getDate returns the Date of a specific DailyWeather
 *
 * returns the Date of one DailyWeather, specified by Index
 *
 * \param INDEX const, the index of the DailyWeather whose Date is being returned
 * \return the Date of the specified day (DailyWeather)
 */
Date WeatherRecord::getDate(const int INDEX) const {
    return getDays()[INDEX].getDate();
}

string WeatherRecord::getDescription(const int INDEX) const{
    return getDays()[INDEX].getDescription();
}
/*!
 * \brief WeatherRecord::getNumDays returns the number of days of data for this location
 *
 * Returns the number of DailyWeather of data that is available for this WeatherRecord
 *
 * \return the size of the days array
 */
int WeatherRecord::getNumDays() const{
    return getDays().size();
}
