using namespace std;

class Product
{
private:
    string category;
    string name;
    int price;
    int stock;

public:
    Product(const string &category, const string &name, int price, int stock);
    void increaseStock(int qty);
    void decreaseStock(int qty);
    void display() const;

    string getCategory() const;
    string getName() const;
    int getPrice() const;
    int getStock() const;

    void setPrice(int newPrice);
};