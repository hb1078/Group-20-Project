#pragma once 
//All functions of this this class, including constructors, have been tested and seem to work as expected

#include <string>
#include <iostream>

using std::string;
using std::endl;
using std::cout;

class book
{
    public:
    string bookname;
    double price;
    int quantity;

    book() : bookname(""), price(0.0), quantity(0) {}
    book(string bookname, double price) : bookname(bookname), price(price), quantity(0) {}
    book(string bookname, double price, int quantity) : bookname(bookname), price(price), quantity(quantity) {}
    ~book();

    void setName(string booknameIn); 
    void setPrice(double priceIn);
    void setQuantity(int quantityIn);

    string getName(); 
    double getPrice();
    int getQuantity();
    void viewBook();

    bool decreaseQuantity(int amount); //bool type allows this to return false in case of failure
};

