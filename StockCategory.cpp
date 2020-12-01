/*
Author: Dhyey Patel
Description: Code file that define an individual stock category
Date: 2020-11-04
*/

#include <iostream>
#include "StockCategory.h"
#include <vector>

using namespace std;


/*!
 * \brief StockCategory::StockCategory constructor
 *
 * Doesn't do anything in particular, as there is nothing to initialize
 *
 */
StockCategory::StockCategory(){
    
    
}
/*!
 * \brief StockCategory::~StockCategory destructor
 *
 * Doesn't do anything in particular, as there is no dynamic memory
 */
StockCategory::~StockCategory(){

}

/*!
 * \brief StockCategory::getRecords getter for the vector of records
 * \return records, the vector of StockRecord s
 */
vector<StockRecord> StockCategory::getRecords(){
   return this->records;
}



/*!
 * \brief StockCategory::search creates and returns a StockRecord given a search string
 *
 *Given a search string (the ticker of the stock), creates a StockRecord, pushes it to records, and returns it.
 *
 * \param SEARCH_STRING the ticker for the stock to be searched
 * \return the StockRecord for the company with ticker SEARCH_STRING
 */
Record StockCategory::search(const string SEARCH_STRING){
    StockRecord r(SEARCH_STRING);
    records.push_back(r);
    return r;
}
