//
//  invalidDay.h
//  
//
//  Created by Bruce Gooch on 4/29/20.
//

#ifndef invalidDay_h
#define invalidDay_h

#include <string>
     
using namespace std;
 
class invalidDay
{
public:
    invalidDay()
    {
        message = "Date out of Range!"; //Depends on the Month
    }
     
    invalidDay(string str)
    {
        message = str;
    }

    string what()
    {
        return message;
    }

private:
    string message;
};







#endif /* invalidDay_h */
