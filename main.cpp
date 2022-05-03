#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include "book.h"
#include "accounts.h"
#include "cart.h"

//#include "accounts.cpp"
//#include "cart.h"
//#include "inventory.h"

using std::cin;
using std::getline;
using std::ws;

int main()
{
    //variables for main's usage
    int user_input;
    int login_option;
    int account_option;
    int shop_option;
    int cart_size;
    int looper = 1;
    int quantity = 10;
    double price = 15.99;

    string line;
    string fullname;
    string password;
    string shippinginfo;
    string paymentinfo;

    string temppass;
    string tempshippinginfo;
    string temppaymentinfo;

    string accountsfile;
    string booksfile;

    vector<accounts> account_vector;
    vector<book> books_vector;
    cart carts;


    fstream file1;
    fstream file2;

    accountsfile = "accounts.txt";
    booksfile = "books.txt";

    file1.open(accountsfile);

    //reads in account information from accounts.txt
    if(file1.is_open()){
        while(getline(file1, line)){
            accounts fileaccount;
            fileaccount.accounts::setFullName(line);

            getline(file1, line);
            fileaccount.accounts::setPassword(line);

            getline(file1, line);
            fileaccount.accounts::setShippingInfo(line);

            getline(file1, line);
            fileaccount.accounts::setPaymentInfo(line);

            account_vector.push_back(fileaccount);
        }

        file1.close();

    }
    else{
        cout << "Error opening file" << endl;
    }

    file2.open(booksfile);
    if(file2.is_open()){
        while(getline(file2, line)){
            book filebook;
            filebook.book::setName(line);

            getline(file2, line);
            filebook.book::setQuantity(quantity);

            getline(file2, line);
            filebook.book::setPrice(price);

            books_vector.push_back(filebook);
            
        }
        file2.close();
    }
    else{
        cout << "Error opening file" << endl;
    }

    //main menu

    while(1)
    {
    
    beginningmenu:
    
    cout << "Welcome to the Group 20 Bookstore!" << endl;
    cout << "Please select from the following options:" << endl << endl;

    cout << "1. Login" << endl;
    cout << "2. Create Account" << endl;
    cout << "3. Exit Program" << endl;

    //sub menus depending on user input
    cin >> user_input;


    //acc login (must have created account OR already have one in the .txt file)
    if(user_input == 1) 
    {
        system("clear");
        cout << "---User Login---" << endl << endl;
        cout << "Please enter the name you registered with: ";
        getline(cin >> ws, fullname);

        for(int i = 0; i < account_vector.size(); i++) {      //THIS IS GOING TO BE A MASSIVE FOR-LOOP (it'll be the entire login menu)
        
            if(fullname == account_vector[i].getFullName()) {

                system("clear");
                cout << "Please enter your password: ";
                getline(cin, password);

                if(password == account_vector[i].getPassword()) {
                    carts.setName(fullname);
                    
                    system("clear");
                    loginmenu:

                    

                    cout << "Welcome " << fullname << "!" << endl;
                    cout << "Please select from the following options:" << endl << endl;

                    cout << "1. View Shop" << endl;
                    cout << "2. View Cart" << endl;
                    cout << "3. View Account" << endl;
                    cout << "4. Logout" << endl;

                    while(looper == 1){
                    cin >> login_option;
                        
                        if(login_option == 1){
                          //TAKE USER TO SHOP SUBMENU

                            system("clear");
                            shopmenu:

                            while(1){
                            
                            int book_option;
                            int book_quantity;
                            
                            cout << "---BOOK SHOP CATALOG ---" << endl << endl;

                            for (int i = 0; i < books_vector.size(); i++){
                                cout << i + 1 << ". ";
                                books_vector[i].viewBook();
                            }

                            //SHOP MENU OPTIONS
                            cout << "1. Add book to cart." << endl;
                            cout << "2. Go back to login menu." << endl;
                            
                            cin >> shop_option;

                            if(shop_option == 1) {
                                bookoptionmenu:
                                cout << "Please select the number of the book that you want: ";
                                cin >> book_option;

                                if(book_option > 0 && book_option<= books_vector.size()) {
                                    cout << "You chose: " << books_vector[book_option-1].getName() << endl;
                                    cout << "Please enter how many of these books you'd like: ";

                                    cin >> book_quantity;

                                    while(1) {
                                        if(book_quantity > books_vector[book_option-1].getQuantity()){
                                            cout << endl << "Sorry, we don't have that many  of that book for sale, please try again: ";
                                            cin >> book_quantity;
                                        }
                                        else{
                                            break;
                                        }
                                    }
                                    book book_to_cart;
                                    book_to_cart.setName(books_vector[book_option-1].getName());
                                    book_to_cart.setQuantity(book_quantity);
                                    book_to_cart.setPrice(books_vector[book_option-1].getPrice());

                                    carts.addBook(book_to_cart);
                                    cart_size = cart_size + 1;

                                    cout << "Book was added to cart!" << endl;
                                    goto shopmenu;
                                }
                                else{
                                    cout << "You entered an invalid input. Either that isn't a valid number, or not a number. " << endl;
                                    goto bookoptionmenu;
                                }
                            }

                            else if(shop_option == 2){
                                system("clear");
                                goto loginmenu;
                            }
                        }
                    }

                        else if(login_option == 2){
                          //TAKE USER TO THEIR CART

                            cartmenu:

                            while(1){
                                int cart_option;
                                cout << "---USER CART---" << endl << endl;
                                carts.viewCart();
                                cout << "1. Checkout all items" << endl;
                                cout << "2. Remove item from cart" << endl;
                                cout << "3. Go back to login menu" << endl;
                                cin >> cart_option;

                                if (cart_option == 1){
                                    //CHECKOUT
                                    for(int loop1 = 0; loop1 < cart_size; loop1++) {
                                        for(int loop2 = 0; loop2 < books_vector.size(); loop2++) {
                                            if(carts.getBookname(loop1) == books_vector[loop2].getName()){
                                                books_vector[loop2].decreaseQuantity(carts.getBookquantity(loop1));
                                        }

                                    }
                                }
                                    carts.checkout();
                                    cart_size = 0;
                                    system("clear");
                                    cout << "Checkout was successful!" << endl << endl;
                                    goto loginmenu;
                            }

                                else if(cart_option == 2){
                                    //REMOVE BOOK FROM CART
                                    
                                    int book_to_remove;
                                    cout << "Please enter the number of the book you'd like to remove: ";
                                    cin >> book_to_remove;
                                    carts.removeBook(book_to_remove);
                                    cart_size = cart_size - 1;

                                    system("clear");
                                    cout << "Book was removed from cart!" << endl;
                                    goto cartmenu;
                                    
                                }
                                else if (cart_option == 3){
                                    //goes back to login menu.
                                    system("clear");
                                    goto loginmenu;
                                }
                                else{
                                    cout << "Invalid input, please try again." << endl;
                                    goto cartmenu;
                                }
                            }
                        }

                        else if(login_option == 3){
                            //TAKE USER TO ACCOUNT OPTIONS

                            system("clear");
                            while(1){
                            cout << "---ACCOUNT MENU---" << endl << endl;
                            cout << "1. View Account Information" << endl;
                            cout << "2. Change Password" << endl;
                            cout << "3. Change Shipping Information" << endl;
                            cout << "4. Change Payment Information" << endl;
                            cout << "5. Delete Account" << endl;
                            cout << "6. View Order History" << endl;
                            cout << "7. Leave Account Menu" << endl;
                            cout << "8. Delete Order History" << endl;

                            cin >> account_option;

                            //gets user info
                            if(account_option == 1){
                                system("clear");
                                account_vector[i].getUserInfo();
                            }

                            //password change
                            else if(account_option == 2){
                                cout << endl << "Please enter your new password: " << endl;
                                getline(cin >> ws, temppass);
                                account_vector[i].setPassword(temppass);
                                cout << endl << endl << "Your password has been changed." << endl << endl;
                            }

                            //shipping info change
                            else if(account_option == 3){
                                cout << "Please enter your new shipping address: " << endl;
                                getline(cin >> ws, tempshippinginfo);
                                account_vector[i].setShippingInfo(tempshippinginfo);
                                cout << endl << endl << "Your shipping information has been changed." << endl << endl;
                                }

                            //payment info change
                            else if(account_option == 4){
                                cout << "Please enter your new payment information: " << endl;
                                getline(cin >> ws, temppaymentinfo);
                                account_vector[i].setPaymentInfo(temppaymentinfo);
                                cout << endl << endl << "Your payment information has been changed." << endl << endl;
                            }
                                
                            //account erasure 
                            else if(account_option == 5){
                                account_vector.erase(account_vector.begin()+i);
                                cout << endl << endl << "Your account has been erased." << endl << endl;
                                goto beginningmenu;

                            }

                            //view acc history
                            else if(account_option == 6){
                                system("clear");
                                carts.viewHistory();
                                
                            }

                            //go back
                            else if(account_option == 7){
                                goto loginmenu;
                            
                            }

                            //delete order history
                            else if(account_option == 8){
                                system("clear");
                                carts.deleteHistory();
                            }
                            
                            else{
                                cout << "Invalid input. Please try again." << endl << endl;
                            }
                        
                        }
                        }   
                          
                        
                        else if(login_option == 4){
                          //LOG USER OUT
                          cout << "Logging out..." << endl << endl;
                          carts.clearCart();
                          goto beginningmenu;
                        }
                        else{
                          cout << "Invalid input! Please enter a valid one." << endl << endl;
                        }
                          }
                }
                else{
                  cout << "Incorrect password!" << endl << endl << endl;
                  break;
                }
                  
            }
            else{
                system("clear");
              cout << "Not a registered name. Try making an account first! (or typing correctly)" << endl << endl;
            }
        }
    }

    //account creation
    else if(user_input == 2)
    {
        system("clear");
        cout << "--- User Account Creation --- " << endl << endl;

        cout << "Please enter your first and last name: " << endl;
        getline(cin >> ws, fullname);

        cout << "Please enter your password: " << endl;
        getline(cin, password);

        cout << "Please enter your shipping address: " << endl;
        getline(cin, shippinginfo);

        cout << "Please enter your card number:" << endl;
        getline(cin, paymentinfo);

        accounts newaccount(fullname, password, shippinginfo, paymentinfo);
        account_vector.push_back(newaccount);

        cout << "Account created successfully!" << endl << "Please wait..." << endl << endl;
 

    }

    //exits program
    else if(user_input == 3)
    {
        cout << "Exiting program... Goodbye!" << endl << endl;

                    //write to accounts.txt
        ofstream accounts_file_write;
        accounts_file_write.open("accounts.txt");
        for(int i = 0; i < account_vector.size(); i++) {
            accounts_file_write << account_vector[i].getFullName() << endl;
            accounts_file_write << account_vector[i].getPassword() << endl;
            accounts_file_write << account_vector[i].getShippingInfo() << endl;
            accounts_file_write << account_vector[i].getPaymentInfo() << endl;
            }
            accounts_file_write.close();
            
        exit(1);
    }
    
    else
    {
        cout << "Invalid input. Please try again." << endl << endl << endl;
        goto beginningmenu;
    }

    }

}
