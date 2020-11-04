/*
Author: Adam Miller
Description: Code file that defines a date record, holding information on day, month, and year
Date: 2020-11-04
*/
#include "Date.h"
using namespace std;
/*
Name: Constructor
Description: Constructs a Date object given a day, month, and year
Parameter Descriptions: day: a day between 0-31; month: a month betwee 1-12; year a year >0
Return Description: N/A
*/
Date::Date(int day, int month, int year){
    //#TODO: [COMPSCI3307F2020GROUP32-22] In Date, have Error Checking to prevent dates like Feb 31, etc. 
    this->day = day;
    this->month=month;
    this->year = year;
}
/*
Name: Destructor 
Description: Destroys the date object
Parameter Descriptions: N/A
Return Description: N/A
*/
Date::~Date(){
    
}
/*
Name: getMonth 
Description: getter for month
Parameter Descriptions: N/A
Return Description: month; the Month of the Date
*/
int Date::getMonth(){
    return month;
}
/*
Name: getDay 
Description: getter for day 
Parameter Descriptions: N/A
Return Description: day, the Day of the Date
*/
int Date::getDay(){
    return day;
}
/* 
Name: getYear 
Description: getter for Year
Parameter Descriptions: N/A
Return Description: year; the year of the Date
*/
int Date::getYear(){
    return year;
}
/*
Name: getStr
Description: allows the representation of the date as a string, with the Format "Month, Day, Year", e.g. February 28, 2019 
Parameter Descriptions: N/A
Return Description: Returns the Date as a String in the format:
Month (Written Out), Day, Year: February 28, 2019
*/
string Date::getStr(){
    //#TODO: [COMPSCI3307F2020GROUP32-21] implement this
    return "hi"; //dummy
}