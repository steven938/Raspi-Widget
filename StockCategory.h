/*
Author: Dhyey Patel
Description: Header file that defines a stock category, which holds stock records for each company and can act on that set of data
Date: 2020-11-04
*/
#ifndef STOCK_CATEGORY_H
#define STOCK_CATEGORY_H
#include <string>
#include <vector>
#include "StockRecord.h"
#include "CategoryADT.h"
/*!
 * \brief The StockCategory class is a singleton that creates and accesses records
 *
 * A class with ways to access and create StockRecords
 *
 * @author Dhyey Patel
 * @date 2020-11-04
 *
 */
class StockCategory: public CategoryADT{
    private:
        std::vector<StockRecord> records; /*!< A vector to store all the stock records*/
        // Print the specified records to the screen
        void displayRecords(std::vector<StockRecord> toDisplay);
        
    public:
    
        // Constructor to make instances of StockCategory class
        StockCategory();

        // Destructor
        ~StockCategory();

        // Function to get the records of the class 
        std::vector<StockRecord> getRecords();

        // Function to find a record of a specific company (specified by searchString)
        Record search(std::string searchString);


};
#endif
