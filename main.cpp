#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <vector>

#include "accounts.h"


using namespace std;

int main()
{
    //variables for main's usage
    int user_input;

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

    }

    //account creation
    else if(user_input == 2)
    {
        cout << "--- User Account Creation --- " << endl;

        cout << "Please enter your first and last name: " << endl;
        getline(cin >> ws, fullnametemp);

        cout << "Please enter your password: " << endl;
        getline(cin, passwordtemp);

        cout << "Please enter your shipping address: " << endl;
        getline(cin, shippinginfotemp);

        cout << "Please enter your card number:" << endl;
        getline(cin, paymentinfotemp);


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
