#pragma once

#include <iostream>
#include <string>

using namespace std;

class accounts
{
    private:
    string fullname;
    string password;
    string shippingInfo;
    string paymentInfo;

    //cart userCart; MUST BE ADDED LATER

    public:
    void setFullName(string fullname);
    void setPassword(string password);
    void setShippingInfo(string shippingInfo);
    void setPaymentInfo(string paymentInfo);

    string getFullName();
    string getPassword();
    string getShippingInfo();
    string getPaymentInfo();
    void getUserInfo();

    void viewCart();
    void clearCart();

    //creates an account with information
    accounts(string fullname, string password, string shippingInfo, string paymentInfo) :
    fullname(fullname), password(password), shippingInfo(shippingInfo), paymentInfo(paymentInfo)
    {};

    //blank account
    accounts() : fullname(""), password(""), shippingInfo(""), paymentInfo("")
    {};

};