/*
Author: Adam Miller
Description: Header file for WeatherRecord representing weather information for a location
Date: 2020-11-04
*/

#ifndef INC_3307FINALPROJECT_WEATHERRECORD_H
#define INC_3307FINALPROJECT_WEATHERRECORD_H

#include "string"
#include "vector"
#include "DailyWeather.h"
#include "Record.h"
/*!
 * \brief The WeatherRecord class holds weather data for one city
 *
 * The WeatherRecord class holds weather data in the form of DailyWeather for one city. It is also an interface for classes like WeatherWindow and WeatherCategory to interact with DailyWeather data without needed to know the underlying implementaation of DailyWeather
 *@author Adam Miller
 */
class WeatherRecord :public Record {
public:
    WeatherRecord(std::string location);
    WeatherRecord(const WeatherRecord &wr2);
    ~WeatherRecord();
    std::vector<DailyWeather> getDays();
    std::string getDescription();
    std::string getLocation();
    float getTempFahren(int index);
    float getTempCelsius(int index);
    float convertTemp(float temp, char from);
    Date getDate(int index);
    std::string getDescription(int index);
    int getNumDays();

private:
    std::string location; /*!<Name of the location that the weather record corresponds to*/
    std::vector<DailyWeather> days; /*!< vector of information on weather for several days*/
};


#endif //INC_3307FINALPROJECT_WEATHERRECORD_H
