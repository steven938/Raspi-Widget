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
/*!
 * \brief The CategoryADT class describes a category of information. Abstract class
 *
 * Abstract class for a category, created to set virtual methods needed to be implemented in each category.
 * \author Dhyey Patel
 * \date 2020-11-04
 */
class CategoryADT {
	public:
    /*!
         * \brief search creates and returns a record based on a given search string
         * \return a Record based on the search string
         */
        virtual Record search(const std::string) = 0;
	private: 
        std::vector<Record> records; /*!< A vector to store the records for the given CategoryADT */
};
#endif 
