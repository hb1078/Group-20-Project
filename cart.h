//not complete only uploded for documentation purposes and help

#include <string>
#include <iostream>
#include <vector>

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

void cart::setTotal(double totalprice)
{
    this->totalprice = totalprice;
}

double cart::getTotal()
{
    return totalprice;
}

string cart::getFullname()
{
    return fullname;
}

string cart::getBookname(int bookret)
{
    return bookname;
}

double cart::getBookprice(double price)
{
    return price;
}

int cart::getBookquantity(int quantity){
    return books_vector[quantity].getQuantity();
}

void cart::addBook(book bookobject) //going by design doc
{
    books_vector.push_back(bookobject);
}

void cart::removeBook(int booknum)
{
    books_vector.erase(books_vector.begin() + booknum - 1);
}

void cart::viewCart()
{
    for (int i = 0; i < books_vector.size(); i++){
        cout << i + 1 << ".";
        cout << "Name: " << books_vector[i].getName() << endl;
        cout << "Quantity: " << books_vector[i].getQuantity() << endl;
        cout << "Price: $" << books_vector[i].getPrice() << endl;
    }

    viewTotal();
}

void cart::clearCart(){
    if(books_vector.size() > 0){
        books_vector.clear();
    }
}

void cart::viewTotal(){
    totalprice = 0;

    for(int i = 0; i < books_vector.size(); i++){
        totalprice = totalprice + books_vector[i].getQuantity() * books_vector[i].getPrice();
    }

    cout << "Your total is: " << totalprice << endl;
}

void cart::checkout()
{
    addHistory();

    for(int i = 0; i < books_vector.size(); i++) {
        books_vector.pop_back();
    }
}

void cart::addHistory() {
    ofstream addhistoryfile;
    string account = getFullname();

    addhistoryfile.open(account + " history.txt", ofstream::out | ofstream::app);

    addhistoryfile << endl << "---HISTORY---" << endl;

    for (int i = 0; i < books_vector.size(); i++) {
        addhistoryfile << i + 1 << ".";
        addhistoryfile << "Name: " << books_vector[i].getName() << endl;
        addhistoryfile << "Quantity: " << books_vector[i].getQuantity() << endl;
        addhistoryfile << "Price: $" << books_vector[i].getPrice() << endl << endl;
    }

    //NOT SURE IF THIS GETS THE ACTUAL TOTAL PRICE, TEST THAT EVENTUALLY
    addhistoryfile << "The total for that order was: " << totalprice << endl;

    addhistoryfile.close();
}

void cart::viewHistory() {
    fstream viewhistoryfile;
    string account = getFullname();
    string holder;

    viewhistoryfile.open(account + " history.txt", ofstream::in);

    cout << "---HISTORY OF " << account << "---" << endl;

    if(viewhistoryfile.is_open()) {
        while(getline(viewhistoryfile, holder)){
            cout << holder << endl;
        }
    }
    cout << endl;
    viewhistoryfile.close();
}

void cart::deleteHistory() {
    string account = getFullname();

    account = account + " history.txt";
    remove(account.c_str());
    
}