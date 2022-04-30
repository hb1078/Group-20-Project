//not complete only uploded for documentation purposes and help

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class cart
{
    private:
   // vector <Book> bookList;
    string userName;
    double totalprice;
   
    public:
    void setTotal(double total);
    double getTotal(double total);

    string getUsername(string username);
    string getBookname(string bookname);
    double getPrice(double Price);

    //adds and removes books
    void addBook(string Book);
    void removeBook(string Book);

    //Cart functions
    void viewCart();
    void clearCart();
    void viewTotal();
    void checkout();
    void addHistory();
    void deleteHistory();

};
