#include "../include/CartItem.hpp"
#include <iostream>
using namespace std;

CartItem::CartItem(const Product &product, int quantity)
    : product(product), quantity(quantity) {}

void CartItem::increaseQuantity(int qty)
{
    quantity += qty;
}

int CartItem::getTotalPrice() const
{
    return product.getPrice() * quantity;
}

void CartItem::display() const
{
    cout << "Product: " << product.getName() << endl;
    cout << "Category: " << product.getCategory() << endl;
    cout << "Price per unit: " << product.getPrice() << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "Total: " << getTotalPrice() << endl;
    cout << "--------------------------" << endl;
}

string CartItem::getProductName() const
{
    return product.getName();
}

string CartItem::getProductCategory() const
{
    return product.getCategory();
}