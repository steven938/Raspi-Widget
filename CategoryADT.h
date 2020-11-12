/*
Author: Dhyey Patel
Description: Abstract class for a category, created to set virtual methods needed to be implemented in each category.
Date: 2020-11-04
*/
#ifndef CATEGORY_ADT_H
#define CATEGORY_ADT_H
#include <vector>
#include <string>
#include "Record.h"

class Record;
class CategoryADT {
	public:
        virtual Record search(std::string) = 0; // Function to find a record
        virtual void sort(int type, bool ascend) = 0;  // Function to store the stored records
	private: 
        std::vector<Record> records; // A vector to store all the records
};
#endif 
