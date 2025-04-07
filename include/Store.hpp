#include <vector>
#include <include/Product.hpp>

class Store {
private:
    std::vector<Product> products;
    int wallet;

public:
    Store();

    void addProduct(const Product& product);
    void removeProduct(const std::string& name, const std::string& category, int qty);
    void showAllProducts() const;
    Product* findProduct(const std::string& name, const std::string& category);
    void injectCapital(int amount);
    int getWalletBalance() const;
    int getTotalInventoryValue() const;
};
