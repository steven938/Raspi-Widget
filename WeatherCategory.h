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
        void displayRecords(std::vector<WeatherRecord> toDisplay); // Print the specified records to the screen

        
    public:
    
        // Constructor to make instances of WeatherCategory class
        WeatherCategory();

        // Destructor
        ~WeatherCategory();

        // Function to get the records of the class 
        std::vector<WeatherRecord> getRecords();

        // Function to find a record of a specific location (specified by searchString)
        Record search(std::string searchString);

        // Sort the weather records currently stored in the private vector
        void sort(int type, bool ascend);
};
#endif
