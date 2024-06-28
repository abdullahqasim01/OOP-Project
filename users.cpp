#include <iostream>
using namespace std;

class Payment{
    protected:
        string cardNumber, cardName, cardType;
        int cardYear, cardMonth, cardCvv;
};

class User{
    protected:
        string username, password;

};

class Customer : private User {
    protected:
        int id;
        string cnic, mobileNumber, drivingLincese;
        bool bikeLincese, carLincese;
};

class Admin: private User{

};
