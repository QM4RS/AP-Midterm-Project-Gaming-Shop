#include "../include/Utils.hpp"
#include <iostream>
using namespace std;

void displayWelcomeScreen() {
    clear_screen();
    set_color(ConsoleColor::BRIGHT_CYAN);
    cout << "===============================\n";
    cout << "     WELCOME TO GAME SHOP     \n";
    cout << "===============================\n\n";
    reset_color();
    wait(1);
}
