/*
Author: Adam Miller
Description: Code file that define an individual record of the news (one news story), with information about the story and a pointers to the parent category
Date: 2020-11-04
*/
#include "NewsRecord.h"
#include "Date.h"
using namespace std;
/*
I'm not going to fill this comment out, because i suspect that this will change - ADAM
Name: 
Description: 
Parameter Descriptions:
Return Description: 
*/
NewsRecord::NewsRecord(Date date, string author, string title, string description, string source, string url){
    this->date = date;
    this->author = author;
    this->title = title;
    this->description = description;
    this->source = source;
    this->url = url;
}
/* 
Name: Destructor
Description: Destroys the object
Parameter Descriptions: N/A
Return Description: N/A
*/
NewsRecord::~NewsRecord(){

}


string NewsRecord::getAuthor(){
    return this->author;
}


/*
Name: getDate 
Description: Returns the Date of the NewsRecord
Parameter Descriptions: N/A
Return Description: The Date of the NewsRecord
*/
Date NewsRecord::getDate(){
    return date;
}
/*
Name: getTitle 
Description: getter for Title
Parameter Descriptions: N/A
Return Description: the title of the NewsRecord
*/
string NewsRecord::getTitle(){
    return title;
}
/*

*/
string NewsRecord::getDescription(){
    return description;
}
/*
Name: getSource 
Description: getter for Source
Parameter Descriptions: N/A
Return Description: the source of the NewsRecord
*/
string NewsRecord::getSource(){
    return source;
}
/*
Name: getURL 
Description: getter for URL
Parameter Descriptions: N/A
Return Description: the URL of the NewsRecord
*/
string NewsRecord::getURL(){
    return url;
}
