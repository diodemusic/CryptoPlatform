#pragma once

#include <string>

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
    /** Creates a new OrderBookEntry */
    OrderBookEntry(std::string _timestamp, std::string _products, orderBookType _orderType, double _price, double _amount);
    std::string getTimestamp() const;
    std::string getProducts() const;
    orderBookType getOrderType() const;
    double getPrice() const;
    double getAmount() const;
};
