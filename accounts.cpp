#include "accounts.h"
#include <iostream>

//using namespace std;

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