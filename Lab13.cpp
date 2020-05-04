//
//  Lab13.cpp
//  
//
//  Created by Bruce Gooch on 4/29/20.
//  Edited by Edward Cruz on 5/3/20.
//


#include "invalidDay.hpp"
#include "invalidMonth.hpp"
#include "invalidYear.hpp"

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

void splitANDtokenize(string &l, char r, vector<string> &t);
int getNumberOfDays(int month, int year);

int main() {
  string line;  
  // Get a Date from the User, such as 8-27-1980
  cout << "Enter a date (such as 8-27-1980) : ";

  // 1. Read an entire line as a string
  getline(cin, line);  
    
  // 2. Tokenize the string into three tokens
  vector <string> tok;
  splitANDtokenize(line, '-', tok);
    
  // 3. Convert the three string into three ints
  vector <int> _tokens;
  for (int i = 0; i < tok.size(); i++) {
    stringstream s(tok[i]);
    int t;
    s >> t;
    _tokens.push_back(t);
  }

  // 4. Test the three ints and throw exceptions
  //year
  bool leap = false;
  try {
    if (_tokens[2] < 0 || _tokens[2] > 2020) {
      throw(invalidYear().what());
    } 
    // Compute whether a year is a leap year
    if((_tokens[2]%400==0) || (_tokens[2]%4==0 && _tokens[2]%100!=0))
      leap = true;
    else
      leap = false;
    
  } catch (string e) {
    cout << "\n" << e << endl;
  }
  
  //month
  try {
    if (_tokens[0] < 1 || _tokens[0] > 12) {
      throw(invalidMonth().what());
    }
  } catch (string e) {
    cout << "\n" << e << endl;
  }
  
  //day
  try {
    
    int max;
    if (_tokens[0] == 2 && leap) {
      max = 29;
    } else {
      max = 28;
    }

    if (_tokens[0] == 1 || _tokens[0] == 3 || _tokens[0] == 5 || _tokens[0] == 7 
                || _tokens[0] == 8 || _tokens[0] == 10 || _tokens[0]==12) {
      max = 31;
    } else {
      max = 30;
    }

    if (_tokens[1] < 1 || _tokens[1] > max) {
      throw(invalidDay().what());
    }
    
  } catch (string e) {
    cout << "\n" << e << endl;
  }
  //TESTS CASES
  // 0-21-1955 -> Throw a Month Exception
  // Bruce-Gooch-1955 Throw a Month & Day Exception
  // 12-32-1955 Throw a Day Exception
  // 14-21-1955 Throw a Month Exception
  return 0;
}

// Original: Geeks-for-Geeks
// Link: https://www.geeksforgeeks.org/tokenizing-a-string-cpp/
// Date: 5/3/2020
// This snipet has been modified by Edward Cruz
void splitANDtokenize(string &l, char r, vector<string> &t)
{ 
  stringstream s(l);
  string sub;
  while(getline(s, sub, r)) {
    t.push_back(sub);
  }
} 