/*
Author: Leland Conn
Description: Code file that define an individual weather category
Date: 2020-11-04
*/
#include "WeatherCategory.h"
#include <iostream>
using namespace std;
/*
Name: WeatherCategory
Description: This is a constructor to create an instance of the WeatherCategory class
Parameter Descriptions: TBD
Return Description: N/A
*/
WeatherCategory::WeatherCategory(){
    

}
/*
Name: Destructor
Description: Destroys the object
Parameter Descriptions: N/A
Return Description: N/A
*/
WeatherCategory::~WeatherCategory(){

}
/*
Name: getRecords 
Description: Getter for the vector of records
Parameter Descriptions: N/A
Return Description: records, the vector holding weather records
*/
vector<WeatherRecord> WeatherCategory::getRecords(){
    cerr<<"in weatherRecord getRecords"<<endl;
    cerr<<records[0].getDays()[0].getTempCelsius()<<endl;
    return records;
}
/*
Name: search 
Description: Returns a desired weather record
Parameter Descriptions: N/A
Return Description: A WeatherRecord object or 0 if not found
*/
Record WeatherCategory::search(string searchString){
    // code to find and return the desired record
    cerr<<searchString<<endl;
    WeatherRecord * r = new WeatherRecord(searchString);
    records.push_back(*r);
    cerr << "end search method"<<endl;
    return *r;

}
/*
Name: sort 
Description: sort the weather records stored in vector records
Parameter Descriptions: integer type to identify the basis of the sort and boolean of ascending to know the order
Return Description: N/A
*/
void WeatherCategory::sort(int type, bool ascending){
    // code to sort the records
}
/*
Name: displayRecords 
Description: display the the records on the screen
Parameter Descriptions: N/A
Return Description: N/A
*/
void WeatherCategory::displayRecords(vector<WeatherRecord> toDisplay){
    // code to display records on screen
}
