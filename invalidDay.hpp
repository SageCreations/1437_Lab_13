//
//  invalidDay.h
//  
//
//  Created by Bruce Gooch on 4/29/20.
//  Edited by Edward Cruz on 5/3/20.
//

#ifndef INVALIDDAY_HPP
#define INVALIDDAY_HPP

#include <string>
     
using namespace std;
 
class invalidDay
{
public:
    invalidDay()
    {
        message = "Day out of Range!"; //Depends on the Month
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
