#ifndef UI_H
#define UI_H

#include <string>
using namespace std;

void printWelcome();
void printResult(int bulls, int cows);
void printWin(const string& secret, int attempts);
void printInvalid();

#endif