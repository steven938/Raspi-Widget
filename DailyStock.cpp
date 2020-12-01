/*
Author: Steven Chen
Description: Code file implmeneting the class that stores information on stock on a given day
Date: 2020-11-04
*/
#include "DailyStock.h"
#include "Date.h"
#include <string>

using namespace std;


/*!
 * \brief DailyStock::DailyStock constructor
 *
 * Constructs a DailyStock, assigning stock prices, volume, and Date
 *
 * \param OPEN const, the opening price of the stock
 * \param CLOSE const, the closing price of the stock
 * \param HIGH const, the high price of the stock for the day
 * \param LOW const, the low price of the stock for the day
 * \param VOLUME const, the volume of trades for the stock for that day
 * \param DATE const, the date of the DailyStock
 */
DailyStock::DailyStock(const float OPEN, const float CLOSE, const float HIGH,const float LOW, const long long int VOLUME,const Date DATE){
    this->open = OPEN;
    this->close = CLOSE;
    this->high = HIGH;
    this->low = LOW;
    this->volume = VOLUME;
    this->date = DATE;
}

/*!
 * \brief DailyStock::getOpen getter for open
 * \return the open price for the stock on this Date
 */
float DailyStock::getOpen() const{
	return this->open;
}


/*!
 * \brief DailyStock::getClose getter for close
 * \return the close price for the stock on this Date
 */
float DailyStock::getClose() const{
	return this->close;
}

/*!
 * \brief DailyStock::getHigh getter for high
 * \return the high price of the stock on this Date
 */
float DailyStock::getHigh() const{
	return this->high;
}


/*!
 * \brief DailyStock::getLow getter for low
 * \return the low price of the stock on this Date
 */
float DailyStock::getLow() const{
	return this->low;
}

/*!
 * \brief DailyStock::getVolume getter for volume
 * \return the volume of trades for this stock on this Date
 */
long long int DailyStock::getVolume() const{
	return this->volume;
}


/*!
 * \brief DailyStock::getDate getss a string representation of the date of the stock
 * \return the date, in DD/MM/YYYY format, as a string
 */
string DailyStock::getDate() const{
    return this->date.getStr2();
}

/*!
 * \brief DailyStock::~DailyStock destructor
 *
 * doesn't do anything, because DailyStock does not allocate dynamic memory
 *
 */
DailyStock::~DailyStock(){
	;
}
