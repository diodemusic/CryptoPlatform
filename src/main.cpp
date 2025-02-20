#include <iostream>
#include <limits>
#include <string.h>

using namespace std;

const int numMenuOptions = 7;
bool printAgain = true;

bool inputIsValid(int userOption)
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

void printMenu()
{
    string options[numMenuOptions] = {
        "1: Print help",
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

    cout << "============" << endl;
    cout << "Press 1-" << numMenuOptions << endl;
}

int processUserOption()
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

    return 0;
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

void printResponse()
{
    int userOption = processUserOption();
    
    switch (userOption)
    {
    case 1:
        printHelp();
        break;
    case 2:
        printExchangeStats();
        break;
    case 3:
        makeOffer();
        break;
    case 4:
        placeBid();
        break;
    case 5:
        printWallet();
        break;
    case 6:
        goToNextTimeFrame();
        break;
    case 7:
        exitProgram();
    
    default:
        cout << "Invalid input. Please press 1-" << numMenuOptions << endl;
        break;
    }
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
