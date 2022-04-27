//not complete only uploded for documentation purposes and help
#pragma once

#include <string>
#include <iostream>
#include <vector>

using std::string;

class cart
{
    private:

    string userName;
    double totalprice;
   // vector <books> books; /// not sure what to put here



    public:
    void setTotal(double total);
    double getTotal();

    string getUsername(string username);
    string getBookname(string bookname);

    //adds and removes books
    void addBook(string Book);
    void removeBook(string Book);


    //cart functions from line 27-32
    void viewCart();
    void clearCart();
    void viewTotal();
    void checkout();
    void addHistory();
    void deleteHistory();


   // void cart::addBook(string getBookname)
   //     {
    //        for (int i=0; //add function here ; i++)
        //        {
      //              if 
      //          }
     //   };

   // void cart::removeBook(string getBookname)
     //   {
      //      for (int i=0; //add function here ; i++)
      //          {
      //              if 
      //          }
      //  };

};
