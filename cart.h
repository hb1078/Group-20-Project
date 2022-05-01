//not complete only uploded for documentation purposes and help

#include <string>
#include <iostream>
#include <vector>
#include <fstream>

#include "book.h"

using namespace std;

class cart : public book
{
    private:
    string fullname;
    double totalprice;
    double price;
    vector<book> books_vector;
   
    public:
    void setTotal(double total);
    double getTotal();

    string getFullname();
    string getBookname(int bookret);
    int getBookquantity(int quantity);
    double getBookprice(double price);

    //adds and removes books
    void addBook(book bookobject);
    void removeBook(int booknum);

    //Cart functions
    void viewCart();
    void clearCart();
    void viewTotal();
    void checkout();
    void addHistory();
    void viewHistory();
    void deleteHistory();

};