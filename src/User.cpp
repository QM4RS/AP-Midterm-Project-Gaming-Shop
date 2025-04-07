#include "../include/User.hpp"
#include "../include/Utils.hpp"
#include <iostream>
using namespace std;

User::User(int initialWallet) : wallet(initialWallet) {}

void User::addToCart(const Product& product, int qty) {
    for (auto& item : cart) {
        if (to_lowercase(item.getProductName()) == to_lowercase(product.getName()) &&
            to_lowercase(item.getProductCategory()) == to_lowercase(product.getCategory())) {
            item.increaseQuantity(qty);
            return;
        }
    }
    cart.emplace_back(product, qty);
}

void User::showCart() const {
    if (cart.empty()) {
        cout << "Your cart is empty.\n";
        return;
    }
    int total = 0;
    for (const auto& item : cart) {
        item.display();
        total += item.getTotalPrice();
    }
    cout << "Total Cost: " << total << "\n";
    cout << "Your Wallet: " << wallet << "\n";
}

void User::chargeWallet(int amount) {
    wallet += amount;
}

int User::getWalletBalance() const {
    return wallet;
}

void User::clearCart() {
    cart.clear();
}