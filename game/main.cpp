#include "logic.h"
#include "ui.h"
#include <iostream>
#include <string>
using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");
    
    printWelcome(); 

    string secret = generateNumber();
    int attempts = 0;
    bool guesse = false;
    
    while (!guesse) 
    {
        cout << "Введите число: ";
        string guess;
        cin >> guess; 
        
        if (!isValid(guess)) 
        {
            printInvalid();
            continue;
        }
        
        attempts++;

        GuessResult result = check(secret, guess);
        printResult(result.bulls, result.cows);
        
        if (result.bulls == 4) 
        { 
            guesse = true;
            printWin(secret, attempts);
        }
    }
    return 0;
}