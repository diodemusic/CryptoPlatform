#include <iostream>
#include <limits>

#include "MerkelMain.h"

int NUMMENUOPTIONS = 7;

void MerkelMain::exitProgram()
{
    std::cout << "Exiting..." << std::endl;
    std::exit(0);
}

int MerkelMain::getUserOption()
{
    int userOption;
    std::cin >> userOption;
    std::cout << "You chose " << userOption << std::endl;
    return userOption;
}

void MerkelMain::goToNextTimeFrame()
{
    std::cout << "Going to next time frame." << std::endl;
}

void MerkelMain::makeOffer()
{
    std::cout << "Make an offer - enter the amount." << std::endl;
}

void MerkelMain::placeBid()
{
    std::cout << "Make a bid - enter the amount." << std::endl;
}

void MerkelMain::printExchangeStats()
{
    unsigned int i = 1;

    std::cout << "EXCHANGE STATS:" << std::endl;
    std::cout << "==========" << std::endl;

    for (const OrderBookEntry &order : this->orders)
    {
        std::cout << "Order " << i << "." << std::endl;
        std::cout << "Timestamp: " << order.getTimestamp() << std::endl;
        std::cout << "Products: " << order.getProducts() << std::endl;
        // ! FIX std::cout << "Order Type: " << order.getOrderType() << std::endl;
        std::cout << "Price: " << order.getPrice() << std::endl;
        std::cout << "Amount: " << order.getAmount() << std::endl;
        std::cout << "==========" << std::endl;
        i++;
    }

    std::cout << "High: " << this->computeHighPrice(orders) << std::endl;
    std::cout << "Low: " << this->computeLowPrice(orders) << std::endl;
    std::cout << "Avg: " << this->computeAveragePrice(orders) << std::endl;
    std::cout << "Spread: " << this->computePriceSpread(orders) << std::endl;
}

void MerkelMain::printHelp()
{
    std::cout << "Help - your aim is to make money. Analyze the market and make binds and offers." << std::endl;
}

void MerkelMain::printWallet()
{
    std::cout << "Your wallet is empty." << std::endl;
}

bool MerkelMain::optionIsValid(int userOption)
{
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }

    if (userOption < 1 or userOption > NUMMENUOPTIONS)
    {
        return false;
    }

    return true;
}

void MerkelMain::processUserOption(int userOption, std::map<int, void (MerkelMain::*)()> menu)
{
    if (!optionIsValid(userOption))
    {
        std::cout << "Invalid input. Please enter a number from 1-" << NUMMENUOPTIONS << std::endl;
        return;
    }

    (this->*menu[userOption])();
}

void MerkelMain::printMenu()
{
    std::string options[NUMMENUOPTIONS] = {
        "\n1: Print help",
        "2: Print exchange stats",
        "3: Make an offer",
        "4: Make a bid",
        "5: Print wallet",
        "6: Continue",
        "7: Exit"};

    for (const std::string &option : options)
    {
        std::cout << option << std::endl;
    }

    std::cout << "====================" << std::endl;
    std::cout << "Press 1-" << NUMMENUOPTIONS << std::endl;
}

std::map<int, void (MerkelMain::*)()> MerkelMain::getMenu()
{
    std::map<int, void (MerkelMain::*)()> menu;

    menu[1] = &MerkelMain::printHelp;
    menu[2] = &MerkelMain::printExchangeStats;
    menu[3] = &MerkelMain::makeOffer;
    menu[4] = &MerkelMain::placeBid;
    menu[5] = &MerkelMain::printWallet;
    menu[6] = &MerkelMain::goToNextTimeFrame;
    menu[7] = &MerkelMain::exitProgram;

    return menu;
}

double MerkelMain::computeAveragePrice(const std::vector<OrderBookEntry> &entries)
{
    double sum;

    for (const OrderBookEntry &entry : entries)
    {
        sum += entry.getPrice();
    }

    return sum / entries.size();
}

double MerkelMain::computeLowPrice(const std::vector<OrderBookEntry> &entries)
{
    double lowPrice = entries[0].getPrice();

    for (unsigned int i = 1; i < entries.size(); ++i)
    {
        double currentPrice = entries[i].getPrice();

        if (currentPrice < lowPrice)
        {
            lowPrice = currentPrice;
        }
    }

    return lowPrice;
}

double MerkelMain::computeHighPrice(const std::vector<OrderBookEntry> &entries)
{
    double highPrice = 0;

    for (const OrderBookEntry &entry : entries)
    {
        double currentPrice = entry.getPrice();

        if (currentPrice > highPrice)
        {
            highPrice = currentPrice;
        }
    }

    return highPrice;
}

double MerkelMain::computePriceSpread(const std::vector<OrderBookEntry> &entries)
{
    double buyerHighPrice = 0;
    double sellerLowPrice = entries[0].getPrice();

    for (const OrderBookEntry &entry : entries)
    {
        if (entry.getOrderType() == orderBookType::ask)
        {
            double currentPrice = entry.getPrice();

            if (currentPrice > buyerHighPrice)
            {
                buyerHighPrice = currentPrice;
            }
        }
        else
        {
            double currentPrice = entry.getPrice();

            if (currentPrice < sellerLowPrice)
            {
                sellerLowPrice = currentPrice;
            }
        }
    }

    return sellerLowPrice - buyerHighPrice;
}

void MerkelMain::loadOrderBook()
{
    std::vector<OrderBookEntry> orders;

    orders.push_back(OrderBookEntry{
        "2020/03/17 17:01:24.884492",
        "ETH/BTC",
        orderBookType::bid,
        1000,
        9.14455526});

    orders.push_back(OrderBookEntry{
        "2020/03/17 17:01:24.884492",
        "ETH/BTC",
        orderBookType::bid,
        2000,
        9.14455526});

    orders.push_back(OrderBookEntry{
        "2020/03/17 17:01:24.884492",
        "BTC/USDT",
        orderBookType::ask,
        300,
        300.5});

    this->orders = orders;
}

void MerkelMain::init()
{
    this->loadOrderBook();
}

void MerkelMain::run()
{
    while (true)
    {
        this->printMenu();
        int userOption = this->getUserOption();
        std::map<int, void (MerkelMain::*)()> menu = this->getMenu();
        this->processUserOption(userOption, menu);
    }
}
