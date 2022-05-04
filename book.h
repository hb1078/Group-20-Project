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


book::~book()
{
    bookname = ""; //I have decided to not use this pointers, as they are redundant as long as variable names are unique
    price = 0.0;
    quantity = 0;
}

void book::setName(string bookname) //all of my parameters are "somethingIn" or "somethingOut" to prevent accidental creation of duplicate variable names
{
    this->bookname = bookname;
}

void book::setPrice(double price)
{
    this->price = price;
}

void book::setQuantity(int quantity)
{
    this->quantity = quantity;
}

string book::getName()
{
    return bookname;
}

double book::getPrice()
{
    return price;
}

int book::getQuantity()
{
    return quantity;
}

void book::viewBook(){
    cout << " Name: " << bookname << endl << "Quantity: " << quantity << endl << "Price: $" << price << endl << endl;
}

void book::decreaseQuantity(int amount) //does as specified in the design document
{
    this->quantity-=quantity;
}