/*
Author: Adam Miller
Description: Header file that define an individual record of the news (one news story), with information about the story and a pointers to the parent category
Date: 2020-11-04
*/
#ifndef NEWS_RECORD_H
#define NEWS_RECORD_H
#include <string>
#include "Date.h"
#include "Record.h"
#include "CategoryADT.h"
class NewsRecord: public Record{
    private:
        Date date;  //the date of the news story
        std::string subject;    //the subject of the news story
        std::string title;      //the title of the news story
        std::string sector;     //the sector (i.e. tech, finance) of the news story
        std::string location;   //the location that the news is from (i.e. a city)
        std::string source;     //the source (i.e. CNN) of the news story
        std::string url;        //the URL to locate the news story online.
    public:
        NewsRecord(CategoryADT* parent);
        ~NewsRecord(); //example comment
        std::string getSubject();
        Date getDate();
        std::string getTitle();
        std::string getSector();
        std::string getLocation();
        std::string getSource();
        std::string getURL();

};
#endif