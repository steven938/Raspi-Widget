/*
Author: Steven Chen
Description: Header file for StockRecord representing information about a single stock/company
Date: 2020-11-04
*/
#ifndef STOCKRECORD_H
#define STOCKRECORD_H

#include "string"
#include "vector"
#include "DailyStock.h"

class StockRecord{
public:
	StockRecord();
	std::string getTicker();
	std::string getCompanyName();
	std::string getExchange();
	float getMarketCap();
	float getOpen(int daysAgo);
	float getLow(int daysAgo);
	float getHigh(int daysAgo);
	float getClose(int daysAgo);
	long long int getVolume(int daysAgo);
	~StockRecord();
private:
	std::string ticker; // 4 letter ticker
	std::string companyName; // company name
	std::string maretCap; 
	std::string exchange;
	std::vector<DailyStock> days; // vector of information on stock price on several dates
};

#endif