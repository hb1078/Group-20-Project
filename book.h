#pragma once //All functions of this this class, including constructors, have been tested and seem to work as expected

#include <string>

using std::string;

class book
{
    private:
    string bookName;
    double price;
    int quantity;

    public:
    book() : bookName(""), price(0.0), quantity(0) {}
    book(string nameIn, double priceIn) : bookName(nameIn), price(priceIn), quantity(0) {}
    book(string nameIn, double priceIn, int quantityIn) : bookName(nameIn), price(priceIn), quantity(quantityIn) {}
    ~book();

    void setName(const string& nameIn); //string passed as const reference because it is a class
    void setPrice(double priceIn);
    void setQuantity(int quantityIn);

    const string getName(); //const better here because it doesn't modify values
    const double getPrice();
    const int getQuantity();

    bool decreaseQuantity(int amount); //decided this should be bool so it can fail if it causes quantity to be negative
};