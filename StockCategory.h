/*
Author: Leland Conn
Description: Header file that defines a stock category, which holds stock records for each company and can act on that set of data
Date: 2020-11-04
*/
#ifndef STOCK_CATEGORY_H
#define STOCK_CATEGORY_H
#include <string>
#include <vector>
#include "StockRecord.h"
#include "CategoryADT.h"
class StockCategory: public CategoryADT{
    private:
        vector<StockRecord> records; // A vector to store all the weather records

        // Print the specified records to the screen
        void displayRecords(vector<StockRecord> toDisplay);
        
    public:
    
        // Constructor to make instances of StockCategory class
        StockCategory();

        // Destructor
        ~StockCategory();

        // Function to get the records of the class 
        vector<StockRecord> getRecords();

        // Function to find a record of a specific company (specified by searchString)
        StockRecord search(std::string searchString);

        // Sort the weather records currently stored in the private vector
        void sort(int type, bool ascend);
};
#endif