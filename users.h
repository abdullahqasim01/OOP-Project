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

        int rentVehicle(Vehicle* vehicle, int days){
            float amount = days * vehicle->getRentPerDay();
            string id = vehicle->getId();
            // int status = payment->makePayment(amount);
            int status = 0;
            if(status == 0){
                vehicle->setAvailable(false);
                ifstream file("vehicles.txt");
            ofstream temp("temp.txt");
            string line;
            while(getline(file, line)){
                stringstream ss(line);
                string Id, brand, model, fuelType, type;
                int power,  year, noOfPassengers, loadCapacity, milage,  rentPerDay, available;
                string t;
                getline(ss, Id, ',');
                getline(ss, brand, ',');
                getline(ss, model, ',');
                getline(ss, fuelType, ',');
                getline(ss, type, ',');
                getline(ss, t, ',');
                power = sti(t);
                getline(ss, t, ',');
                year = sti(t);
                getline(ss, t, ',');
                noOfPassengers = sti(t);
                getline(ss, t, ',');
                loadCapacity = sti(t);
                getline(ss, t, ',');
                milage = sti(t);
                getline(ss, t, ',');
                rentPerDay = sti(t);
                getline(ss, t, ',');
                available = sti(t);

                if(Id == id){
                    available = 0;
                }
                temp << Id << "," << brand << "," << model << "," << fuelType << "," << type  << "," << power << "," << year << "," << noOfPassengers << "," << loadCapacity << "," << milage << "," << rentPerDay << "," << available << endl;
            }
            file.close();
            temp.close();
            remove("vehicles.txt");
            rename("temp.txt", "vehicles.txt");

                ofstream rentFile("rent.txt", ios::app);
                rentFile << username << "," << vehicle->getId() << "," << days << "," << amount << endl;
                rentFile.close();

                return 0;
            }
        }

        int returnVehicle(Vehicle* vehicle){
            vehicle->setAvailable(true);
            string id = vehicle->getId();
            ifstream file("vehicles.txt");
            ofstream temp("temp.txt");
            string line;
            while(getline(file, line)){
                stringstream ss(line);
                string Id, brand, model, fuelType, type;
                int power,  year, noOfPassengers, loadCapacity, milage,  rentPerDay, available;
                string t;
                getline(ss, Id, ',');
                getline(ss, brand, ',');
                getline(ss, model, ',');
                getline(ss, fuelType, ',');
                getline(ss, type, ',');
                getline(ss, t, ',');
                power = sti(t);
                getline(ss, t, ',');
                year = sti(t);
                getline(ss, t, ',');
                noOfPassengers = sti(t);
                getline(ss, t, ',');
                loadCapacity = sti(t);
                getline(ss, t, ',');
                milage = sti(t);
                getline(ss, t, ',');
                rentPerDay = sti(t);
                getline(ss, t, ',');
                available = sti(t);

                if(Id == id){
                    available = 1;
                }
                temp << Id << "," << brand << "," << model << "," << fuelType << "," << type  << "," << power << "," << year << "," << noOfPassengers << "," << loadCapacity << "," << milage << "," << rentPerDay << "," << available << endl;
            }
            file.close();
            temp.close();
            remove("vehicles.txt");
            rename("temp.txt", "vehicles.txt");

            ifstream file_("rent.txt");
            ofstream temp_("temp.txt");
            string line_;
            while(getline(file_, line_)){
                stringstream ss(line_);
                string u, id_, days, amount;
                getline(ss, u, ',');
                getline(ss, id_, ',');
                getline(ss, days, ',');
                getline(ss, amount, ',');
                if(id_ != id){
                    temp_ << line_ << endl;
                }
            }
            file_.close();
            temp_.close();
            remove("rent.txt");
            rename("temp.txt", "rent.txt");

            return 0;
        
        }

        void showRentedVehicles(){
            ifstream file("rent.txt");
            string line;
            cout << setw(10) << "Username" << setw(10) << "Vehicle ID" << setw(10) << "Days" << setw(10) << "Amount" << endl;
            while(getline(file, line)){
                stringstream ss(line);
                string u, id, days, amount;
                getline(ss, u, ',');
                getline(ss, id, ',');
                getline(ss, days, ',');
                getline(ss, amount, ',');
                if(u == username){
                    cout << setw(10) << u << setw(10) << id << setw(10) << days << setw(10) << amount << endl;
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
        
        void showAllCustomers(){
            ifstream file("customers.txt");
            string line;
            cout << setw(10) << "Username" << setw(10) << "CNIC" << setw(10) << "Mobile Number" << setw(10) << "Driving Lincese" << setw(10) << "Bike Lincese" << setw(10) << "Car Lincese" << endl;
            while(getline(file, line)){
                stringstream ss(line);
                string u, p, cnic, mobileNumber, drivingLincese, bikeLincese, carLincese;
                getline(ss, u, ',');
                getline(ss, p, ',');
                getline(ss, cnic, ',');
                getline(ss, mobileNumber, ',');
                getline(ss, drivingLincese, ',');
                getline(ss, bikeLincese, ',');
                getline(ss, carLincese, ',');
                cout << setw(10) << u << setw(10) << cnic << setw(10) << mobileNumber << setw(10) << drivingLincese << setw(10) << bikeLincese << setw(10) << carLincese << endl;
            }
            file.close();
        }

        void showAllVehicles(){
            ifstream file("vehicles.txt");
            string line;
            cout << setw(10) << "ID" << setw(10) << "Type" << setw(10) << "Brand" << setw(10) << "Model" << setw(10) << "Year" << setw(10) << "Rent/Day" << setw(10) << "Milage" << setw(10) << "Power" << setw(10) << "Fuel Type" << setw(10) << "Passengers" << setw(10) << "Load Capacity" << setw(10) << "Availiable" << endl;
            while(getline(file, line)){
                stringstream ss(line);
                string id, brand, model, fuelType, type;
                int power,  year, noOfPassengers, loadCapacity, milage,  rentPerDay, available;
                bool availiableBool;
                string t;
                getline(ss, id, ',');
                getline(ss, brand, ',');
                getline(ss, model, ',');
                getline(ss, fuelType, ',');
                getline(ss, type, ',');
                getline(ss, t, ',');
                power = sti(t);
                getline(ss, t, ',');
                year = sti(t);
                getline(ss, t, ',');
                noOfPassengers = sti(t);
                getline(ss, t, ',');
                loadCapacity = sti(t);
                getline(ss, t, ',');
                milage = sti(t);
                getline(ss, t, ',');
                rentPerDay = sti(t);
                getline(ss, t, ',');
                available = sti(t);

                if(available == 1){
                    availiableBool = true;
                }else{
                    availiableBool = false;
                }
                cout << setw(10) << id << setw(10) << type << setw(10) << brand << setw(10) << model << setw(10) << year << setw(10) << rentPerDay << setw(10) << milage << setw(10) << power << setw(10) << fuelType << setw(10) << noOfPassengers << setw(10) << loadCapacity << setw(10) << availiableBool << endl;
            }
            file.close();
        }


        void searchVehicle(){
            ifstream file("vehicles.txt");
            string line;
            cout << "Enter ID: ";
            string id;
            cin >> id;
            while(getline(file, line)){
                stringstream ss(line);
                string Id, brand, model, fuelType, type;
                int power,  year, noOfPassengers, loadCapacity, milage,  rentPerDay, available;
                bool availiableBool;
                string t;
                getline(ss, Id, ',');
                getline(ss, brand, ',');
                getline(ss, model, ',');
                getline(ss, fuelType, ',');
                getline(ss, type, ',');
                getline(ss, t, ',');
                power = sti(t);
                getline(ss, t, ',');
                year = sti(t);
                getline(ss, t, ',');
                noOfPassengers = sti(t);
                getline(ss, t, ',');
                loadCapacity = sti(t);
                getline(ss, t, ',');
                milage = sti(t);
                getline(ss, t, ',');
                rentPerDay = sti(t);
                getline(ss, t, ',');
                available = sti(t);

                if(Id == id){
                    if(available == 1){
                        availiableBool = true;
                    }else{
                        availiableBool = false;
                    }
                    cout << setw(10) << Id << setw(10) << type << setw(10) << brand << setw(10) << model << setw(10) << year << setw(10) << rentPerDay << setw(10) << milage << setw(10) << power << setw(10) << fuelType << setw(10) << noOfPassengers << setw(10) << loadCapacity << setw(10) << availiableBool << endl;
                    break;
                }
            }
            file.close();
        }

        int editVehicle(Vehicle* vehicle){
            string brand, model, id, type, fuelType, Id;
            int power,  year, noOfPassengers, loadCapacity, milage,  rentPerDay;
            bool available;

            brand = vehicle->getBrand();
            model = vehicle->getModel();
            id = vehicle->getId();
            type = vehicle->getType();
            fuelType = vehicle->getFuelType();
            power = vehicle->getPower();
            year = vehicle->getYear();
            noOfPassengers = vehicle->getNoOfPassengers();
            loadCapacity = vehicle->getLoadCapacity();
            milage = vehicle->getMilage();
            rentPerDay = vehicle->getRentPerDay();
            available = vehicle->getAvailable();
            
            int t;
            string te;

            cin.ignore();
            cout << "Enter 0 to keep the previous value";
            cout << "Enter Brand: ";
            getline(cin, te);
            if (te != "0")
                brand = te;
            cout << "Enter Model: ";
            getline(cin, te);
            if (te != "0")
                model = te;
            cout << "Enter Type: ";
            getline(cin, te);
            if (te != "0")
                type = te;
            cout << "Enter ID: ";
            getline(cin, te);
            if (te != "0")
                Id = te;
            cout << "Enter Fuel Type: ";
            getline(cin, te);
            if (te != "0")
                fuelType = te;
            cout << "Enter Power: ";
            cin >> t;
            if (t != 0)
                power = t;
            cout << "Enter Year: ";
            cin >> t;
            if (t != 0)
                year = t;
            cout << "Enter Number of Passengers: ";
            cin >> t;
            if (t != 0)
                noOfPassengers = t;
            cout << "Enter Load Capacity: ";
            cin >> t;
            if (t != 0)
                loadCapacity = t;
            cout << "Enter Milage: ";
            cin >> t;
            if (t != 0)
                milage = t;
            cout << "Enter Rent Per Day: ";
            cin >> t;
            if (t != 0)
                rentPerDay = t;
            cout << "Enter Availiable: ";
            cin >> t;
            if (t != 0)
                available = t;
            
            
            vehicle->setBrand(brand);
            vehicle->setModel(model);
            vehicle->setId(Id);
            vehicle->setFuelType(fuelType);
            vehicle->setType(type);
            vehicle->setPower(power);
            vehicle->setYear(year);
            vehicle->setNoOfPassengers(noOfPassengers);
            vehicle->setLoadCapacity(loadCapacity);
            vehicle->setMilage(milage);
            vehicle->setRentPerDay(rentPerDay);
            vehicle->setAvailable(available);

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

            ofstream file_("vehicles.txt", ios::app);
            file_ << id << "," << brand << "," << model << "," << fuelType << "," << type  << "," << power << "," << year << "," << noOfPassengers << "," << loadCapacity << "," << milage << "," << rentPerDay << "," << 1 << endl;
            file_.close();

            return 0;
        }

        void showRentedVehicles(){
            ifstream file("rent.txt");
            string line;
            cout << setw(10) << "Username" << setw(10) << "Vehicle ID" << setw(10) << "Days" << setw(10) << "Amount" << endl;
            while(getline(file, line)){
                stringstream ss(line);
                string u, id, days, amount;
                getline(ss, u, ',');
                getline(ss, id, ',');
                getline(ss, days, ',');
                getline(ss, amount, ',');
                cout << setw(10) << u << setw(10) << id << setw(10) << days << setw(10) << amount << endl;
            }
            file.close();
        }



};

#endif