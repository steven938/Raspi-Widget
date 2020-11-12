/*
Author: Steven Chen
Description: Cpp file for StockRecord representing information about a single stock/company
Date: 2020-11-04
*/

#include "StockRecord.h"
#include "Date.h"
#include <string.h>

using namespace std;

/*
Name: constructor
Description: initializes query to the stock API to initialize stock information
Parameter Descriptions: 
Return Description: 
*/
StockRecord::StockRecord(string ticker){
    this->ticker = ticker;
    // API Call goes here, dummy data for now
    this->companyName = "Apple";
    this->exchange = "NASDAQ";
    this->marketCap = "2.03T";
    DailyStock ds1(117.19,119.63,116.44,119.49,109791495,Date(11,11,2020));
    DailyStock ds2(115.55,117.59,114.13,115.97,137656000,Date(10,11,2020));
    DailyStock ds3(120.50,121.99,116.05,116.32,154515300,Date(9,11,2020));
    DailyStock ds4(118.32,119.20,116.13,118.69,114457900,Date(6,11,2020));
    DailyStock ds5(117.95,119.62,116.87,119.03,126387100,Date(5,11,2020));
    this->days.push_back(ds1);
    this->days.push_back(ds2);
    this->days.push_back(ds3);
    this->days.push_back(ds4);
    this->days.push_back(ds5);


}

/*
Name: getTicker
Description: 
Parameter Descriptions: get the ticker name of the stock
Return Description: ticker
*/
string StockRecord::getTicker(){
    return ticker;
}

/*
Name: getCompanyName
Description: gets the company name
Parameter Descriptions: 
Return Description: company name
*/
string StockRecord::getCompanyName(){
    return companyName;
}

/*
Name: getExchange
Description: gets the exchange on which stock is traded on
Parameter Descriptions:
Return Description:
*/
string StockRecord::getExchange(){
    return exchange;
}

/*
Name: getMarketCap
Description: gets market capitalization of the stock
Parameter Descriptions: 
Return Description: market cap
*/
string StockRecord::getMarketCap(){
    return this->marketCap;
}

/*
Name: getOpen
Description: gets the open price some number of days ago
Parameter Descriptions: the number days to look back
Return Description: open price
*/
float StockRecord::getOpen(int daysAgo){
    return days[daysAgo].getOpen();
}

/*
Name: getLow
Description: gets the low price some number of days ago
Parameter Descriptions: the number days to look back
Return Description: low price
*/
float StockRecord::getLow(int daysAgo){
    return days[daysAgo].getLow();
}

/*
Name: getHigh
Description: gets the high price some number of days ago
Parameter Descriptions: the number days to look back
Return Description: high price
*/
float StockRecord::getHigh(int daysAgo){
    return days[daysAgo].getHigh();
}

/*
Name: getClose
Description: gets the closing price some number of days ago
Parameter Descriptions: the number days to look back
Return Description: closing price
*/
float StockRecord::getClose(int daysAgo){
    return days[daysAgo].getClose();
}

/*
Name: getVolume
Description: gets the volume of trades on certain day
Parameter Descriptions: the number days to look back
Return Description: the volume of trades
*/
long long int StockRecord::getVolume(int daysAgo){
    return days[daysAgo].getVolume();
}

/*
Name: getDate
Description: gets the Date on certain day
Parameter Descriptions: the number days to look back
Return Description: Date object with the date
*/
string StockRecord::getDate(int daysAgo){
    return this->days[daysAgo].getDate();
}
/*
Name: destructor
Description:
Parameter Descriptions: 
Return Description: open price
*/
StockRecord::~StockRecord(){
    ;
}




