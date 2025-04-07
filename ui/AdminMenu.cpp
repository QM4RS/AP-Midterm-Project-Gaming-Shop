#include "../include/Store.hpp"
#include "../include/Utils.hpp"
#include <iostream>
using namespace std;

extern Store globalStore;

void showAllProductsAdmin()
{
    clear_screen();
    set_color(ConsoleColor::BRIGHT_CYAN);
    cout << "--- All Products in Store ---\n";
    reset_color();
    globalStore.showAllProducts();
    wait(1);
}

void addProductMenu()
{
    clear_screen();
    string name, category;
    int price, stock;

    cout << "Enter product name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter category: ";
    getline(cin, category);

    cout << "Enter price: ";
    price = get_int_input();

    cout << "Enter stock count: ";
    stock = get_int_input();

    Product newProduct(category, name, price, stock);
    globalStore.addProduct(newProduct);
    set_color(ConsoleColor::GREEN);
    cout << "\nProduct added successfully!\n";
    reset_color();
    wait(1);
}

void removeProductMenu()
{
    clear_screen();
    string name, category;
    int qty;

    cout << "Enter product name to remove: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter category: ";
    getline(cin, category);

    cout << "Enter quantity to remove: ";
    qty = get_int_input();

    globalStore.removeProduct(name, category, qty);
    wait(1);
}