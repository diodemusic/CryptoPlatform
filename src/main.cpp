#include <iostream>
#include <string.h>

using namespace std;

bool optionIsValid(int userOption, int max)
{
    if (userOption < 1 or userOption > max)
    {
        return false;
    }
    return true;
}

void printOptions()
{
    int numMenuOptions = 7;
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
    int userOption;
    bool printAgain = true;

    while (printAgain)
    {
        for (string option : options)
        {
            cout << option << endl;
        }

        cout << "========== " << endl;
        cout << "Press 1-" << numMenuOptions << endl;

        cin >> userOption;

        if (!optionIsValid(userOption, numMenuOptions))
        {
            cout << "Invalid choice. Choose 1-" << numMenuOptions << endl;
            continue;
        }

        cout << results[userOption - 1] << endl;

        if (userOption == 7)
        {
            printAgain = false;
        }
    }
}

int main()
{
    printOptions();
    return 0;
}
