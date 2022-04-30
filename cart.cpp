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

void cart::addBook(book bookIn) //going by design doc
{
    bookList.push_back(bookIn);
    totalPrice += (bookIn.getPrice() * bookIn.getQuantity()); //updates total price to include new book and quantity
}

bool cart::removeBook(book bookIn)
{
    for(vector<book>::iterator it = bookList.begin(); it != bookList.end(); it++) //iterates through the whole vector trying to find the specified book
    { //an iterator is preferable to a standard for loop here because it allows me to use erase()
        if ((*it).getName() == bookIn.getName()) //checks to see if the specific book matches the one in the vector
        {
            totalPrice -= ((*it).getPrice() * (*it).getQuantity()); //reduces total price by price of book removed
            bookList.erase(it); //removes the book
            return true; //returns success
        }
    }

    return false; //returns failure if nothing is found
}

void cart::viewCart()
{
    cout << "Cart contains: " << endl;
    for (int i = 0; i < bookList.size(); i++)
        cout << endl << bookList[i].getName() << ":" << endl << "Price: " << bookList[i].getPrice() << endl << "Quantity: " << bookList[i].getQuantity() << endl;
}

void cart::clearCart()
{
    bookList.clear(); //empties book vector
    totalPrice = 0.0; //drops price to 0
}

void cart::viewTotal()
{
    cout << totalPrice << endl;
}

void cart::checkout()
{
    return;
}

void cart::addHistory()
{;}

void cart::viewHistory()
{;}

void cart::deleteHistory()
{;}