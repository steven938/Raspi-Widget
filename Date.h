/*
Author: Adam Miller
Description: Header file that defines a date record, holding information on day, month, and year
Date: 2020-11-04
*/
#ifndef DATE_H
#define DATE_H
#include <string>
#include <vector>
/*!
 * \brief The Date class describes a Date
 *
 * The Date class describes a Date, holding information on day, month, and year
 * @author Adam Miller
 * @date 2020-11-04
 */
class Date{
private:    
    int month; /*!< month is an int from 1-12*/
    int day; /*!< day is an int from 1-31 */
    int year; /*!< year is an int>0 */
    std::vector<std::string> monthName = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"}; /*!< Vector representing the names of each month*/
public:
    Date();
    Date(const int, const int, const int);
    ~Date();
    int getMonth() const;
    int getDay() const;
    int getYear() const;
    std::string getStr() const;
    std::string getStr2() const;
    bool operator==(const Date& other);
    bool operator!=(const Date& other);
};
#endif
