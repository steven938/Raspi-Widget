/*
Author: Leland Conn
Description: Code file that define the weather category, which is the container that holds weather records
Date: 2020-11-04
*/
#include <iostream>
#include "WeatherCategory.h"
using namespace std;

/*!
 * \brief WeatherCategory::WeatherCategory constructor creates a WeatherCategory object.
 *
 * This is a constructor to create an instance of the WeatherCategory class. Included for completeness, does not perform operations
 */
WeatherCategory::WeatherCategory(){

}
/*!
 * \brief WeatherCategory::~WeatherCategory destructor destroys a WeatherCategory object
 *
 * Since WeatherCategory has no dynamically allocated memory, this does not do anything. Included for completeness.
 */
WeatherCategory::~WeatherCategory(){

}
/*!
* \brief getRecords, getter for the vector of Record s
*
* returns the records vector
*  @return records, the vector holding WeatherRecord s
*/
vector<WeatherRecord> WeatherCategory::getRecords() const{
    return records;
}
/*!
* \brief search: returns a desired weather record representing weather in a given city
*
* Creates a weather record, passing the search string from the search bar to the new weather record. This will call the weather API and find information for a given city
* @param searchString a string that represents the city being searched for
* @return a weather record with the weather for the searched-for city
*
*/
Record WeatherCategory::search(const string SEARCH_STRING){
    WeatherRecord r(SEARCH_STRING); //constructs a weather record, which calls the API; just make this return a record, not a pointer.
    records.push_back(r);                               //adds the record to the records vector
    return r;

}

