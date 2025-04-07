#include "../include/UserMenu.hpp"
#include "../include/Utils.hpp"
#include <iostream>
using namespace std;

extern Store globalStore;

void userMenu(User& user) {
    while (true) {
        clear_screen();
        set_color(ConsoleColor::BRIGHT_BLUE);
        cout << "[ User Panel ]\n";
        reset_color();
        cout << "1) Show All Products\n";
        cout << "2) Search Product\n";
        cout << "3) Add to Cart\n";
        cout << "4) View Cart\n";
        cout << "5) Charge Wallet\n";
        cout << "6) Show Wallet Balance\n";
        cout << "7) Back to Main Menu\n";
        cout << ">> ";

        int choice = get_int_input();
        switch (choice) {
            case 1: showAllProductsUser(); break;
            case 2: searchProductUser(); break;
            case 3: addToCartMenu(user); break;
            case 4: showUserCart(user); break;
            case 5: chargeWalletMenu(user); break;
            case 6: showWalletBalance(user); break;
            case 7: return;
            default:
                set_color(ConsoleColor::RED);
                cout << "\nInvalid choice.\n";
                reset_color();
                wait(1);
        }
    }
}

void showAllProductsUser() {
    clear_screen();
    globalStore.showAllProducts();
    wait(2);
}

void searchProductUser() {
    clear_screen();
    cin.ignore();
    string name;
    cout << "Enter product name: ";
    getline(cin, name);

    for (auto& p : globalStore.getProductList()) {
        if (to_lowercase(p.getName()).find(to_lowercase(name)) != string::npos) {
            p.display();
        }
    }
    wait(2);
}

void addToCartMenu(User& user) {
    clear_screen();
    cin.ignore();
    string name, category;
    int qty;

    cout << "Enter product name: ";
    getline(cin, name);
    cout << "Enter category: ";
    getline(cin, category);

    Product* product = globalStore.findProduct(name, category);
    if (!product) {
        set_color(ConsoleColor::RED);
        cout << "Product not found.\n";
        reset_color();
        wait(1);
        return;
    }

    cout << "Enter quantity: ";
    qty = get_int_input();
    if (qty > product->getStock()) {
        set_color(ConsoleColor::RED);
        cout << "Not enough stock.\n";
        reset_color();
        wait(1);
        return;
    }

    user.addToCart(*product, qty);
    product->decreaseStock(qty);
    cout << "Added to cart.\n";
    wait(1);
}

void showUserCart(const User& user) {
    clear_screen();
    user.showCart();
    wait(2);
}

void chargeWalletMenu(User& user) {
    clear_screen();
    cout << "Enter amount to charge: ";
    int amt = get_int_input();
    user.chargeWallet(amt);
    cout << "Wallet charged.\n";
    wait(1);
}

void showWalletBalance(const User& user) {
    clear_screen();
    cout << "Wallet Balance: " << user.getWalletBalance() << "\n";
    wait(2);