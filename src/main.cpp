#include <iostream>
#include <limits>
#include <map>
#include <vector>

int numMenuOptions = 7;
bool printAgain = true;

void exitProgram()
{
    std::cout << "Exiting..." << std::endl;
    std::exit(0);
}

int getUserOption()
{
    int userOption;
    std::cin >> userOption;
    std::cout << "You chose " << userOption << std::endl;
    return userOption;
}

void goToNextTimeFrame()
{
    std::cout << "Going to next time frame." << std::endl;
}

void makeOffer()
{
    std::cout << "Make an offer - enter the amount." << std::endl;
}

void placeBid()
{
    std::cout << "Make a bid - enter the amount." << std::endl;
}

void printExchangeStats()
{
    std::cout << "Market looks good." << std::endl;
}

void printHelp()
{
    std::cout << "Help - your aim is to make money. Analyze the market and make binds and offers." << std::endl;
}

void printWallet()
{
    std::cout << "Your wallet is empty." << std::endl;
}

bool optionIsValid(int userOption)
{
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }

    if (userOption < 1 or userOption > numMenuOptions)
    {
        return false;
    }

    return true;
}

void processUserOption(int userOption, std::map<int, void (*)()> menu)
{
    if (!optionIsValid(userOption))
    {
        std::cout << "Invalid input. Please enter a number from 1-" << numMenuOptions << std::endl;
        return;
    }

    menu[userOption]();
}

void printMenu()
{
    std::string options[numMenuOptions] = {
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
    std::cout << "Press 1-" << numMenuOptions << std::endl;
}

std::map<int, void (*)()> getMenu()
{
    std::map<int, void (*)()> menu;

    menu[1] = printHelp;
    menu[2] = printExchangeStats;
    menu[3] = makeOffer;
    menu[4] = placeBid;
    menu[5] = printWallet;
    menu[6] = goToNextTimeFrame;
    menu[7] = exitProgram;

    return menu;
}

enum class orderBookType
{
    ask,
    bid
};

class OrderBookEntry
{
private:
    std::string timestamp;
    std::string products;
    orderBookType orderType;
    double price;
    double amount;

public:
    /** Create a new OrderBookEntry
     */
    OrderBookEntry::OrderBookEntry(std::string _timestamp, std::string _products, orderBookType _orderType, double _price, double _amount)
        : timestamp(_timestamp),
          products(_products),
          orderType(_orderType),
          price(_price),
          amount(_amount) {}

    std::string getTimestamp() const
    {
        return timestamp;
    }

    std::string getProducts() const
    {
        return products;
    }

    orderBookType getOrderType() const
    {
        return orderType;
    }

    double getPrice() const
    {
        return price;
    }

    double getAmount() const
    {
        return amount;
    }
};

double computeAveragePrice(const std::vector<OrderBookEntry> &entries)
{
    double sum;

    for (const OrderBookEntry &entry : entries)
    {
        sum += entry.getPrice();
    }

    return sum / entries.size();
}

double computeLowPrice(const std::vector<OrderBookEntry> &entries)
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

double computeHighPrice(const std::vector<OrderBookEntry> &entries)
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

double computePriceSpread(const std::vector<OrderBookEntry> &entries)
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

int main()
{
    std::vector<OrderBookEntry> entries;

    entries.push_back(OrderBookEntry{
        "2020/03/17 17:01:24.884492",
        "ETH/BTC",
        orderBookType::bid,
        1000,
        9.14455526});

    entries.push_back(OrderBookEntry{
        "2020/03/17 17:01:24.884492",
        "ETH/BTC",
        orderBookType::bid,
        2000,
        9.14455526});

    entries.push_back(OrderBookEntry{
        "2020/03/17 17:01:24.884492",
        "BTC/USDT",
        orderBookType::ask,
        300,
        300.5});

    std::cout << "High: " << computeHighPrice(entries) << std::endl;
    std::cout << "Low: " << computeLowPrice(entries) << std::endl;
    std::cout << "Avg: " << computeAveragePrice(entries) << std::endl;
    std::cout << "Spread: " << computePriceSpread(entries) << std::endl;

    for (const OrderBookEntry &entry : entries)
    {
        std::cout << "Timestamp: " << entry.getTimestamp() << std::endl;
    }

    while (printAgain)
    {
        printMenu();
        int userOption = getUserOption();
        std::map<int, void (*)()> menu = getMenu();
        processUserOption(userOption, menu);
    }

    return 0;
}
