#include <iostream>
#include <limits>
#include <map>
#include <vector>

#include "MerkelMain.h"
#include "OrderBookEntry.h"

int main()
{
    MerkelMain app{};
    app.init();
    app.run();

    return 0;
}
