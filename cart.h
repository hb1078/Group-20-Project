//not complete only uploded for documentation purposes and help

#include <string>
#include <iostream>
#include <vector>
#include "book.h"

using namespace std;

class cart
{
    private:
    vector <book> bookList;
    string userName;
    double totalPrice;
   
    public:
    void setTotal(double totalIn);
    double getTotal();

    string getUsername();
    //string getBookname(string bookname); not sure how to specificy which book to get so this is commented out for now
    //double getPrice(double Price); ^^^^^

    //adds and removes books
    void addBook(book bookIn);
    bool removeBook(book bookIn); //needs to be bool in case it fails

    //Cart functions
    void viewCart();
    void clearCart();
    void viewTotal();
    void checkout();
    void addHistory();
    void viewHistory();
    void deleteHistory();

};
