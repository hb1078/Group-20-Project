#pragma once

#include<string>
#include<iostream>

using namespace std;

class admin
{
private:
    string admin_fullname;
    string admin_password;
    string admin_shipping;
    string admin_payment;

    //cart userCart; MUST BE ADDED LATER

public:
    void setAdminFullName(string admin_fullname);
    void setAdminPassword(string admin_password);
    void setAdminShipping(string admin_shipping);
    void setAdminPayment(string admin_payment);

    string getAdminFullName();
    string getAdminPassword();
    string getAdminShipping();
    string getAdminPayment();
    void getAdminInfo();

    void viewCart();
    void clearCart();
    

    admin(string admin_fullname, string admin_password, string admin_shipping, string admin_payment) :
        admin_fullname(admin_fullname), admin_password(admin_password), admin_shipping(admin_shipping), admin_payment(admin_payment)
    {};

    //blank account
    admin() : admin_fullname(""), admin_password(""), admin_shipping(""), admin_payment("")
    {};
};
