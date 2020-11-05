/*
Author: Leland Conn
Description: Header file that defines a weather category, which holds weather records for each location and can act on that set of data
Date: 2020-11-04
*/
#ifndef WEATHER_CATEGORY_H
#define WEATHER_CATEGORY_H
#include <string>
#include "WeatherRecord.h"
#include "CategoryADT.h"
#include "vector.h"
class WeatherCategory: public CategoryADT{
    private:
        vector<WeatherRecord> records; // A vector to store all the weather records

        // Print the specified records to the screen
        void displayRecords(vector<WeatherRecord> toDisplay);
        
    public:
    
        // Constructor to make instances of WeatherCategory class
        WeatherCategory();

        // Destructor
        ~WeatherCategory();

        // Function to get the records of the class 
        vector<WeatherRecord> getRecords();

        // Function to find a record of a specific location (specified by searchString)
        WeatherRecord search(std::string searchString);

        // Sort the weather records currently stored in the private vector
        void sort(int type, bool ascend);
};
#endif