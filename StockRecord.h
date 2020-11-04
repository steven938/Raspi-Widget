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
	Category parent;
	std::string ticker;
	std::companyName;
	std::string maretCap;
	std::string exchange;
	std::vector<DailyStock> days;
}

#endif