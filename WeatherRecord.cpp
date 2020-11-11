/*
Author: Abdul Rehman Zafar
Description: Cpp file for WeatherRecord representing weather information for a location
Date: 2020-11-04
*/

#include "WeatherRecord.h"
#include "Date.h"
#include <string.h>
#include <iostream>
using namespace std;

/*
Name: constructor
Description: initializes query to the weather API to initialize weather for requested location
Parameter Descriptions: location user wishes to know forecast for
Return Description:
*/
WeatherRecord::WeatherRecord(std::string location) {
    this->location = location;
    //API CALL GOES HERE. Dummy data for now.
    for (int i = 0 ; i < 7 ; i++){
        int r = rand()%2;
        string desc;
        if (r == 0){
            desc = "Cloudy";
        }else desc = "Sunny";
        Date d(i+1,1,2020);
        DailyWeather dw(32, 0, desc, d);
    days.push_back(dw);

    }
    cerr<<"End WeatherRecord Constructor"<<endl;
}

WeatherRecord::WeatherRecord(const WeatherRecord &wr2){
    this->location = wr2.location;
}
/*
Name: destructor
Description:
Parameter Descriptions:
Return Description:
*/
WeatherRecord::~WeatherRecord() {

}

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
    return std::string();
}

/*
Name: getLocation
Description: returns location of the forecast
Parameter Descriptions:
Return Description: the name of the location
*/
std::string WeatherRecord::getLocation() {
    return std::string();
}

/*
Name: getTempFahren
Description: returns the temperature for a specified day in Fahrenheit
Parameter Descriptions: an index representing which day the user wants the temperature for
Return Description: the temperature for that day in Fahrenheit
*/
float WeatherRecord::getTempFahren(int index) {
    return 0;
}

/*
Name: getTempCelsius
Description: returns the temperature for a specified day in Celsius
Parameter Descriptions: an index representing which day the user wants the temperature for
Return Description: the temperature for that day in Celsius
*/
float WeatherRecord::getTempCelsius(int index) {
    return 0;
}
