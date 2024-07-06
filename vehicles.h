
#ifndef VEHICLES_H
#define VEHICLES_H

#include <iostream>
#include<iomanip>
using namespace std;


class Vehicle{
    protected:
        string brand, model, id, fuelType, type;
        int power, year, noOfPassengers, loadCapacity;
        float milage, rentPerDay;
        bool available;
    
    public:
        Vehicle(){
            brand = "";
            model = "";
            id = "";
            fuelType = "";
            type = "";
            power = 0;
            year = 0;
            noOfPassengers = 0;
            loadCapacity = 0;
            milage = 0;
            rentPerDay = 0;
            available = false;
        }

        Vehicle(string brand, string model, string id, string fuelType, int power, int year, int noOfPassengers, int loadCapacity, float milage, float rentPerDay, bool available, string type){
            this->brand = brand;
            this->model = model;
            this->id = id;
            this->fuelType = fuelType;
            this->type = type;
            this->power = power;
            this->year = year;
            this->milage = milage;
            this->rentPerDay =  rentPerDay;
            this->available = available;
            this->noOfPassengers = noOfPassengers;
            this->loadCapacity = loadCapacity;
        }

        void setAvailable(bool available){
            this->available = available;
        }
        bool getAvailable(){
            return available;
        }
        void setRentPerDay(float rentPerDay){
            this->rentPerDay = rentPerDay;
        }
        float getRentPerDay(){
            return rentPerDay;
        }
        void setMilage(float milage){
            this->milage = milage;
        }
        float getMilage(){
            return milage;
        }
        int getYear(){
            return year;
        }
        int getPower(){
            return power;
        }
        string getFuelType(){
            return fuelType;
        }
        string getId(){
            return id;
        }
        string getModel(){
            return model;
        }
        string getBrand(){
            return brand;
        }
        int getNoOfPassengers(){
            return noOfPassengers;
        }
        int getLoadCapacity(){
            return loadCapacity;
        }

        void display(){
            cout << setw(10) << id << setw(10) << brand << setw(10) << model << setw(10) << year << setw(10) << rentPerDay << setw(10) << milage << setw(10) << milage << setw(10) << fuelType << setw(10) << type << endl;
        }

};

#endif