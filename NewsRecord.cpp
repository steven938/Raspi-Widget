/*
Author: Adam Miller
Description: Code file that define an individual record of the news (one news story), with information about the story and a pointers to the parent category
Date: 2020-11-04
*/
#include "NewsRecord.h"
using namespace std;
/*
I'm not going to fill this comment out, because i suspect that this will change - ADAM
Name: 
Description: 
Parameter Descriptions:
Return Description: 
*/
NewsRecord::NewsRecord(CategoryADT* parent){
    date = Date(1,2,3);
    
}
/*
Name: Destructor
Description: Destroys the object
Parameter Descriptions: N/A
Return Description: N/A
*/
NewsRecord::~NewsRecord(){

}
/*
Name: getSubject 
Description: Getter for subject
Parameter Descriptions: N/A
Return Description: subject, the subject of the NewsRecord 
*/
string NewsRecord::getSubject(){
    return subject;
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
Name: getSector 
Description: getter for sector
Parameter Descriptions: N/A
Return Description: the sector of the NewsRecord
*/
string NewsRecord::getSector(){
    return sector;
}
/*
Name: getLocation 
Description: getter for Location
Parameter Descriptions: N/A
Return Description: the location of the NewsRecord
*/
string NewsRecord::getLocation(){
    return location;
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
