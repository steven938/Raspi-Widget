/*
Author: Abdul Rehman Zafar
Description: Header file for DailyWeather representing daily weather forecast
Date: 2020-11-04
*/

#ifndef INC_3307FINALPROJECT_DAILYWEATHER_H
#define INC_3307FINALPROJECT_DAILYWEATHER_H
#include "Date.h"
#include "string"

class DailyWeather {
private:
    float tempFaren; // temperature in Fahrenheit
    float tempCelsius; // temperature in Celsius
    std::string description; // verbal description of the weather (i.e. cloudy)
    Date date; // the date // date of the weather
public:
    DailyWeather(float tempCelsius,float tempFaren,std::string description);
    ~DailyWeather();
    float getTempFaren();
    float getTempCelsius();
    std::string getDescription();
    Date getDate();
};


#endif //INC_3307FINALPROJECT_DAILYWEATHER_H

