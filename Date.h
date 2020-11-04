/*
Author: Adam Miller
Description: Header file that defines a date record, holding information on day, month, and year
Date: 2020-11-04
*/
#ifndef DATE_H
#define DATE_H
#include <string>
class Date{
private:    
    int month, day, year; //month is an int from 1-12, day is an int from 1-31, year is an int>0
public:
    Date();
    Date(int, int, int);
    ~Date();
    int getMonth();
    int getDay();
    int getYear();
    std::string getStr();
};
#endif