#include <string>
#include "Product.hpp"

class CartItem
{
private:
    Product product;
    int quantity;

public:
    CartItem(const Product &product, int quantity);

    void increaseQuantity(int qty);
    int getTotalPrice() const;
    void display() const;

    std::string getProductName() const;
    std::string getProductCategory() const;
};