#include "../include/Product.hpp"
#include <iostream>
using namespace std;

Product::Product(const string &category, const string &name, int price, int stock)
    : category(category), name(name), price(price), stock(stock) {}

void Product::increaseStock(int qty)
{
    stock += qty;
}

void Product::decreaseStock(int qty)
{
    if (qty <= stock)
        stock -= qty;
}

void Product::display() const
{
    cout << "Category: " << category << endl;
    cout << "Name: " << name << endl;
    cout << "Price: " << price << endl;
    cout << "In Stock: " << stock << endl;
    cout << "--------------------------" << endl;
}

string Product::getCategory() const
{
    return category;
}

string Product::getName() const
{
    return name;
}

int Product::getPrice() const
{
    return price;
}

int Product::getStock() const
{
    return stock;
}

void Product::setPrice(int newPrice)
{
    price = newPrice;
}