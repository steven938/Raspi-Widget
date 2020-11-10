/*
Author: Dhyey Patel
Description: Code file that define NewsCategory.h
Date: 2020-11-04
*/
#include "NewsCategory.h"
using namespace std;
/*
Name: NewsCategory
Description: It will do nothing but create an instance of that class
Parameter Descriptions: N/A
Return Description: N/A
*/
NewsCategory::NewsCategory(){
    
}
/*
Name: Destructor
Description: Destroys the object
Parameter Descriptions: N/A
Return Description: N/A
*/
NewsCategory::~NewsCategory(){

}
/*
Name: getRecords
Description: Getter for collection of NewsRecords
Parameter Descriptions: N/A
Return Description: Returns the vector of NewsRecords
*/
vector<Record> NewsCategory::getRecords(){
    return records;
}

/*
Name: search
Description: Searches articles related to the requested search
Parameter Descriptions: Topic to search 
Return Description: NewsRecords related to the search
*/
Record NewsCategory::search(string searchString){

}

/*
Name: sort
Description: sort the NewsRecords in the requested order
Parameter Descriptions: type is what to sort by, and asend is if we should sort in ascending order
Return Description: N/A
*/
void NewsCategory::sort(int type, bool asend){


}


/*
Name: changeTime
Description: Change the time period for NewsRecords in the vector, do another search if necessary
Parameter Descriptions: The timeframe you would like to change it to, prelist of timeframes represented by ints (1 = last week)
Return Description: the vector with the NewsRecords that follow the time period
*/
vector<Record> NewsCategory::changeTime(int time){
    return records;
}

/*
Name: changeTopic
Description: Change the topic for NewsRecords in the vector, do another search if necessary
Parameter Descriptions: The topic you would like to change it to, prelist of topics represented by ints (1 = sports)
Return Description: the vector with the NewsRecords that follow the topic
*/
vector<Record> NewsCategory::changeTopic(int time){
    return records;
}

/*
Name: changeNewsSource
Description: Change the news source for NewsRecords in the vector, do another search if necessary
Parameter Descriptions: The topic you would like to change it to, prelist of news sources represented by ints (1 = CNN)
Return Description: the vector with the NewsRecords that are from the given news source
*/
vector<Record> NewsCategory::changeNewsSource(int source){
    return records;
}

/*
Name: displayRecords
Description: Helper function that will display the NewsRecords on the screen (called inside every function)
Parameter Descriptions: A vector with the NewsRecords to be displayed
Return Description: N/A
*/
void NewsCategory::displayRecords(vector<Record> toDisplay){

}
