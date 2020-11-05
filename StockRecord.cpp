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
StockRecord::StockRecord(){

}

/*
Name: getTicker
Description: 
Parameter Descriptions: get the ticker name of the stock
Return Description: ticker
*/
string StockRecord::getTicker(){

}

/*
Name: getCompanyName
Description: gets the company name
Parameter Descriptions: 
Return Description: company name
*/
string StockRecord::getCompanyName(){

}

/*
Name: getExchange
Description: gets the exchange on which stock is traded on
Parameter Descriptions:
Return Description:
*/
string StockRecord::getExchange(){

}

/*
Name: getMarketCap
Description: gets market capitalization of the stock
Parameter Descriptions: 
Return Description: market cap
*/
float StockRecord::getMarketCap(){

}

/*
Name: getOpen
Description: gets the open price some number of days ago
Parameter Descriptions: the number days to look back
Return Description: open price
*/
float StockRecord::getOpen(int daysAgo){

}

/*
Name: getLow
Description: gets the low price some number of days ago
Parameter Descriptions: the number days to look back
Return Description: low price
*/
float StockRecord::getLow(int daysAgo){

}

/*
Name: getHigh
Description: gets the high price some number of days ago
Parameter Descriptions: the number days to look back
Return Description: high price
*/
float StockRecord::getHigh(int daysAgo){

}

/*
Name: getClose
Description: gets the closing price some number of days ago
Parameter Descriptions: the number days to look back
Return Description: closing price
*/
float StockRecord::getClose(int daysAgo){

}

/*
Name: getVolume
Description: gets the volume of trades on certain day
Parameter Descriptions: the number days to look back
Return Description: the volume of trades
*/
long long int StockRecord::getVolume(int daysAgo){

}


/*
Name: destructor
Description:
Parameter Descriptions: 
Return Description: open price
*/
StockRecord::~StockRecord(){

}




