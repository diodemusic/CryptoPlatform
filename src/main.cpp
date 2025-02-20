#include <iostream>
#include <limits>
#include <map>

#include "global.h"

using namespace std;

void printMenu();
int getUserOption();
map<int, void(*)()> getMenu();
void processUserOption(int userOption, map<int, void(*)()> menu);

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
