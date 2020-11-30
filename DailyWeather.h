/*
Author: Abdul Rehman Zafar
Description: Header file for DailyWeather representing daily weather forecast
Date: 2020-11-04
*/

#ifndef INC_3307FINALPROJECT_DAILYWEATHER_H
#define INC_3307FINALPROJECT_DAILYWEATHER_H
#include <string>
#include "Date.h"


/*!
 * \brief The DailyWeather class describes the weather in a given location on a single day
 *
 * DailyWeather describes the weather forecast for a given location on a single day, including temperature in farenheit and celsius and description.
 *
 */
class DailyWeather {
private:
    float tempFaren;             /*!< temperature in Fahrenheit*/
    float tempCelsius;           /*!< temperature in Celsius*/
    std::string description;     /*!< verbal description of the weather (i.e. cloudy)*/
    Date date;                   /*!< date that the Daily Weather describes*/
public:
    DailyWeather(const float TEMPFAREN, const float TEMPCELSIUS, const std::string DESCRIPTION, const Date DATEIN);
    ~DailyWeather();
    float getTempFaren() const;
    float getTempCelsius() const;
    std::string getDescription() const;
    Date getDate() const;
};


#endif //INC_3307FINALPROJECT_DAILYWEATHER_H

