#pragma once 
//All functions of this this class, including constructors, have been tested and seem to work as expected

#include <string>
using std::string;

#ifndef BOOK_H
#define BOOK_H

class Book
{
private:
  string bookname;
  int quantity;
  double price;
public:
  //Constructors
  Book();
  Book(string bookname, int quantity, double price);

  // getters
  string getName();
  int getQuantity();
  double getPrice();

  //setters
  void setName(string bookname);
  void setQuantity(int quantity);
  void setPrice(double price);
  
}

void book::viewBook(){
    cout << " Name: " << bookname << endl << "Quantity: " << quantity << endl << "Price: $" << price << endl << endl;
}

void book::decreaseQuantity(int amount) //does as specified in the design document
{
    this->quantity-=quantity;
}