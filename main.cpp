#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "accounts.h"
//#include "accounts.cpp"


using namespace std;

int main()
{
    //variables for main's usage
    int user_input;
    int login_option;

    string line;
    string fullname;
    string password;
    string shippinginfo;
    string paymentinfo;

    string accountsfile;
    string itemsfile;

    vector<accounts> account_vector;
    //vector<books> books_vector; MUST BE ADDED EVENTUALLY


    fstream file1;
    fstream file2;

    accountsfile = "accounts.txt";
    itemsfile = "items.txt";

    file1.open(accountsfile);

    //reads in account information from accounts.txt
    if(file1.is_open()){
        while(getline(file1, line)){
            accounts fileaccount;
            fileaccount.setFullName(line);

            getline(file1, line);
            fileaccount.setPassword(line);

            getline(file1, line);
            fileaccount.setShippingInfo(line);

            getline(file1, line);
            fileaccount.setPaymentInfo(line);

            account_vector.push_back(fileaccount);
        }

        file1.close();

    }
    else{
        cout << "Error opening file" << endl;
    }

    //main menu
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
        cout << "---User Login---" << endl << endl;
        cout << "Please enter the name you registered with: ";
        getline(cin >> ws, fullname);

        for(int i = 0; i < account_vector.size(); i++) {          
                  //THIS IS GOING TO BE A MASSIVE FOR-LOOP (it'll be the entire login menu)
            if(fullname == account_vector[i].getFullName()) {

                cout << "Please enter your password: ";
                getline(cin, password);

                if(password == account_vector[i].getPassword()) {

                    cout << "Welcome " << fullname << "!" << endl;
                    cout << "Please select from the following options:" << endl << endl;

                    cout << "1. View Shop" << endl;
                    cout << "2. View Cart" << endl;
                    cout << "3. View Account" << endl;
                    cout << "4. Logout" << endl;

                    cin >> login_option;
                }
            }
        }
    }

    //account creation
    else if(user_input == 2)
    {
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

        cout << "Account created successfully!" << endl;

    }

    //exits program
    else if(user_input == 3)
    {
        cout << "Exiting program..." << endl;
        exit(1);
    }
    
    else
    {
        cout << "Invalid input. Please try again." << endl;
        //main();
    }
}
