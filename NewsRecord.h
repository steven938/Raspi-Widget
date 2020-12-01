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
/*!
 * \brief The NewsRecord class represents one news story
 *
 * Represnts one news story, given an author, title, description, source and url.
 *
 * @author Adam Miller
 * @date 2020-11-04
 *
 */
class NewsRecord: public Record{
    private: /*!< a qt-created pointer that represents the window itself*/
        Date date;                  /*!< the date of the news story */
        std::string author;         /*!< author of story */
        std::string title;          /*!< the title of the news story */
        std::string description;    /*!< description of news article */
        std::string source;         /*!< the source (i.e. CNN) of the news story */
        std::string url;            /*!< the URL to locate the news story online. */
    public:
        NewsRecord(Date date, std::string author, std::string title, std::string description, std::string source, std::string url);
        ~NewsRecord();
        std::string getAuthor();
        std::string getSubject();
        Date getDate();
        std::string getTitle();
        std::string getDescription();
        std::string getSource();
        std::string getURL();

};
#endif
