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
Name: destructor
Description:
Parameter Descriptions: 
Return Description: open price
*/
StockRecord::~StockRecord(){
    ;
}




