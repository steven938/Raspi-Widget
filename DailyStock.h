#ifndef DAILYSTOCK_H
#define DAILYSTOCK_H
#include "Date.h"
/*!
 * \brief The DailyStock class describes the stock price and volume of a given stock on a given day
 *
 *describes one day of stock price (high low open and close) for a given stock
 *
 */
class DailyStock {
private:
    float open; /*!< open price on that date */
    float low; /*!< low price on that date */
    float high; /*!< high price on that date*/
    float close; /*!< closing price on that date*/
    long long int volume; /*!< volume of trades on that date*/
    Date date; /*!< the Date */
public:
    DailyStock(const float OPEN, const float CLOSE, const float HIGH,const float LOW, const long long int VOLUME,const Date DATE);
    float getOpen() const;
    float getClose() const;
    float getHigh() const;
    float getLow() const;
    std::string getDate() const;
    long long int getVolume() const;
    ~DailyStock();
};

#endif
