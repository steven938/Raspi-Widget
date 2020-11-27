/*
Author: Leland Conn
Description: Code file that define the weather category, which is the container that holds weather records
Date: 2020-11-04
*/
#include <iostream>
#include "WeatherCategory.h"
using namespace std;

/*!
 * \brief WeatherCategory::WeatherCategory constructor
 *
 * This is a constructor to create an instance of the WeatherCategory class
 */
WeatherCategory::WeatherCategory(){
    //TO BE IMPLEMENTED
}
/*!
 *  \brief a destructor
 *
 * Destroys the object
 *
*/
WeatherCategory::~WeatherCategory(){
    //TO BE IMPLEMENTED
}
/*!
* \brief getRecords, getter for the vector of records
*
* returns the records vector
*  @return records, the vector holding weather records
*/
vector<WeatherRecord> WeatherCategory::getRecords(){
    return records;
}
/*!
* \brief search: returns a desired weather record representing weather in a given city
*
* Creates a weather record, passing the search string from the search bar to the new weather record. This will call the weather API and find information for a given city
*@param searchString a string that represents the city being searched for
* @return a weather record with the weather for the searched-for city
*
*/
Record WeatherCategory::search(string searchString){
    WeatherRecord * r = new WeatherRecord(searchString); //constructs a weather record, which calls the API
    records.push_back(*r);                               //adds the record to the records vector
    return *r;

}
//--------considering deleting the below
/*
Name: sort 
Description: sort the weather records stored in vector records
Parameter Descriptions: integer type to identify the basis of the sort and boolean of ascending to know the order
Return Description: N/A
*/
void WeatherCategory::sort(int type, bool ascending){
    // TO BE IMPLEMENTED: code to sort the records

}
/*
Name: displayRecords 
Description: display the the records on the screen
Parameter Descriptions: N/A
Return Description: N/A
*/
void WeatherCategory::displayRecords(vector<WeatherRecord> toDisplay){
    // TO BE IMPLEMENTED: code to display records on screen
}
