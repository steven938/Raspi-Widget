/*
Author: Adam Miller
Description: Code file that define an individual record of the news (one news story), with information about the story and a pointers to the parent category
Date: 2020-11-04
*/
#include "NewsRecord.h"
#include "Date.h"
using namespace std;

/*!
 * \brief NewsRecord::NewsRecord constructor creates a NewsRecord object.
 *
 * This is a constructor to create an instance of the NewsRecord class.
 * \param date a Date object representing the date the article was posted.
 * \param author a string representing the name of the author that wrote the article.
 * \param title a string representing the title of the article.
 * \param description a string representing a brief description of the article.
 * \param source a string representing the publishing source of the article.
 * \param url a string representing a url to open the article in a web browser.
 */
NewsRecord::NewsRecord(Date date, string author, string title, string description, string source, string url){
    this->date = date;
    this->author = author;
    this->title = title;
    this->description = description;
    this->source = source;
    this->url = url;
}

/*!
 * \brief NewsRecord::~NewsRecord destructor destroys a NewsRecord object.
 *
 * Since NewsRecord has no dynamically allocated memory, this does not do anything. Included for completeness.
 */
NewsRecord::~NewsRecord(){

}

/*!
 * \brief NewsRecord::getAuthor getter for the author of the article.
*
* returns the author's name who wrote the article.
 * \return author a string of the author's name.
 */
string NewsRecord::getAuthor(){
    return this->author;
}

/*!
 * \brief NewsRecord::getDate returns the Date of the NewsRecord.
 *
 *  return the date the news record was published.
 * \return date a Date object representing the date the article was published.
 */
Date NewsRecord::getDate(){
    return date;
}

/*!
 * \brief NewsRecord::getTitle getter for the title.
 *
 * returns the title of the article.
 * \return title a string representing the title of the NewsRecord.
 */
string NewsRecord::getTitle(){
    return title;
}

/*!
 * \brief NewsRecord::getDescription getter for the description.
 *
 * returns the description of the article.
 * \return description a string representing the description of the NewsRecord.
 */
string NewsRecord::getDescription(){
    return description;
}

/*!
 * \brief NewsRecord::getSource getter for the source.
 *
 * returns the the publishing company/entity of the article.
 * \return source a string representing the source of the NewsRecord.
 */
string NewsRecord::getSource(){
    return source;
}

/*!
 * \brief NewsRecord::getURL getter for the article's url.
 *
 * returns the the url to view the article in a web browser.
 * \return url a string representing the url of the NewsRecord.
 */
string NewsRecord::getURL(){
    return url;
}
