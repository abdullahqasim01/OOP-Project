#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
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
    
    public:
        User(string username, string password){
            this->username = username;
            this->password = password;
        }
};

class Customer : private User {
    protected:
        int id;
        string cnic, mobileNumber, drivingLincese;
        bool bikeLincese, carLincese;
        Payment* payment;

};

class Admin: private User{

    public:
        int addVehicle(){
            string brand, model, id,  fuelType;
            int power,  year, noOfPassengers;
            float milage,  rentPerDay;
            bool available;

            cout << "Enter Brand: ";
            getline(cin, brand);
            cin.ignore();
            cout << "Enter Model: ";
            getline(cin, model);
            cin.ignore();
            cout << "Enter ID: ";
            getline(cin, id);
            cin.ignore();
            cout << "Enter Fuel Type: ";
            getline(cin, fuelType);
            cin.ignore();
            cout << "Enter Power: ";
            cin >> power;
            cout << "Enter Year: ";
            cin >> year;
            cout << "Enter Number of Passengers: ";
            cin >> noOfPassengers;
            cout << "Enter Milage: ";
            cin >> milage;
            cout << "Enter Rent Per Day: ";
            cin >> rentPerDay;
            available = true;

            ofstream file;
            file.open("vehicles.txt", ios::app);
            file << brand << "," << model << "," << id << "," << fuelType << "," << power << "," << year << "," << noOfPassengers << "," << milage << "," << rentPerDay << "," << available << endl;
            file.close();

            return 0;
        }

};
