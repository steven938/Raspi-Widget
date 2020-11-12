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
    this->location = location;                      //initializes location
    //API call will go here in future stage. The for loop generates dummy data.
    for (int i = 0 ; i < 7 ; i++){
        int r = rand()%2;
        string desc;
        if (r == 0){
            desc = "Cloudy";
        }else desc = "Sunny";
        Date d(i+1,1,2020);
        int tempFaren =  rand()%50+32;
        DailyWeather dw(tempFaren, convertTemp(tempFaren,'f') , desc, d);
        days.push_back(dw);
    }
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
    //TO BE IMPLEMENTED
    return 0;
}

/*
Name: getTempCelsius
Description: returns the temperature for a specified day in Celsius
Parameter Descriptions: an index representing which day the user wants the temperature for
Return Description: the temperature for that day in Celsius
*/
float WeatherRecord::getTempCelsius(int index) {
    //TO BE IMPLEMENTED
    return 0;
}
