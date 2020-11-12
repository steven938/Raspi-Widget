/*
Author: Leland Conn
Description: Code file that define the weather category, which is the container that holds weather records
Date: 2020-11-04
*/
#include <iostream>
#include "WeatherCategory.h"
using namespace std;
/*
Name: WeatherCategory
Description: This is a constructor to create an instance of the WeatherCategory class
Parameter Descriptions: TBD
Return Description: N/A
*/
WeatherCategory::WeatherCategory(){
    //TO BE IMPLEMENTED
}
/*
Name: Destructor
Description: Destroys the object, deallocating memory
Parameter Descriptions: N/A
Return Description: N/A
*/
WeatherCategory::~WeatherCategory(){
    //TO BE IMPLEMENTED
}
/*
Name: getRecords 
Description: Getter for the vector of records
Parameter Descriptions: N/A
Return Description: records, the vector holding weather records
*/
vector<WeatherRecord> WeatherCategory::getRecords(){
    return records;
}
/*
Name: search 
Description: Returns a desired weather record
Parameter Descriptions: N/A
Return Description: A WeatherRecord object or 0 if not found
*/
Record WeatherCategory::search(string searchString){
    WeatherRecord * r = new WeatherRecord(searchString); //constructs a weather record, which calls the API
    records.push_back(*r);                               //adds the record to the records vector
    return *r;

}
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
