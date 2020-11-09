/*
Author: Abdul Rehman Zafar
Description: Header file for WeatherRecord representing weather information for a location
Date: 2020-11-04
*/

#ifndef INC_3307FINALPROJECT_WEATHERRECORD_H
#define INC_3307FINALPROJECT_WEATHERRECORD_H

#include "string"
#include "vector"
#include "DailyWeather.h"

class WeatherRecord {
public:
    WeatherRecord(std::string location);
    ~WeatherRecord();
    std::string getDescription();
    std::string getLocation();
    float getTempFahren(int index);
    float getTempCelsius(int index);

private:
    std::string location; // name of the location
    std::vector<DailyWeather> days; // vector of information on weather for several days
};


#endif //INC_3307FINALPROJECT_WEATHERRECORD_H
