/*
Author: Leland Conn
Description: Header file that will store the collection of NewsRecords and will change the Records in the collection based on the requests
Date: 2020-11-04
*/
#ifndef NEWS_CATEGORY_H
#define NEWS_CATEGORY_H
#include "string.h"
#include "Date.h"
#include "Record.h"
#include "NewsRecord.h"
#include "CategoryADT.h"
#include "QJsonObject"

/*!
 * \brief The NewsCategory class holds news records for each query.
 *
 * The NewsCategory class is a singleton that holds news records for each query
 *
 * @author Leland Conn
*/
class NewsCategory: public CategoryADT{
    private:
        std::vector<NewsRecord> records; /*!< A vector to store all the news records*/
        void parseArticles(QJsonArray&, int numArticles);

    public:
        NewsCategory();
        ~NewsCategory(); 
        //It is only letting me set the vector to Record and not NewsRecord because of the ADT
        std::vector<NewsRecord> getRecords();
        Record search(std::string);

        void requestArticlesBySector(std::string sector);
        void requestArticles(std::string searchString);
};
#endif
