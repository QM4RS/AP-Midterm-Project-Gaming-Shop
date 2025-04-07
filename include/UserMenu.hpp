#pragma once
#include "User.hpp"
#include "Store.hpp"

void userMenu(User& user);
void showAllProductsUser();
void searchProductUser();
void addToCartMenu(User& user);
void showUserCart(const User& user);
void chargeWalletMenu(User& user);
void showWalletBalance(const User& user);
