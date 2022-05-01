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

    void setName(string bookname); 
    void setPrice(double price);
    void setQuantity(int quantity);

    string getName(); 
    double getPrice();
    int getQuantity();
    void viewBook();

    void decreaseQuantity(int amount);
};

