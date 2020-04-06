#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "helperFunctions.h"

using namespace std;

//clears the terminal
void clearConsole()
{
  cout << "\033[2J\033[1;1H";;
}

//converts each letter of the string to uppercase
void toUpperCase(string &mystring)
{
  transform(mystring.begin(), mystring.end(), mystring.begin(), ::toupper);
}
