// TO FIX:
// Handling invalid location input or API bad responses
// Restructure the API request code: const for the API key for example

/*
Author: Abdul Rehman Zafar
Description: Cpp file for WeatherRecord representing weather information for a location
Date: 2020-11-04
*/

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

/*
Name: constructor
Description: initializes query to the weather API to initialize weather for requested location
Parameter Descriptions: location user wishes to know forecast for
Return Description:
*/
WeatherRecord::WeatherRecord(std::string location) {
    this->location = location;                      //initializes location

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
    }
    reply->deleteLater();
}
/*
Name: Copy constructor
Description: Constructs a WeatherRecord that references the days and location of the original WeatherRecord. This is a shallow copy.
Parameter Descriptions: wr2: the weather record being copied
Return Description: N/A
*/
WeatherRecord::WeatherRecord(const WeatherRecord &WR2){
    this->location = WR2.location;
    this->days = WR2.days;
}

/*
Name: converTempt
Description: Helper function that converts a temperature from celcius to farenheit
Parameter Descriptions: temp: the input temperature; from: a character representing the unit of the "temp" input: f for farenheit, c for celcius
Return Description: The temperature converted to the other format
*/

float WeatherRecord::convertTemp(float temp, char from){
    if (from == 'f'){
        return (temp-32)*5.0/9;
    }  else if (from == 'c') return (from * 9/5.0)+32;
   throw "Please specify either f or c";
   return -1;

}

/*
Name: destructor
Description: Deallocates memory allocated to the weather record
Parameter Descriptions: n/a
Return Description: n/a
*/
WeatherRecord::~WeatherRecord() {
    //TO BE IMPLEMENTED
}
/*
Name: getDays
Description: returns the days vector
Parameter Descriptions: N/A
Return Description: the days vector
*/
std::vector<DailyWeather> WeatherRecord::getDays() {
    return days;
}

/*
Name: getDescription
Description: returns verbal description of the forecast (i.e. cloudy)
Parameter Descriptions:
Return Description: the description of the forecast
*/
std::string WeatherRecord::getDescription() {
    //TO BE IMPLEMENTED;
    return "description";
}

/*
Name: getLocation
Description: returns location of the forecast
Parameter Descriptions: n/a
Return Description: the name of the location
*/
std::string WeatherRecord::getLocation() {
    return location;
}

/*
Name: getTempFahren
Description: returns the temperature for a specified day in Fahrenheit
Parameter Descriptions: an index representing which day the user wants the temperature for
Return Description: the temperature for that day in Fahrenheit
*/
float WeatherRecord::getTempFahren(int index) {
    return getDays()[index].getTempFaren();
}

/*
Name: getTempCelsius
Description: returns the temperature for a specified day in Celsius
Parameter Descriptions: an index representing which day the user wants the temperature for
Return Description: the temperature for that day in Celsius
*/
float WeatherRecord::getTempCelsius(int index) {
    //TO BE IMPLEMENTED
    return getDays()[index].getTempCelsius();
}

Date WeatherRecord::getDate(int index) {
    //TO BE IMPLEMENTED
    return getDays()[index].getDate();
}

string WeatherRecord::getDescription(int index){
    return getDays()[index].getDescription();
}

int WeatherRecord::getNumDays(){
        return getDays().size();
}
