#ifndef LOGIC_H
#define LOGIC_H

#include <string>
using namespace std;

struct GuessResult 
{
    int bulls;
    int cows;
};

string generateNumber();
GuessResult check(const string& secret, const string& guess);
bool isValid(const string& guess);

#endif