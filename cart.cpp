#include "cart.h"

void cart::setTotal(double totalIn)
{
    totalPrice = totalIn;
}

double cart::getTotal()
{
    return totalPrice;
}

string cart::getUsername()
{
    return userName;
}

/*string cart::getBookName()
{
    return Bookname;
}

double cart::getPrice(double BookPrice2)
{
    getBookPrice = bookPrice2;
}*/

void cart::addBook(const book& bookIn) //going by design doc
{
    bookList.push_back(bookIn);
}

bool cart::removeBook(const book& bookIn)
{
    for(vector<book>::iterator it = bookList.begin(); it != bookList.end(); it++) //iterates through the whole vector trying to find the specified book
    { //an iterator is preferable to a standard for loop here because it allows me to use erase()
        if ((*it).getName() == bookIn.getName()) //checks to see if the specific book matches the one in the vector
        {
            bookList.erase(it); //removes the book
            return true; //returns success
        }
    }

    return false; //returns failure if nothing is found
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