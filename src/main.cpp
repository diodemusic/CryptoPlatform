#include <iostream>
#include <limits>
#include <string.h>
#include <map>

using namespace std;

int numMenuOptions = 7;
bool printAgain = true;

void printMenu()
{
    string options[numMenuOptions] = {
        "\n1: Print help",
        "2: Print exchange stats",
        "3: Make an offer",
        "4: Make a bid",
        "5: Print wallet",
        "6: Continue",
        "7: Exit"
    };

    for (string option : options)
    {
        cout << option << endl;
    }

    cout << "====================" << endl;
    cout << "Press 1-" << numMenuOptions << endl;
}

int getUserOption()
{
    int userOption;
    cin >> userOption;
    cout << "You chose " << userOption << endl;
    return userOption;
}

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

void printHelp()
{
    cout << "Help - your aim is to make money. Analyze the market and make binds and offers." << endl;
}

void printExchangeStats()
{
    cout << "Market looks good." << endl;
}

void makeOffer()
{
    cout << "Make an offer - enter the amount." << endl;
}

void placeBid()
{
    cout << "Make a bid - enter the amount." << endl;
}

void printWallet()
{
    cout << "Your wallet is empty." << endl;
}

void goToNextTimeFrame()
{
    cout << "Going to next time frame." << endl;
}

void exitProgram()
{
    cout << "Exiting..." << endl;
    exit(0);
}

map<int, void(*)()> getMenu()
{
    map<int, void(*)()> menu;

    menu[1] = printHelp;
    menu[2] = printExchangeStats;
    menu[3] = makeOffer;
    menu[4] = placeBid;
    menu[5] = printWallet;
    menu[6] = goToNextTimeFrame;
    menu[7] = exitProgram;

    return menu;
}

void processUserOption(int userOption, map<int, void(*)()> menu)
{
    if (!optionIsValid(userOption))
    {
        cout << "Invalid input. Please enter a number from 1-6" << endl;
        return;
    }

    menu[userOption]();
}

int main()
{
    while (printAgain)
    {
        printMenu();
        int userOption = getUserOption();
        map<int, void(*)()> menu = getMenu();
        processUserOption(userOption, menu);
    }

    return 0;
}
