/*
Author: Adam Miller
Description: Header file that define an individual record of the news (one news story), with information about the story and a pointers to the parent category
Date: 2020-11-04
*/
#ifndef NEWS_RECORD_H
#define NEWS_RECORD_H
#include <string>
#include "Date.h"
class NewsRecord:: public Record{
    private:
        Date date;
        std::string subject;
        std::string title;
        std::string sector;     
        std::string location;   //the location that the news is from (i.e. a city)
        std::string source;
        std::string url;
    public:
        NewsRecord();
        ~NewsRecord();
        std::string getSubject();
        Date getDate();
        std::string getTitle();
        std::string getSector();
        std::string getLocation();
        std::string getSource();

};
#endif