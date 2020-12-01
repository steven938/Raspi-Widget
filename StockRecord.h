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
/*!
 * \brief The StockRecord class describes an individual stock
 *
 * Describes an individual stock, including stock information over time (each day is stored as a DailyStock), as well as financial information for the company
 *@author Steven Chen
 * @Date 2020-11-04
 *
 */
class StockRecord: public Record{
public:
    StockRecord(const std::string TICKER);
    std::string getTicker() const;
    std::string getCompanyName() const;
    std::string getExchange() const;
    double getMarketCap() const;
    float getOpen(const int DAYS_AGO) const;
    float getLow(const int DAYS_AGO) const;
    float getHigh(const int DAYS_AGO) const;
    float getClose(const int DAYS_AGO) const;
    float getEBITShare() const;
    float getPayoutRatio() const;
    float getCurrentRatio() const;
    float getGrossMargin() const;
    long long int getVolume(const int DAYS_AGO) const;
    std::string getDate(const int DAYS_AGO) const;
	~StockRecord();
private:
    void requestStockPrices();
    void requestCompanyInfo();
    void requestFinancials();

    //private members
    std::string ticker;         /*!< up to 4 letter ticker */
    std::string companyName;    /*!< name of company e.g. "Ford Motor Co."*/
    double marketCap;           /*!< market capitalization of the company, equal to number of shares * stock pice */
    std::string exchange;       /*!< the exchange that the stock is traded on */
    float ebitShare;            /*!< Earnings Before Interest and Tax (EBIT) divided by number of shares */
    float payoutRatio;          /*!< Payout ratio = dividend/share divided by earnings/share*/
    float currentRatio;         /*!< Current ratio = current assets/current liabilities*/
    float grossMargin;          /*!< Gross margin = gross profit divided by revenue*/
    std::vector<DailyStock> days; /*!< vector of information on stock price on several dates*/
};

#endif
