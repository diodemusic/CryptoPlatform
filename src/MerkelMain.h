#pragma once

#include <map>
#include <vector>

#include "OrderBookEntry.h"

extern int NUMMENUOPTIONS;

class MerkelMain
{
public:
    MerkelMain() = default;
    void init();
    void run();

private:
    void exitProgram();
    int getUserOption();
    void goToNextTimeFrame();
    void makeOffer();
    void placeBid();
    void printExchangeStats();
    void printHelp();
    void printWallet();
    bool optionIsValid(int userOption);
    void processUserOption(int userOption, std::map<int, void (MerkelMain::*)()> menu);
    void printMenu();
    std::map<int, void (MerkelMain::*)()> getMenu();
    double computeAveragePrice(const std::vector<OrderBookEntry> &entries);
    double computeLowPrice(const std::vector<OrderBookEntry> &entries);
    double computeHighPrice(const std::vector<OrderBookEntry> &entries);
    double computePriceSpread(const std::vector<OrderBookEntry> &entries);
    void loadOrderBook();
    std::vector<OrderBookEntry> orders;
};
