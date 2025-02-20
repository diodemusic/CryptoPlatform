#include <iostream>
#include <map>
#include <string.h>

#include "global.h"

using namespace std;

void printHelp();
void printExchangeStats();
void makeOffer();
void placeBid();
void printWallet();
void goToNextTimeFrame();
void exitProgram();

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
