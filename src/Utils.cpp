#include "../include/Utils.hpp"
#include <iostream>
#include <cctype>
#include <windows.h>
using namespace std;

void set_color(ConsoleColor color) {
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, static_cast<int>(color));
#endif
}

void reset_color() {
    set_color(ConsoleColor::WHITE);
}

void clear_screen() {
    system("cls");
    
}

void wait(int seconds) {
#ifdef _WIN32
    Sleep(seconds * 1000);
#else
    sleep(seconds);
#endif
}

bool is_valid_int(const string& s) {
    if (s.empty()) return false;
    for (char c : s) {
        if (!isdigit(c)) return false;
    }
    return true;
}

int to_int(const string& s) {
    return stoi(s);
}

int get_int_input() {
    while (true) {
        string input;
        cin >> input;
        if (is_valid_int(input)) {
            return to_int(input);
        } else {
            set_color(ConsoleColor::RED);
            cout << "Invalid number! Try again: ";
            reset_color();
        }
    }
}

string to_lowercase(const string& input) {
    string result = input;
    for (char& c : result) {
        c = tolower(c);
    }
    return result;
}