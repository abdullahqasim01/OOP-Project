#ifndef USERS_H
#define USERS_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "vehicles.h"
#include "utils.h"
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
        string username, password, role;
    
    public:
        User(string username, string password, string role){
            this->username = username;
            this->password = password;
            this->role = role;
        }

        int login(){
            ifstream file;
            if (role == "Customer"){
                file.open("customers.txt");
            }
            else if(role == "Admin"){
                file.open("admins.txt");
            }
            string u, p;
            string line;
            while(getline(file, line)){
                stringstream ss(line);
                getline(ss, u, ',');
                getline(ss, p, ',');
                if(u == username && p == password){
                    return 0;
                }
                else if(u == username && p != password){
                    return -1;
                }
            }
            return -2;
        }

        int register_(){
            ofstream file;
            file.open("admins.txt", ios::app);
            file << username << "," << password << endl;
            file.close();
            return 0;
        }

        int register_(string cnic, string mobileNumber, string drivingLincese, bool bikeLincese, bool carLincese){
            if (role != "Customer"){
                return -1;
            }
            string bikeLinceseT = "0";
            string carLinceseT = "0";
            if (bikeLincese){
                bikeLinceseT = "1";
            }
            if (carLincese){
                carLinceseT = "1";
            }
            ofstream file;
            file.open("customers.txt", ios::app);
            file << username << "," << password << "," << cnic << "," << mobileNumber << "," << drivingLincese << "," << bikeLinceseT << "," << carLinceseT << endl;
            file.close();
            return 0;
        
        }
};

class Customer : public User {
    protected:
        string cnic, mobileNumber, drivingLincese;
        bool bikeLincese, carLincese;
        Payment* payment;

    public:
        Customer(string username, string password): User(username, password, "Customer"){
            this->cnic = "";
            this->mobileNumber = "";
            this->drivingLincese = "";
            this->bikeLincese = false;
            this->carLincese = false;
        }

        Customer(string username, string password, string cnic, string mobileNumber, string drivingLincese, bool bikeLincese, bool carLincese): User(username, password, "Customer"){
            this->cnic = cnic;
            this->mobileNumber = mobileNumber;
            this->drivingLincese = drivingLincese;
            this->bikeLincese = bikeLincese;
            this->carLincese = carLincese;
        }

        void load_data(){
            ifstream file("customers.txt");
            string line;
            while(getline(file, line)){
                stringstream ss(line);
                string u, p;
                getline(ss, u, ',');
                getline(ss, p, ',');
                string temp;
                if(u == username){
                    getline(ss, cnic, ',');
                    getline(ss, mobileNumber, ',');
                    getline(ss, drivingLincese, ',');
                    getline(ss, temp, ',');
                    if(temp == "1"){
                        bikeLincese = true;
                    }else{
                        bikeLincese = false;
                    }
                    getline(ss, temp, ',');
                    if(temp == "1"){
                        carLincese = true;
                    }else{
                        carLincese = false;
                    }
                    break;
                }
            }
            file.close();
        
        }

};

class Admin: public User{

    public:

        Admin(string username, string password): User(username, password, "Admin"){
        }

        Vehicle* addVehicle(){
            string brand, model, id, type, fuelType;
            int power,  year, noOfPassengers, loadCapacity, milage,  rentPerDay;
            bool available;
            
            cin.ignore();
            cout << "Enter Brand: ";
            getline(cin, brand);
            cout << "Enter Model: ";
            getline(cin, model);
            cout << "Enter Type: ";
            getline(cin, type);
            cout << "Enter ID: ";
            getline(cin, id);
            cout << "Enter Fuel Type: ";
            getline(cin, fuelType);
            cout << "Enter Power: ";
            cin >> power;
            cout << "Enter Year: ";
            cin >> year;
            cout << "Enter Number of Passengers: ";
            cin >> noOfPassengers;
            cout << "Enter Load Capacity: ";
            cin >> loadCapacity;
            cout << "Enter Milage: ";
            cin >> milage;
            cout << "Enter Rent Per Day: ";
            cin >> rentPerDay;
            available = true;

            Vehicle* vehicle = new Vehicle(brand, model, id, fuelType, power, year, noOfPassengers, loadCapacity, milage, rentPerDay, available, type);



            ofstream file("vehicles.txt", ios::app);
            file << id << "," << brand << "," << model << "," << fuelType << "," << type  << "," << power << "," << year << "," << noOfPassengers << "," << loadCapacity << "," << milage << "," << rentPerDay << "," << 1 << endl;
            file.close();

            return vehicle;
        }

        int removeVehicle(string id){
            ifstream file("vehicles.txt");
            ofstream temp("temp.txt");
            string line;
            while(getline(file, line)){
                stringstream ss(line);
                string Id;
                getline(ss, Id, ',');
                if(Id != id){
                    temp << line << endl;
                }
            }
            file.close();
            temp.close();
            remove("vehicles.txt");
            rename("temp.txt", "vehicles.txt");
            return 0;
        }
        

};

#endif