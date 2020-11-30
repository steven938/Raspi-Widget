/*
Author: Leland Conn
Description: Header file that defines a weather category, which holds weather records for each location and can act on that set of data. Singleton.
Date: 2020-11-04
*/
#ifndef WEATHER_CATEGORY_H
#define WEATHER_CATEGORY_H
#include <string>
#include <vector>
#include "WeatherRecord.h"
#include "CategoryADT.h"
/*!
 * \brief The WeatherCategory class holds weather records for each location.
 *
 * The WeatherCategory class is a singleton that holds weather records for each location and can act on that set of data.
 *
 * @author Leland Conn
*/
class WeatherCategory: public CategoryADT{
    private:
        std::vector<WeatherRecord> records; /*!< A vector to store all the weather records*/

    public:
            // Constructor to make instances of WeatherCategory class
        WeatherCategory();

        // Destructor
        ~WeatherCategory();

        // Function to get the records of the class 
        std::vector<WeatherRecord> getRecords() const;

        // Function to find a record of a specific location (specified by searchString)
        Record search(const std::string SEARCH_STRING);

};
#endif
