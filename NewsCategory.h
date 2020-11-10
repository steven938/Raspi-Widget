/*
Author: Dhyey Patel
Description: Header file that will store the collection of NewsRecords and will change the Records in the collection based on the requests
Date: 2020-11-04
*/
#ifndef NEWS_CATEGORY_H
#define NEWS_CATEGORY_H
#include <string>
#include "Date.h"
#include "Record.h"
#include "NewsRecord.h"
#include "CategoryADT.h"


class NewsCategory: public CategoryADT{
    private:
        std::vector<Record> records;                    //Store the records
        void displayRecords(std::vector<Record>);
    public:
        NewsCategory();
        ~NewsCategory(); 
        //It is only letting me set the vector to Record and not NewsRecord because of the ADT
        std::vector<Record> getRecords();
        Record search(std::string);
        void sort(int, bool);
        // I can change the vector type to NewsRecord here, but it makes sense to leave it as a Record now
        std::vector<Record> changeTime(int);
        std::vector<Record> changeTopic(int);
        std::vector<Record> changeNewsSource(int);
         
        
};
#endif
