#include "cart.h> 
#include <iostream>

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

void cart::removeBook(Book book)
{
    ;
}

void