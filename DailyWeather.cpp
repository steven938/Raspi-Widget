/*
Author: Abdul Rehman Zafar
Description: Cpp file for DailyWeather representing daily weather forecast
Date: 2020-11-04
*/
#include <iostream>

#include "DailyWeather.h"
#include "Date.h"
using namespace std;

/*!
 * \brief DailyWeather::DailyWeather constructs a DailyWeather
 *
 * Constructs a DailyWeather with temperatures in Fahrenheit and Celsius, Date, and Description
 *
 * \param TEMPFAREN const, the temperature in fahrenheit on this day for the location
 * \param TEMPCELSIUS const, the temperature in celsius on this day for the location
 * \param DESCRIPTION const, the description of the weather (i.e. cloudy" for the day for the location
 * \param DATEIN const, the Date of the DailyWeather.
 */
DailyWeather::DailyWeather(const float TEMPFAREN, const float TEMPCELSIUS, const std::string DESCRIPTION, const Date DATEIN) {
    this->tempFaren = TEMPFAREN;
    this->tempCelsius = TEMPCELSIUS;
    this->description = DESCRIPTION;
    date = DATEIN;
}

/*!
 * \brief DailyWeather::~DailyWeather destructor
 *
 * Destructor for DailyWeather. Does not do anything, as there is no dynamically allocated memory to free
 */
DailyWeather::~DailyWeather() {
}

/*
Name: getTempFahren
Description: returns the temperature for the day in Fahrenheit
Parameter Descriptions:
Return Description: the temperature for that day in Fahrenheit
*/
/*!
 * \brief DailyWeather::getTempFaren getter for tempFaren
 *
 * returns the temperature for the DailyWeather in Fahrenheit
 *
 * \return the temperature for the day in Fahrenheit
 */
float DailyWeather::getTempFaren() const {
    return tempFaren;
}


/*!
 * \brief DailyWeather::getTempCelsius getter for tempCelsius
 *
 * returns the temperature for the DailyWeather in Celsius
 *
 * \return the temperature for the day in celsius
 */
float DailyWeather::getTempCelsius() const{
    return tempCelsius;
}

/*!
 * \brief DailyWeather::getDescription getter for description
 *
 * returns the verbal desription of the forecast (i.e. cloudy)
 *
 * \return the description of the forecast for this DailyWeather
 */
std::string DailyWeather::getDescription() const{
    return description;
}

/*!
 * \brief DailyWeather::getDate getter for date
 *
 * returns the Date of this DailyWeather
 *
 * \return the Date of this DailyWeather
 */
Date DailyWeather::getDate() const{
    return date;
}
