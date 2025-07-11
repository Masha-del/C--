#include "logic.h"
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;


void mixingArray(int arr[], int size) 
{
    srand(time(NULL));

    for (int i = size - 1; i > 0; i--) 
    {
        int j = rand() % (i + 1);

        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

    string generateNumber()
    {
    int digits[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    mixingArray(digits, 10);
    
    string secret;

    for (int i = 0; i < 4; ++i) 
    {
        secret += to_string(digits[i]);
    }
    
    return secret;
}


GuessResult check(const string& secret, const string& guess) 
{
    GuessResult result{0, 0};
    
    for (int i = 0; i < 4; ++i) 
    {
        if (secret[i] == guess[i]) 
        {
            result.bulls++;
        } 
        else
        {
            for (int j = 0; j < 4; ++j) 
            {
                if (i != j && secret[i] == guess[j]) 
                {
                    result.cows++;
                    break;
                }
            }
        }
    }
    
    return result;
}

bool isValid(const string& guess) 
{
    if (guess.length() != 4) 
    {
        return false;
    }
    
    bool used[10] = {false};

    for (int i = 0; i < 4; ++i) 
    {
        char c = guess[i];       

        if (!isdigit(c)) 
        {
            return false;
        }

        int digit = c - '0';

        if (used[digit]) 
        {
            return false;
        
        }
        used[digit] = true;
    }
    return true;
}