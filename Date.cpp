/*
Author: Adam Miller
Description: Code file that defines a date record, holding information on day, month, and year
Date: 2020-11-04
*/
#include "Date.h"
#include <string>
#include <exception>
using namespace std;
/*
Name: Constructor
Description: Constructs a Date object given a day, month, and year
Parameter Descriptions: day: a day between 0-31; month: a month betwee 1-12; year a year >0
Return Description: N/A
*/
Date::Date(int day, int month, int year) {
    // check that days, month, and year are not too small and that months is not greater than 12
    if (year < 0 || month < 1 || day < 1 || month > 12)
        throw "Invalid date";

    // check days in January, March, May, July, August, October, December are not greater than 31
    if (day > 31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12))
        throw "Invalid date";

    // check days in April, June, September, November are not greater than 30
    if (day > 30 && (month == 4 || month == 6 || month == 9 || month == 11))
        throw "Invalid date";

    // check that days in february are not greater than 29 on leap years
    if (day > 29 && month == 2 && year % 4 == 0)
        throw "Invalid date";

    // check that days in february are not greater 28 on common years
    if (day > 28 && month == 2 && year % 4 != 0) {
        throw "Invalid date";
    }

    this->day = day;
    this->month = month;
    this->year = year;
}
Date::Date(){

}
/*
Name: Destructor 
Description: Destroys the date object
Parameter Descriptions: N/A
Return Description: N/A
*/
Date::~Date(){
    ;
}
/*
Name: getMonth 
Description: getter for month
Parameter Descriptions: N/A
Return Description: month; the Month of the Date
*/
int Date::getMonth() const{
    return this->month;
}
/*
Name: getDay 
Description: getter for day 
Parameter Descriptions: N/A
Return Description: day, the Day of the Date
*/
int Date::getDay() const{
    return this->day;
}
/* 
Name: getYear 
Description: getter for Year
Parameter Descriptions: N/A
Return Description: year; the year of the Date
*/
int Date::getYear() const{
    return this->year;
}
/*
Name: getStr
Description: allows the representation of the date as a string, with the Format "Month, Day, Year", e.g. February 28, 2019 
Parameter Descriptions: N/A
Return Description: Returns the Date as a String in the format:
Month (Written Out), Day, Year: February 28, 2019
*/
string Date::getStr() const{
    return this->monthName[this->month] + '/' + to_string(this->day) + ", " + to_string(this->year); //dummy
}


/*
Name: getStr2
Description: allows the representation of the date as a string, with the Format "DD/MM/YYYY" , e.g. 01/01/2020
Parameter Descriptions: N/A
Return Description: Returns the Date as a String in the format:
Month (Written Out), Day, Year: February 28, 2019
*/
string Date::getStr2() const{
    return to_string(this->day) + "/" + to_string(this->month)+ "/" +  to_string(this->year); //dummy
}

bool Date::operator==(const Date& other){
    return this->year == other.getYear() && this->month == other.getMonth() && this->day == other.getDay();
}

bool Date::operator!=(const Date& other){
    return this->year != other.getYear() || this->month != other.getMonth() || this->day != other.getDay();
}
