#include "OrderBookEntry.h"

OrderBookEntry::OrderBookEntry(std::string _timestamp, std::string _products, orderBookType _orderType, double _price, double _amount)
    : timestamp(_timestamp),
      products(_products),
      orderType(_orderType),
      price(_price),
      amount(_amount) {}

std::string OrderBookEntry::getTimestamp() const
{
    return timestamp;
}

std::string OrderBookEntry::getProducts() const
{
    return products;
}

orderBookType OrderBookEntry::getOrderType() const
{
    return orderType;
}

double OrderBookEntry::getPrice() const
{
    return price;
}

double OrderBookEntry::getAmount() const
{
    return amount;
}
