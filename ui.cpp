#include "ui.h"
#include <iostream>
using namespace std;

void printWelcome() 
{
    cout << "====Быки и Коровы===" << endl;
    cout << "Цель игры: Угадать 4-значное число" << endl;
    cout << "Количество 🐂 - цифры расположены на своих местах" << endl;
    cout << "Количество 🐄 - в числе есть такие цифры, но не на своих местах" << endl;
}

void printResult(int bulls, int cows)
{
    cout << "Быки: " << bulls << ", Коровы: " << cows << endl;
}

void printWin(const string& secret, int attempts) 
{
    cout << "Вы угадали число " << secret << endl << " за " << attempts << " попыток";
}

void printInvalid() 
{
    cout << "Введите 4 разные цифры" << endl;
}