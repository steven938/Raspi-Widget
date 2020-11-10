/*
Author: Leland Conn
Description: Header file that defines a weather category, which holds weather records for each location and can act on that set of data
Date: 2020-11-04
*/
#ifndef WEATHER_CATEGORY_H
#define WEATHER_CATEGORY_H
#include <string>
#include <vector>
#include "WeatherRecord.h"
#include "CategoryADT.h"
class WeatherCategory: public CategoryADT{
    private:
        std::vector<WeatherRecord> records; // A vector to store all the weather records

        // Print the specified records to the screen
        void displayRecords(std::vector<WeatherRecord> toDisplay);
        
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
