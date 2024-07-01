#include <iostream>
#include <fstream>
#include "utils.cpp"
using namespace std;

class Payment{
    protected:
        string cardNumber, cardName, cardType;
        int cardYear, cardMonth, cardCvv;

    public:
        Payment(){
            cardNumber = "";
            cardName = "";
            cardType = "";
            cardYear = 0;
            cardMonth = 0;
            cardCvv = 0;
        }

        Payment(string cardNumber, string cardName, string cardType, int cardYear, int cardMonth, int cardCvv){
            this->cardNumber = cardNumber;
            this->cardName = cardName;
            this->cardType = cardType;
            this->cardYear = cardYear;
            this->cardMonth = cardMonth;
            this->cardCvv = cardCvv;
        }

        int makePayment(float amount){
            cout << "Your card is charged for amount Rs. " << amount << endl;
            cout << "Card Number: " << cardNumber << endl;
            cout << "Card Holder Name: " << cardName << endl;
            cout << "Card Type: " << cardType << endl;


            int month = getMonth();
            int year = getYear();

            if(cardYear < year || (cardYear == year && cardMonth < month)){
                return -1;
            }

            int cvv;
            cout << "Enter CVV: ";
            cin >> cvv;

            if(cvv != cardCvv){
                return -2;
            }

            return 0;
        }

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
