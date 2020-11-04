#ifndef STOCKRECORD_H
#define STOCKRECORD_H

class DailyStock{
private:
	float open;
	float low;
	float high;
	float close;
	float volume;
	float date;
public:
	float getOpen();
	float getClose();
	float getHigh();
	float getLow();
	long long int getVolume();
}

#endif