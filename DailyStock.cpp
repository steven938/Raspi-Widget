/*
Author: Steven Chen
Description: Code file implmeneting the class that stores information on stock on a given day
Date: 2020-11-04
*/
#include "DailyStock.h"
#include "Date.h"
#include <string>

using namespace std;

/*
Name: Constructor
Description: Constructs the daily stock record with information on stock price, volume on given day
Parameter Descriptions: open price, closing price, high price, low price, trade volume, string representing the date 
Return Description: N/A
*/
DailyStock::DailyStock(float open, float close, float high, float low, long long int volume, Date date){
	this->open = open;
	this->close = close;
	this->high = high;
	this->low = low;
	this->volume = volume;
	// To do: set date
}

/*
Name: getOpen
Description: gets the opening price of stock on this date
Parameter Descriptions: 
Return Description: opening price
*/
float DailyStock::getOpen(){
	return this->open;
}


/*
Name: getClose
Description: gets the closing price of stock on this date
Parameter Descriptions: 
Return Description: 
*/
float DailyStock::getClose(){
	return this->close;
}

/*
Name: getHigh
Description: gets the high price of stock on this date
Parameter Descriptions: 
Return Description: 
*/
float DailyStock::getHigh(){
	return this->high;
}

/*
Name: getLow
Description: gets the low price of the stock on this date
Parameter Descriptions: 
Return Description: 
*/
float DailyStock::getLow(){
	return this->low;
}

/*
Name: getVolume
Description: gets the volume of trades for the stock on this date
Parameter Descriptions:
Return Description: volume
*/
long long int DailyStock::getVolume(){
	return this->volume;
}

/*
Name: getDate
Description: gets the volume of trades for the stock on this date
Parameter Descriptions:
Return Description: volume
*/
string DailyStock::getDate(){
    return this->date.getStr2();
}


/*
Name: Destructor
Description: Destroys the object
Parameter Descriptions: 
Return Description: 
*/
DailyStock::~DailyStock(){
	;
}
