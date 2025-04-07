#pragma once
#include <vector>
#include "include/CartItem.hpp"
#include "include/Product.hpp"

class User {
private:
    int wallet;
    std::vector<CartItem> cart;

public:
    User(int initialWallet = 500);

    void addToCart(const Product& product, int qty);
    void showCart() const;
    void chargeWallet(int amount);
    int getWalletBalance() const;
    void clearCart();
};