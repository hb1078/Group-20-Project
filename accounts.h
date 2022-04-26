#pragma once

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


////////////////////////////////////////////////// FORMER ACCOUNTS.CPP STARTS HERE ////////////////////////////////////////////////////////////////////////////

void accounts::setFullName(string fullname)
{
    this->fullname = fullname;
}

void accounts::setPassword(string password)
{
    this->password = password;
}

void accounts::setShippingInfo(string shippingInfo)
{
    this->shippingInfo = shippingInfo;
}

void accounts::setPaymentInfo(string paymentInfo)
{
    this->paymentInfo = paymentInfo;
}

void accounts::getUserInfo()
{
    cout << "Full Name: " << fullname << endl;
    cout << "Password: " << password << endl;
    cout << "Shipping Info: " << shippingInfo << endl;
    cout << "Payment Info: " << paymentInfo << endl;
}

string accounts::getFullName()
{
    return fullname;
}

string accounts::getPassword()
{
    return password;
}

string accounts::getShippingInfo()
{
    return shippingInfo;
}

string accounts::getPaymentInfo()
{
    return paymentInfo;
}

//2 CART FUNCTIONS (clear/view) GO HERE, RECONSIDER IF THIS IS NEEDED IN ACCOUNTS.CPP OR NOT
