#include "book.h" //this comment is testing if I have this branch set up correctly

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

bool book::getName(string& nameOut)
{
    if (bookName == "") //all my getters follow the same format
        return false; //that format being a check for an empty variable leading to a false return if the variable is indeed empty
    
    else //followed by an else that does the actual "getting" and returns true, as long as the variable is storing an actual name/price/quantity
    {
        nameOut = bookName;
        return true;
    }
}

bool book::getPrice(double& priceOut)
{
    if (price == 0.0)
        return false;
    
    else
    {
        priceOut = price;
        return true;
    }
}

bool book::getQuantity(int& quantityOut)
{
    if (quantity == 0)
        return false;
    
    else
    {
        quantityOut = quantity;
        return true;
    }
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