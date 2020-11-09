#ifndef DAILYSTOCK_H
#define DAILYSTOCK_H
#include "Date.h"

class DailyStock {
private:
	float open; // open price on that date
	float low; // low price on that date
	float high; // high price on that date
	float close; // closing price on that date
	long long int volume; // volume of tradeson that date
	Date date; // the date
public:
	DailyStock(float open, float close, float high, float low, long long int volume, std::string date);
	float getOpen();
	float getClose();
	float getHigh();
	float getLow();
	long long int getVolume();
	~DailyStock();
};

#endif