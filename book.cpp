#include "book.h"

Book::Book()
{
  bookname = "";
  quantity = 0;
  price = 0;
}

Book::Book(string bookname, int quantity, double price)
{
  this->bookname = bookname;
  this->quantity = quantity;
  this->price = price;
}

//getters
string Book::getName()
{
  return bookname;
}

int Book::getQuantity()
{
  return quantity;
}

double Book::getPrice()
{
  return price;
}

//Setters
void Book::setName(string bookname)
{
  this->bookname = bookname;
}

void Book::setQuantity(int quantity)
{
  this->quantity = quantity;
}

void Book::setPrice(double price)
{
  this->price = price;
}

bool Book::decreaseQuantity(int amount)
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
