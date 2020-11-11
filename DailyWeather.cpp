/*
Author: Abdul Rehman Zafar
Description: Cpp file for DailyWeather representing daily weather forecast
Date: 2020-11-04
*/

#include "DailyWeather.h"
#include "Date.h"
#include <iostream>
using namespace std;
/*
Name: constructor
Description: Constructs the daily weather record with information on temperature, description, and date
Parameter Descriptions: temperature in Fahrenheit and Celsius, and the description/date of the forecast
Return Description:
*/
DailyWeather::DailyWeather(float tempFaren, float tempCelsius, std::string description, Date date) {
        this->tempFaren = tempFaren;
        this->tempCelsius = tempCelsius;
        this-> description = description;
        this->date = date;
    cerr<<"From DailyWeather constructor"<<endl;
}

//copy constrtuctor
/*DailyWeather::DailyWeather(const DailyWeather &dw2){
    cerr <<"From DW Copy Constructor before"<<endl;
    this->tempFaren = dw2.tempFaren;
    cerr <<"From DW Copy Constructor 1"<<endl;

    tempCelsius = dw2.tempCelsius;
    cerr <<"From DW Copy Constructor 2"<<endl;

    description = dw2.description;
    cerr <<"From DW Copy Constructor 3"<<endl;

    date = dw2.date;
    cerr <<"From DW Copy Constructor"<<endl;
*/
/*
Name: destructor
Description:
Parameter Descriptions:
Return Description:
*/
DailyWeather::~DailyWeather() {

}

/*
Name: getTempFahren
Description: returns the temperature for the day in Fahrenheit
Parameter Descriptions:
Return Description: the temperature for that day in Fahrenheit
*/
float DailyWeather::getTempFaren() {
    return tempFaren;
}

/*
Name: getTempCelsius
Description: returns the temperature for the day in Celsius
Parameter Descriptions:
Return Description: the temperature for that day in Celsius
*/
float DailyWeather::getTempCelsius() {
    return tempCelsius;
}

/*
Name: getDescription
Description: returns verbal description of the forecast (i.e. cloudy)
Parameter Descriptions:
Return Description: the description of the forecast
*/
std::string DailyWeather::getDescription() {
    return description;
}

/*
Name: getDate
Description: gets the date of the forecast
Parameter Descriptions:
Return Description: the date of the forecast
*/
Date DailyWeather::getDate() {
    return date;
}
