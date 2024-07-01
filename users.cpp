#include <iostream>
#include <fstream>
using namespace std;

class Payment{
    protected:
        string cardNumber, cardName, cardType;
        int cardYear, cardMonth, cardCvv;
        float amount;

    public:
        Payment(){
            cardNumber = "";
            cardName = "";
            cardType = "";
            cardYear = 0;
            cardMonth = 0;
            cardCvv = 0;
        }

        Payment(string cardNumber, string cardName, string cardType, int cardYear, int cardMonth, int CardCvv){
            this->cardNumber = cardNumber;
            this->cardName = cardName;
            this->cardType = cardType;
            this->cardYear = cardYear;
            this->cardMonth = cardMonth;
            this->cardCvv = cardCvv;
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
