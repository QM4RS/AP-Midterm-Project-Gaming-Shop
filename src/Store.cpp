#include "../include/Store.hpp"
#include "../include/Utils.hpp"
#include <iostream>
using namespace std;

Store::Store() : wallet(0) {}

void Store::addProduct(const Product& product) {
    for (auto& p : products) {
        if (to_lowercase(p.getName()) == to_lowercase(product.getName()) &&
            to_lowercase(p.getCategory()) == to_lowercase(product.getCategory())) {
            p.increaseStock(product.getStock());
            p.setPrice(product.getPrice());
            return;
        }
    }
    products.push_back(product);
}

void Store::removeProduct(const string& name, const string& category, int qty) {
    for (auto it = products.begin(); it != products.end(); ++it) {
        if (to_lowercase(it->getName()) == to_lowercase(name) &&
            to_lowercase(it->getCategory()) == to_lowercase(category)) {
            if (qty >= it->getStock()) {
                products.erase(it);
                cout << "Product removed from inventory.\n";
            } else {
                it->decreaseStock(qty);
                cout << "Reduced quantity of product.\n";
            }
            return;
        }
    }
    cout << "Product not found.\n";
}

void Store::showAllProducts() const {
    if (products.empty()) {
        cout << "No products available.\n";
        return;
    }
    for (const auto& p : products) {
        p.display();
    }
}

Product* Store::findProduct(const string& name, const string& category) {
    for (auto& p : products) {
        if (to_lowercase(p.getName()) == to_lowercase(name) &&
            to_lowercase(p.getCategory()) == to_lowercase(category)) {
            return &p;
        }
    }
    return nullptr;
}

void Store::injectCapital(int amount) {
    wallet += amount;
}

int Store::getWalletBalance() const {
    return wallet;
}

int Store::getTotalInventoryValue() const {
    int total = 0;
    for (const auto& p : products) {
        total += p.getPrice() * p.getStock();
    }
    return total;
}

const std::vector<Product>& Store::getProductList() const {
    return products;
}
