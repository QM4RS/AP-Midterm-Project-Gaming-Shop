#pragma once
#include <string>

class Product
{
private:
    std::string category;
    std::string name;
    int price;
    int stock;

public:
    Product(const std::string &category, const std::string &name, int price, int stock);
    void increaseStock(int qty);
    void decreaseStock(int qty);
    void display() const;

    std::string getCategory() const;
    std::string getName() const;
    int getPrice() const;
    int getStock() const;

    void setPrice(int newPrice);
};