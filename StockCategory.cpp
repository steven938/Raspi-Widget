/*
Author: Leland Conn
Description: Code file that define an individual stock category
Date: 2020-11-04
*/
#include "StockCategory.h"
using namespace std;
/*
Name: StockCategory
Description: This is a constructor to create an instance of the StockCategory class
Parameter Descriptions: TBD
Return Description: N/A
*/
StockCategory::StockCategory(){
    
    
}
/*
Name: Destructor
Description: Destroys the object
Parameter Descriptions: N/A
Return Description: N/A
*/
StockCategory::~StockCategory(){

}
/*
Name: getRecords 
Description: Getter for the vector of records
Parameter Descriptions: N/A
Return Description: records, the vector holding stock records
*/
vector<StockRecord> StockCategory::getRecords(){
    return records;
}
/*
Name: search 
Description: Returns a desired stock record
Parameter Descriptions: N/A
Return Description: A StockRecord object or 0 if not found
*/
StockRecord StockCategory::search(string searchString){
    // code to find and return the desired record
}
/*
Name: sort 
Description: sort the stock records stored in vector records
Parameter Descriptions: integer type to identify the basis of the sort and boolean of ascending to know the order
Return Description: N/A
*/
void StockCategory::sort(int type, bool ascending){
    // code to sort the records
}
/*
Name: displayRecords 
Description: display the the records on the screen
Parameter Descriptions: N/A
Return Description: N/A
*/
void StockCategory::displayRecords(){
    // code to display records on screen
}