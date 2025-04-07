#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <limits>

using namespace std;

// Structs for Product and CartItem
struct Product {
    string category;
    string name;
    int price;
    int count_in_warehouse;
};

struct CartItem {
    string category;
    string name;
    int price;
    int quantity;
};

// Global Variables
string admin_password = "admin1admin ";
int store_wallet_balance = 0;
int user_wallet_balance = 500;
vector<Product> Products;
vector<CartItem> userCart;

// Console Color Handling
enum ConsoleColor {
    BLACK = 0,
    BLUE = 1,
    GREEN = 2,
    CYAN = 3,
    RED = 4,
    MAGENTA = 5,
    YELLOW = 6,
    WHITE = 7,
    BRIGHT_BLACK = 8,
    BRIGHT_BLUE = 9,
    BRIGHT_GREEN = 10,
    BRIGHT_CYAN = 11,
    BRIGHT_RED = 12,
    BRIGHT_MAGENTA = 13,
    BRIGHT_YELLOW = 14,
    BRIGHT_WHITE = 15
};

// Function to set console text color
void set_color(ConsoleColor color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

// Function to reset console color to default
void reset_color() {
    set_color(WHITE);
}

// Function to clear the screen (adjust as per operating system)
void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Function to convert string to lowercase
string to_lowercase(const string &data) {
    string result = data;
    for (auto &ch : result) ch = tolower(ch);
    return result;
}

// Function to pause the program (only during authentication)
void wait(int seconds) {
    Sleep(seconds * 1000);
}

// Function to check if a string contains only digits
bool is_valid_int(const string &s) {
    if (s.empty()) return false;
    for (char c : s) {
        if (!isdigit(c)) return false;
    }
    return true;
}

// Function to convert string to integer
int to_int(const string &s) {
    return stoi(s);
}

// Function to get numeric input from user and safely convert to int
int get_int_input() {
    while (true) {
        string temp;
        cin >> temp;
        if (is_valid_int(temp)) {
            return to_int(temp);
        } else {
            set_color(RED);
            cout << "Invalid input! Please enter a valid number: ";
            reset_color();
        }
    }
}

// Function to ask user to continue or return to menu
bool ask_to_continue_or_menu(const string &menuType) {
    set_color(YELLOW);
    cout << "\n1) Continue in this section\n2) Back to " << menuType << " Menu\n>> ";
    reset_color();
    int choice = get_int_input();
    return (choice == 1);
}

// Function Declarations for Admin Panel
void admin_menu();
void show_all_products_admin();
void add_product();
void remove_product();
void find_product_by_name_admin();
void total_store_value();
void get_store_wallet_balance();
void capital_injection();

// Function Declarations for User Panel
void user_menu();
void show_all_products_user();
void search_product_by_name_user();
void charge_user_wallet();
void show_user_wallet_balance();
void show_cart();
void add_to_cart();
void show_products_by_category();

// Function Declarations for Authentication
void authentication();
int main();

// Function to display ASCII Art for Welcome Screen
void display_welcome_screen() {
    set_color(BRIGHT_BLUE);
    cout << "=============================================\n";
    cout << "        WELCOME TO THE GAMING SHOP           \n";
    cout << "=============================================\n\n";
    reset_color();
}

// --------------------- Administration ---------------------
void show_all_products_admin() {
    clear_screen();
    display_welcome_screen();
    set_color(BRIGHT_GREEN);
    cout << "------ All Products ------\n";
    reset_color();

    if (Products.empty()) {
        set_color(RED);
        cout << "No products in the shop.\n";
        reset_color();
    } else {
        for (auto &p : Products) {
            set_color(CYAN);
            cout << "Category: " << p.category << "\n";
            cout << "Name: " << p.name << "\n";
            cout << "Price: " << p.price << "\n";
            cout << "Count in Warehouse: " << p.count_in_warehouse << "\n\n";
            reset_color();
        }
    }

    if (ask_to_continue_or_menu("Admin")) show_all_products_admin();
    else admin_menu();
}

void add_product() {
    clear_screen();
    display_welcome_screen();
    set_color(BRIGHT_GREEN);
    cout << "------ Add New Product ------\n\n";
    reset_color();

    Product new_product;
    cout << "Enter product category (single word): ";
    cin >> new_product.category;
    cin.ignore(1, '\n');

    cout << "Enter product name (can include spaces): ";
    getline(cin, new_product.name);

    cout << "Enter product price: ";
    int temp_price = get_int_input();
    new_product.price = temp_price;

    cout << "Enter quantity to add: ";
    int temp_count = get_int_input();
    new_product.count_in_warehouse = temp_count;

    bool exists = false;
    for (auto &prod : Products) {
        if (to_lowercase(prod.name) == to_lowercase(new_product.name) &&
            to_lowercase(prod.category) == to_lowercase(new_product.category)) {
            prod.count_in_warehouse += new_product.count_in_warehouse;
            prod.price = new_product.price;
            set_color(GREEN);
            cout << "\nProduct updated successfully.\n";
            reset_color();
            exists = true;
            break;
        }
    }
    if (!exists) {
        Products.push_back(new_product);
        set_color(GREEN);
        cout << "\nNew product added successfully.\n";
        reset_color();
    }

    if (ask_to_continue_or_menu("Admin")) add_product();
    else admin_menu();
}

void remove_product() {
    clear_screen();
    display_welcome_screen();
    set_color(BRIGHT_GREEN);
    cout << "------ Remove Product ------\n\n";
    reset_color();

    cout << "Enter product category: ";
    string category;
    cin >> category;
    cin.ignore(1, '\n');

    cout << "Enter product name: ";
    string name;
    getline(cin, name);

    cout << "Enter quantity to remove: ";
    int quantity = get_int_input();

    bool found = false;
    for (auto it = Products.begin(); it != Products.end();) {
        if (to_lowercase(it->category) == to_lowercase(category) &&
            to_lowercase(it->name) == to_lowercase(name)) {
            found = true;
            if (it->count_in_warehouse >= quantity) {
                it->count_in_warehouse -= quantity;
                set_color(GREEN);
                cout << "\nRemoved " << quantity << " of \"" << it->name << "\".\n";
                reset_color();
                if (it->count_in_warehouse == 0) {
                    it = Products.erase(it);
                    set_color(YELLOW);
                    cout << "Product \"" << it->name << "\" is now out of stock and removed from the inventory.\n";
                    reset_color();
                } else {
                    ++it;
                }
            } else {
                set_color(RED);
                cout << "\nNot enough stock to remove.\n";
                reset_color();
                ++it;
            }
            break;
        } else {
            ++it;
        }
    }
    if (!found) {
        set_color(RED);
        cout << "\nNo such product found.\n";
        reset_color();
    }

    if (ask_to_continue_or_menu("Admin")) remove_product();
    else admin_menu();
}

void find_product_by_name_admin() {
    clear_screen();
    display_welcome_screen();
    set_color(BRIGHT_GREEN);
    cout << "------ Search Product ------\n\n";
    reset_color();

    cout << "Enter product name (partial match): ";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    string name;
    getline(cin, name);
    string key = to_lowercase(name);
    bool found = false;

    for (auto &p : Products) {
        string pname = to_lowercase(p.name);
        if (pname.find(key) != string::npos) {
            found = true;
            set_color(CYAN);
            cout << "\nCategory: " << p.category << "\n";
            cout << "Name: " << p.name << "\n";
            cout << "Price: " << p.price << "\n";
            cout << "Count: " << p.count_in_warehouse << "\n\n";
            reset_color();
        }
    }
    if (!found) {
        set_color(RED);
        cout << "\nNo matching products found.\n";
        reset_color();
    }

    if (ask_to_continue_or_menu("Admin")) find_product_by_name_admin();
    else admin_menu();
}

void total_store_value() {
    clear_screen();
    display_welcome_screen();
    set_color(BRIGHT_GREEN);
    cout << "------ Total Store Value ------\n\n";
    reset_color();

    long long total_qty = 0, total_val = 0;
    for (auto &p : Products) {
        total_qty += p.count_in_warehouse;
        total_val += (long long)p.price * p.count_in_warehouse;
    }
    set_color(BRIGHT_YELLOW);
    cout << "Total quantity of products: " << total_qty << "\n";
    cout << "Total value of store inventory: " << total_val << "\n";
    reset_color();

    if (ask_to_continue_or_menu("Admin")) total_store_value();
    else admin_menu();
}

void get_store_wallet_balance() {
    clear_screen();
    display_welcome_screen();
    set_color(BRIGHT_GREEN);
    cout << "------ Store Wallet Balance ------\n\n";
    reset_color();

    set_color(BRIGHT_YELLOW);
    cout << "Current Store Wallet Balance: " << store_wallet_balance << "\n";
    reset_color();

    if (ask_to_continue_or_menu("Admin")) get_store_wallet_balance();
    else admin_menu();
}

void capital_injection() {
    clear_screen();
    display_welcome_screen();
    set_color(BRIGHT_GREEN);
    cout << "------ Capital Injection ------\n\n";
    reset_color();

    cout << "Enter amount to inject into the store wallet: ";
    int val = get_int_input();
    store_wallet_balance += val;
    set_color(GREEN);
    cout << "\nCapital injected successfully. New Store Wallet Balance: " << store_wallet_balance << "\n";
    reset_color();

    if (ask_to_continue_or_menu("Admin")) capital_injection();
    else admin_menu();
}

void admin_menu() {
    while (true) {
        clear_screen();
        display_welcome_screen();
        set_color(BRIGHT_BLUE);
        cout << "[ Admin Panel ]\n";
        reset_color();
        set_color(BRIGHT_YELLOW);
        cout << "---------------------------------\n";
        reset_color();
        set_color(BRIGHT_WHITE);
        cout << "1) Show All Products\n";
        cout << "2) Add Product\n";
        cout << "3) Remove Product\n";
        cout << "4) Search By Name\n";
        cout << "5) Total Store Value\n";
        cout << "6) Store Wallet Balance\n";
        cout << "7) Capital Injection\n";
        cout << "8) Back to Main Menu\n";
        reset_color();
        set_color(YELLOW);
        cout << "---------------------------------\n";
        cout << "Select an option: ";
        reset_color();

        int c = get_int_input();
        switch (c) {
            case 1: show_all_products_admin(); break;
            case 2: add_product(); break;
            case 3: remove_product(); break;
            case 4: find_product_by_name_admin(); break;
            case 5: total_store_value(); break;
            case 6: get_store_wallet_balance(); break;
            case 7: capital_injection(); break;
            case 8: main(); break; // Return to main menu
            default:
                set_color(RED);
                cout << "\nInvalid option. Please try again.\n";
                reset_color();
                wait(1);
                break;
        }
    }
}

// --------------------- User ---------------------
void show_all_products_user() {
    clear_screen();
    display_welcome_screen();
    set_color(BRIGHT_GREEN);
    cout << "------ All Products ------\n";
    reset_color();

    if (Products.empty()) {
        set_color(RED);
        cout << "No products available.\n";
        reset_color();
    } else {
        for (auto &p : Products) {
            set_color(CYAN);
            cout << "Category: " << p.category << "\n";
            cout << "Name: " << p.name << "\n";
            cout << "Price: " << p.price << "\n";
            cout << "Available: " << p.count_in_warehouse << "\n\n";
            reset_color();
        }
    }

    if (ask_to_continue_or_menu("User")) show_all_products_user();
    else user_menu();
}

void search_product_by_name_user() {
    clear_screen();
    display_welcome_screen();
    set_color(BRIGHT_GREEN);
    cout << "------ Search Product ------\n\n";
    reset_color();

    cout << "Enter product name (partial match): ";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    string name;
    getline(cin, name);
    string key = to_lowercase(name);
    bool found = false;

    for (auto &p : Products) {
        string pname = to_lowercase(p.name);
        if (pname.find(key) != string::npos) {
            found = true;
            set_color(CYAN);
            cout << "\nCategory: " << p.category << "\n";
            cout << "Name: " << p.name << "\n";
            cout << "Price: " << p.price << "\n";
            cout << "Available: " << p.count_in_warehouse << "\n\n";
            reset_color();
        }
    }
    if (!found) {
        set_color(RED);
        cout << "\nNo matching products found.\n";
        reset_color();
    }

    if (ask_to_continue_or_menu("User")) search_product_by_name_user();
    else user_menu();
}

void charge_user_wallet() {
    clear_screen();
    display_welcome_screen();
    set_color(BRIGHT_GREEN);
    cout << "------ Charge Wallet ------\n\n";
    reset_color();

    set_color(BRIGHT_YELLOW);
    cout << "Current Wallet Balance: " << user_wallet_balance << "\n";
    reset_color();
    cout << "Enter amount to deposit: ";
    int amt = get_int_input();
    user_wallet_balance += amt;
    set_color(GREEN);
    cout << "\nWallet charged successfully. New Balance: " << user_wallet_balance << "\n";
    reset_color();

    if (ask_to_continue_or_menu("User")) charge_user_wallet();
    else user_menu();
}

void show_user_wallet_balance() {
    clear_screen();
    display_welcome_screen();
    set_color(BRIGHT_GREEN);
    cout << "------ Wallet Balance ------\n\n";
    reset_color();

    set_color(BRIGHT_YELLOW);
    cout << "Your Current Wallet Balance: " << user_wallet_balance << "\n";
    reset_color();

    if (ask_to_continue_or_menu("User")) show_user_wallet_balance();
    else user_menu();
}

void show_cart() {
    clear_screen();
    display_welcome_screen();
    set_color(BRIGHT_GREEN);
    cout << "------ Your Cart ------\n";
    reset_color();

    if (userCart.empty()) {
        set_color(RED);
        cout << "Your cart is empty.\n";
        reset_color();
    } else {
        long long total_cost = 0;
        for (auto &item : userCart) {
            set_color(CYAN);
            cout << "Category: " << item.category << "\n";
            cout << "Name: " << item.name << "\n";
            cout << "Price: " << item.price << "\n";
            cout << "Quantity: " << item.quantity << "\n\n";
            reset_color();
            total_cost += (long long)item.price * item.quantity;
        }
        set_color(BRIGHT_YELLOW);
        cout << "Total Cost: " << total_cost << "\n";
        cout << "Your Wallet Balance: " << user_wallet_balance << "\n";
        reset_color();
    }

    if (ask_to_continue_or_menu("User")) show_cart();
    else user_menu();
}

void add_to_cart() {
    clear_screen();
    display_welcome_screen();
    set_color(BRIGHT_GREEN);
    cout << "------ Add to Cart ------\n\n";
    reset_color();

    cout << "Enter product name to add to cart: ";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    string name;
    getline(cin, name);

    bool found = false;
    for (auto &p : Products) {
        if (to_lowercase(p.name) == to_lowercase(name)) {
            found = true;

            int alreadyInCart = 0;
            for (auto &item : userCart) {
                if (to_lowercase(item.name) == to_lowercase(p.name) &&
                    to_lowercase(item.category) == to_lowercase(p.category)) {
                    alreadyInCart = item.quantity;
                    break;
                }
            }
            int available = p.count_in_warehouse - alreadyInCart;
            if (available <= 0) {
                set_color(RED);
                cout << "\nNo more \"" << p.name << "\" can be added to the cart.\n";
                reset_color();
                break;
            }

            cout << "How many would you like to add? (Available: " << available << "): ";
            int qty = get_int_input();
            if (qty <= 0) {
                set_color(RED);
                cout << "\nInvalid quantity entered.\n";
                reset_color();
                break;
            }

            if (qty <= available) {
                bool inCart = false;
                for (auto &item : userCart) {
                    if (to_lowercase(item.name) == to_lowercase(p.name) &&
                        to_lowercase(item.category) == to_lowercase(p.category)) {
                        item.quantity += qty;
                        inCart = true;
                        break;
                    }
                }
                if (!inCart) {
                    userCart.push_back({p.category, p.name, p.price, qty});
                }
                set_color(GREEN);
                cout << "\n" << qty << " of \"" << p.name << "\" added to your cart.\n";
                reset_color();
            } else {
                set_color(RED);
                cout << "\nNot enough stock available.\n";
                reset_color();
            }
            break;
        }
    }
    if (!found) {
        set_color(RED);
        cout << "\nProduct not found.\n";
        reset_color();
    }

    if (ask_to_continue_or_menu("User")) add_to_cart();
    else user_menu();
}

void show_products_by_category() {
    clear_screen();
    display_welcome_screen();
    set_color(BRIGHT_GREEN);
    cout << "------ Show Products by Category ------\n\n";
    reset_color();

    cout << "Enter category to view products: ";
    string cat;
    cin >> cat;
    bool found = false;

    for (auto &p : Products) {
        if (to_lowercase(p.category) == to_lowercase(cat)) {
            if (!found) {
                set_color(BRIGHT_CYAN);
                cout << "\nProducts under \"" << cat << "\" category:\n";
                reset_color();
            }
            found = true;
            set_color(CYAN);
            cout << "\nName: " << p.name << "\n";
            cout << "Price: " << p.price << "\n";
            cout << "Available: " << p.count_in_warehouse << "\n";
            reset_color();
        }
    }
    if (!found) {
        set_color(RED);
        cout << "\nNo products found under this category.\n";
        reset_color();
    }

    if (ask_to_continue_or_menu("User")) show_products_by_category();
    else user_menu();
}

void user_menu() {
    while (true) {
        clear_screen();
        display_welcome_screen();
        set_color(BRIGHT_BLUE);
        cout << "[ User Panel ]\n";
        reset_color();
        set_color(BRIGHT_YELLOW);
        cout << "---------------------------------\n";
        reset_color();
        set_color(BRIGHT_WHITE);
        cout << "1) Show All Products\n";
        cout << "2) Search By Name\n";
        cout << "3) Charge Wallet\n";
        cout << "4) View Wallet Balance\n";
        cout << "5) Show Cart\n";
        cout << "6) Add to Cart\n";
        cout << "7) Show Products by Category\n";
        cout << "8) Back to Main Menu\n";
        reset_color();
        set_color(YELLOW);
        cout << "---------------------------------\n";
        cout << "Select an option: ";
        reset_color();

        int c = get_int_input();
        switch (c) {
            case 1: show_all_products_user(); break;
            case 2: search_product_by_name_user(); break;
            case 3: charge_user_wallet(); break;
            case 4: show_user_wallet_balance(); break;
            case 5: show_cart(); break;
            case 6: add_to_cart(); break;
            case 7: show_products_by_category(); break;
            case 8: main(); break; // Return to main menu
            default:
                set_color(RED);
                cout << "\nInvalid option. Please try again.\n";
                reset_color();
                wait(1);
                break;
        }
    }
}

// --------------------- Authentication / Main ---------------------
void authentication() {
    clear_screen();
    display_welcome_screen();
    set_color(BRIGHT_RED);
    cout << "------ Admin Authentication ------\n\n";
    reset_color();

    cout << "Enter admin password: ";
    string pass;
    cin >> pass;
    cout << "\nAuthorizing";
    for(int i = 0; i < 3; ++i){
        cout << ".";
        wait(1);
    }
    cout << "\n";

    if (pass == admin_password) {
        set_color(GREEN);
        cout << "Access Granted. Welcome, Admin!\n";
        reset_color();
        wait(2);
        admin_menu();
    } else {
        set_color(RED);
        cout << "Access Denied. Incorrect password.\n";
        reset_color();
        wait(2);
        return;
    }
}

int main() {
    while (true) {
        clear_screen();
        display_welcome_screen();
        set_color(BRIGHT_BLUE);
        cout << "====== Main Menu ======\n";
        reset_color();
        set_color(BRIGHT_YELLOW);
        cout << "1) User\n";
        cout << "2) Admin\n";
        cout << "3) Exit\n";
        reset_color();
        set_color(YELLOW);
        cout << "------------------------\n";
        cout << "Select your role: ";
        reset_color();

        int role;
        role = get_int_input();

        if (role == 1) {
            user_menu();
        }
        else if (role == 2) {
            authentication();
        }
        else if (role == 3) {
            set_color(BRIGHT_GREEN);
            cout << "\nThank you for visiting the Gaming Shop. Goodbye!\n";
            reset_color();
            wait(2);
            break;
        }
        else {
            set_color(RED);
            cout << "\nInvalid selection. Please try again.\n";
            reset_color();
            wait(1);
        }
    }
    return 0;
}
