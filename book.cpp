#include "book.h"

book::~book()
{
    bookname = ""; //I have decided to not use this pointers, as they are redundant as long as variable names are unique
    price = 0.0;
    quantity = 0;
}

void book::setName(string booknameIn) //all of my parameters are "somethingIn" or "somethingOut" to prevent accidental creation of duplicate variable names
{
    bookname = booknameIn; //specifying the variable as booknameIn rather than bookname makes this-> pointer unnecessary
}

void book::setPrice(double priceIn)
{
    price = priceIn;
}

void book::setQuantity(int quantityIn)
{
    quantity = quantityIn;
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
    cout << " Name: " << bookname << endl << "Quantity: " << quantity << endl << "Price: " << price << endl << endl;
}

bool book::decreaseQuantity(int amount) //does as specified in the design document
{
    int difference = quantity - amount; //this reduces time complexity by only doing the quantity - amount subtraction once

    if (difference < 0) //returns failure if the difference is negative
        return false;
    
    else
    {
        quantity = difference; //sets quantity to the difference as long as it is 0 or positive
        return true;
    }
}