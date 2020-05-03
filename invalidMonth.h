//
//  invalidMonth.h
//  
//
//  Created by Bruce Gooch on 4/29/20.
//

#ifndef invalidMonth_h
#define invalidMonth_h

#include <string>
     
using namespace std;
 
class invalidMonth
{
public:
    invalidMonth()
    {
        message = "Month out of Range 1-12!";
    }
     
    invalidMonth(string str)
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

#endif /* invalidMonth_h */
