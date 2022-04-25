#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h> //not sure what stdio is doing. This is the equivalent to iostream, but it is a C library. Didn't want to delete in case there was a reason for it that I don't see
#include <vector>

#include "accounts.h"


using namespace std;

int main()
{
    //variables for main's usage
    int user_input;
    int login_option;

    string line;
    string fullnametemp;
    string passwordtemp;
    string shippinginfotemp;
    string paymentinfotemp;

    string accountsfile;
    string itemsfile;

    vector<accounts> account_vector;
    //vector<items> item_vector; MUST BE ADDED EVENTUALLY


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
        getline(cin >> ws, fullnametemp);

        for(int i = 0; i < account_vector.size(); i++) {          
                  //THIS IS GOING TO BE A MASSIVE FOR-LOOP (it'll be the entire login menu)
            if(fullnametemp == account_vector[i].getFullName()) {

                cout << "Please enter your password: ";
                getline(cin, passwordtemp);

                if(passwordtemp == account_vector[i].getPassword()) {

                    cout << "Welcome " << fullnametemp << "!" << endl;
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
        getline(cin >> ws, fullnametemp);

        cout << "Please enter your password: " << endl;
        getline(cin, passwordtemp);

        cout << "Please enter your shipping address: " << endl;
        getline(cin, shippinginfotemp);

        cout << "Please enter your card number:" << endl;
        getline(cin, paymentinfotemp);

        accounts newaccount(fullnametemp, passwordtemp, shippinginfotemp, paymentinfotemp);
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
