#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
    //variables for main's usage
    int user_input;

    string line;
    string accountsfile;
    string itemsfile;

    fstream file1;
    fstream file2;

    accountsfile = "accounts.txt";
    itemsfile = "items.txt";


    //main menu
    cout << "Welcome to the Group 20 Bookstore!" << endl;
    cout << "Please select from the following options:" << endl << endl;

    cout << "1. Login" << endl;
    cout << "2. Create Account" << endl;
    cout << "3. Exit Program" << endl;

    //sub menus depending on user input
    cin >> user_input;

    //acc login (must have account)
    if(user_input == 1)
    {

    }

    //account creation
    else if(user_input == 2)
    {
        cout << "User Account Creation: " << endl;
        cout << "Please enter your first and last name: " << endl;

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
