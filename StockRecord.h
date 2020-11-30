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
#include "Record.h"

class StockRecord: public Record{
public:
	StockRecord(std::string ticker);
	std::string getTicker();
	std::string getCompanyName();
	std::string getExchange();
    double getMarketCap();
	float getOpen(int daysAgo);
	float getLow(int daysAgo);
	float getHigh(int daysAgo);
	float getClose(int daysAgo);
    float getEBITShare();
    float getPayoutRatio();
    float getCurrentRatio();
    float getGrossMargin();
	long long int getVolume(int daysAgo);
    std::string getDate(int daysAgo);
	~StockRecord();
private:
    void requestStockPrices();
    void requestCompanyInfo();
    void requestFinancials();
	std::string ticker; // 4 letter ticker
	std::string companyName; // company name
    double marketCap;
	std::string exchange;
    float ebitShare;
    float payoutRatio;
    float currentRatio;
    float grossMargin;
	std::vector<DailyStock> days; // vector of information on stock price on several dates
};

#endif
