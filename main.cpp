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

using namespace std;

int main()
{
    //variables for main's usage
    int user_input;
    int login_option;
    int account_option;
    int looper = 1;

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
    //vector<books> books_vector; MUST BE ADDED EVENTUALLY


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

                    loginmenu:

                    cout << "Welcome " << fullname << "!" << endl;
                    cout << "Please select from the following options:" << endl << endl;

                    cout << "1. View Shop" << endl;
                    cout << "2. View Cart" << endl;
                    cout << "3. View Account" << endl;
                    cout << "4. Logout" << endl;

                    while(looper == 1){
                    cin >> login_option;
                    //system("clear");
                        
                        if(login_option == 1){
                          //TAKE USER TO SHOP SUBMENU
                        }

                        else if(login_option == 2){
                          //TAKE USER TO THEIR CART
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
                                //view history somehow
                                
                            }

                            //go back
                            else if(account_option == 7){
                                goto loginmenu;
                            
                            }
                            }
                        }   
                          
                        
                        else if(login_option == 4){
                          //LOG USER OUT
                          cout << "Logging out..." << endl << endl;
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
