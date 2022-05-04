#include "admin.h"

void admin::setAdminFullName(string admin_fullname)
{
    this->admin_fullname = admin_fullname;
}

void admin::setAdminPassword(string admin_password)
{
    this->admin_password = admin_password;
}

void admin::setAdminShipping(string admin_shipping)
{
    this->admin_shipping = admin_shipping;
}

void admin::setAdminPayment(string admin_payment)
{
    this->admin_payment = admin_payment;
}

void admin::getAdminInfo()
{
    cout << "Full Name: " << admin_fullname << endl;
    cout << "Password: " << admin_password << endl;
    cout << "Shipping Info: " << admin_shipping << endl;
    cout << "Payment Info: " << admin_payment << endl;
}

string admin::getAdminFullName()
{
    return admin_fullname;
}

string admin::getAdminPassword()
{
    return admin_password;
}

string admin::getAdminShipping()
{
    return admin_shipping;
}

string admin::getAdminPayment()
{
    return admin_payment;
}

