#pragma once
#include <string>

enum class ConsoleColor {
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


void set_color(ConsoleColor color);

void reset_color();

void clear_screen();

void displayWelcomeScreen();

void wait(int seconds);

bool is_valid_int(const std::string& s);

int to_int(const std::string& s);

int get_int_input();

std::string to_lowercase(const std::string& input);
