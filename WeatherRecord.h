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
    WeatherRecord(const std::string LOCATION);
    WeatherRecord(const WeatherRecord &wr2);
    ~WeatherRecord();
    std::vector<DailyWeather> getDays() const;
    std::string getLocation() const;
    float getTempFahren(const int INDEX) const;
    float getTempCelsius(const int INDEX) const;
    Date getDate(const int INDEX) const;
    std::string getDescription(const int INDEX) const;
    int getNumDays() const;

private:
    std::string location; /*!<Name of the location that the weather record corresponds to*/
    std::vector<DailyWeather> days; /*!< vector of information on weather for several days*/
    float convertTemp(const float TEMP, const char FROM) const;

};


#endif //INC_3307FINALPROJECT_WEATHERRECORD_H
