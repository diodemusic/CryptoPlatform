#include <iostream>
#include <string.h>

using namespace std;

const int numMenuOptions = 7;
bool printAgain = true;
string options[numMenuOptions] = {
    "1: Print help",
    "2: Print exchange stats",
    "3: Make an offer",
    "4: Make a bid",
    "5: Print wallet",
    "6: Continue",
    "7: Exit"
};
string results[numMenuOptions] = {
    "Help - your aim is to make money. Analyze the market and make binds and offers.",
    "Market looks good.",
    "Make an offer - enter the amount.",
    "Make a bid - enter the amount.",
    "Your wallet is empty.",
    "Going to next time frame.",
    "Exiting...",
};

bool inputIsValid(int userOption)
{
    if (userOption < 1 or userOption > numMenuOptions)
    {
        return false;
    }
    return true;
}

void printMenu()
{
    for (string option : options)
    {
        cout << option << endl;
    }

    cout << "============" << endl;
    cout << "Press 1-" << numMenuOptions << endl;
}

int processInput()
{
    int userOption;
    cin >> userOption;

    if (userOption == 7)
    {
        printAgain = false;
        return userOption;
    }

    if (inputIsValid(userOption))
    {
        return userOption;
    }

    cout << "Invalid input. Please press 1-" << numMenuOptions << endl;

    return 0;
}

void printResponse()
{
    int userOption = processInput();
    cout << results[userOption - 1] << endl;
}

int main()
{
    while (printAgain)
    {
        printMenu();
        printResponse();
    }
    return 0;
}
