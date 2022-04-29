#include "cart.h> 
#include <iostream>
#include <string>


using namespace std;

void cart::setTotal(double totalIN)
{
    setTotal = setTotalIn;
}

void cart::getTotal(double TotalIN)
{
    getTotal = getTotalIn;
}

string cart::getUsername()
{
    return Username;
}

string cart::getBookName()
{
    return Bookname;
}

double cart::getBookPrice(double BookPrice2)
{
    getBookPrice = bookPrice2;
}

void cart::addBook(Book book) //going by design doc
{
;
}

void cart::removeBook()
{
    ;
}

void cart::viewCart()
{
return cart;
}

void cart::clearCart()
{;}

void cart::viewTotal()
{;}

void cart::checkout()
{
return checkout;
}

void cart::addHistory()
{;}

void cart::viewHistory()
{;}

void cart::deleteHistory()
{;}