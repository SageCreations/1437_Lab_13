//
//  created by Edward Cruz on 5/3/20.
//

#ifndef INVALIDYEAR_HPP
#define INVALIDYEAR_HPP

#include <string>
     
using namespace std;
 
class invalidYear
{
public:
    invalidYear()
    {
        message = "year out of AC history"; //Depends on the Month
    }
     
    invalidYear(string str)
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







#endif