#include "book.h"

book::~book()
{
    bookName = ""; //I have decided to not use this pointers, as they are redundant as long as variable names are unique
    price = 0.0;
    quantity = 0;
}

void book::setName(const string& nameIn) //all of my parameters are "somethingIn" or "somethingOut" to prevent accidental creation of duplicate variable names
{
    bookName = nameIn;
}

void book::setPrice(double priceIn)
{
    price = priceIn;
}

void book::setQuantity(int quantityIn)
{
    quantity = quantityIn;
}

const string book::getName()
{
    return bookName;
}

const double book::getPrice()
{
    return price;
}

const int book::getQuantity()
{
    return quantity;
}

bool book::decreaseQuantity(int amount) //does as specified in the design document
{
    int difference = quantity - amount; //this variable exists so the program doesn't have to do this subtraction twice
    //this improves time complexity at the cost of using an extra variable

    if (difference < 0) //checks for a negative value, which would be an invalid value for a quantity
        return false; //returns false, not allowing the decrease to occur
    
    else
    {
        quantity = difference; //sets the quantity to the new, decreased value as long as it is a valid quantity
        return true;
    }
}