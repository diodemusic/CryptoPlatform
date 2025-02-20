#include <iostream>
#include <limits>
#include <map>

#include "global.h"

using namespace std;

bool optionIsValid(int userOption)
{
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }

    if (userOption < 1 or userOption > numMenuOptions)
    {
        return false;
    }

    return true;
}

void processUserOption(int userOption, map<int, void(*)()> menu)
{
    if (!optionIsValid(userOption))
    {
        cout << "Invalid input. Please enter a number from 1-" << numMenuOptions << endl;
        return;
    }

    menu[userOption]();
}
