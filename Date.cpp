/*
Author: Adam Miller
Description: Code file that defines a date record, holding information on day, month, and year
Date: 2020-11-04
*/
#include "Date.h"
#include <string>
#include <exception>
using namespace std;

/*!
 * \brief Date::Date constructor for date
 *
 * Constructs a Date object given a day, month, and year. Throws an exception if the date is invalid
 *
 * \param day a day between 0-31
 * \param month a month betwee 1-12;
 * \param year a year >0
 */
Date::Date(const int DAY, const int MONTH, const int YEAR) {
    // check that days, month, and year are not too small and that months is not greater than 12
    if (YEAR < 0 || MONTH < 1 || DAY < 1 || MONTH > 12)
        throw "Invalid date";

    // check days in January, March, May, July, August, October, December are not greater than 31
    if (DAY > 31 && (MONTH == 1 || MONTH == 3 || MONTH == 5 || MONTH == 7 || MONTH == 8 || MONTH == 10 || MONTH == 12))
        throw "Invalid date";

    // check days in April, June, September, November are not greater than 30
    if (DAY > 30 && (MONTH == 4 || MONTH == 6 || MONTH == 9 || MONTH == 11))
        throw "Invalid date";

    // check that days in february are not greater than 29 on leap years
    if (DAY > 29 && MONTH == 2 && YEAR % 4 == 0)
        throw "Invalid date";

    // check that days in february are not greater 28 on common years
    if (DAY > 28 && MONTH == 2 && YEAR % 4 != 0) {
        throw "Invalid date";
    }

    this->day = DAY;
    this->month = MONTH;
    this->year = YEAR;
}
/*!
 * \brief Date::Date constructor
 *
 * Default constructor - creates a Date with no member data.
 */
Date::Date(){

}


/*!
 * \brief Date::~Date destructor
 *
 * Destroys the date object - doesn't do anything as the Date object has no member data
 */
Date::~Date(){
    ;
}

/*!
 * \brief Date::getMonth getter for month
 *
 * Gets the month of the Date
 *
 * \return an int (1-12) representing the month of the Date
 */
int Date::getMonth() const{
    return this->month;
}

/*!
 * \brief Date::getDay getter for day
 *
 * returns the day of the Date
 *
 * \return an int (1-31) representing the day of the Date
 */
int Date::getDay() const{
    return this->day;
}

/*!
 * \brief Date::getYear getter for year
 *
 *returns the year of the Date
 *
 * \return an int > 0 representing the year of the Date
 */
int Date::getYear() const{
    return this->year;
}

/*!
 * \brief Date::getStr returns a string representation of the Date
 *
 * allows the representation of the date as a string, with the Format "Month Day, Year", e.g. February 28, 2019
 * \return the Date as a String in the format: Month (Written Out), Day, Year: February 28, 2019
 */
string Date::getStr() const{
    return this->monthName[this->month] + ' ' + to_string(this->day) + ", " + to_string(this->year); //dummy
}


/*!
 * \brief Date::getStr2 returns a string representation of the Date
 * allows the representation of the date as a string, with the Format "DD/MM/YYYY" , e.g. 01/01/2020

 * \return the Date as a String in the format: "DD/MM/YYYY" e.g. 05/12/1999
 */
string Date::getStr2() const{
    return to_string(this->day) + "/" + to_string(this->month)+ "/" +  to_string(this->year); //dummy
}
/*!
 * \brief Date::operator == overloaded = operator to determine if two Dates are the same
 *
 * Determines if Date s are the same, comapring on Year, Month, and Day
 *
 * \param other the Date being compared to
 * \return true if the Date s are equal, false otherwise
 */
bool Date::operator==(const Date& other){
    return this->year == other.getYear() && this->month == other.getMonth() && this->day == other.getDay();
}

/*!
 * \brief Date::operator != overloaded != operator to determine if two Dates are not the same
 *
 *  Determines if Date s are unequal, comparing on Year, Month, and Day
 *
 * \param other the Date being compared to
 * \return true if the Date s are unequal, false otherwise
 */
bool Date::operator!=(const Date& other){
    return this->year != other.getYear() || this->month != other.getMonth() || this->day != other.getDay();
}
