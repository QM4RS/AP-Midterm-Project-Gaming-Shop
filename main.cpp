#include "include/Utils.hpp"
#include "include/User.hpp"
#include "include/Store.hpp"
#include "include/UserMenu.hpp"
#include <iostream>
using namespace std;

Store globalStore;

void adminMenu() {
    while (true) {
        clear_screen();
        set_color(ConsoleColor::BRIGHT_MAGENTA);
        cout << "[ Admin Panel ]\n";
        reset_color();
        cout << "1) Show All Products\n";
        cout << "2) Add Product\n";
        cout << "3) Remove Product\n";
        cout << "4) Inject Capital\n";
        cout << "5) Show Store Wallet\n";
        cout << "6) Show Total Inventory Value\n";
        cout << "7) Back to Main Menu\n";
        cout << ">> ";

        int c = get_int_input();
        switch (c) {
            case 1: globalStore.showAllProducts(); wait(2); break;
            case 2: {
                cin.ignore();
                string name, category;
                int price, stock;
                cout << "Enter product name: "; getline(cin, name);
                cout << "Enter category: "; getline(cin, category);
                cout << "Enter price: "; price = get_int_input();
                cout << "Enter stock: "; stock = get_int_input();
                Product p(category, name, price, stock);
                globalStore.addProduct(p);
                cout << "Product added.\n"; wait(1);
                break;
            }
            case 3: {
                cin.ignore();
                string name, category;
                int qty;
                cout << "Enter product name: "; getline(cin, name);
                cout << "Enter category: "; getline(cin, category);
                cout << "Enter quantity to remove: "; qty = get_int_input();
                globalStore.removeProduct(name, category, qty);
                wait(1);
                break;
            }
            case 4: {
                cout << "Enter amount to inject: ";
                int amt = get_int_input();
                globalStore.injectCapital(amt);
                cout << "Capital injected.\n"; wait(1);
                break;
            }
            case 5:
                cout << "Store Wallet: " << globalStore.getWalletBalance() << "\n"; wait(1); break;
            case 6:
                cout << "Inventory Value: " << globalStore.getTotalInventoryValue() << "\n"; wait(1); break;
            case 7: return;
            default:
                set_color(ConsoleColor::RED);
                cout << "Invalid option.\n"; reset_color(); wait(1);
        }
    }
}

int main() {
    User user;

    while (true) {
        displayWelcomeScreen();
        set_color(ConsoleColor::YELLOW);
        cout << "1) User\n2) Admin\n3) Exit\n>> ";
        reset_color();

        int choice = get_int_input();
        if (choice == 1) userMenu(user);
        else if (choice == 2) {
            std::string pass;
            clear_screen();
            set_color(ConsoleColor::YELLOW);
            std::cout << "Enter admin password: ";
            reset_color();
            std::cin >> pass;

            if (pass == "admin1admin") {
                adminMenu();
            } else {
                set_color(ConsoleColor::RED);
                std::cout << "Incorrect password!\n";
                reset_color();
                wait(1);
            }
        }

        else if (choice == 3) {
            cout << "Goodbye!\n"; break;
        } else {
            set_color(ConsoleColor::RED);
            cout << "Invalid selection.\n";
            reset_color();
            wait(1);
        }
    }
    return 0;
}
