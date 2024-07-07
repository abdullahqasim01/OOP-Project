
#ifndef VEHICLES_H
#define VEHICLES_H

#include <iostream>
#include<iomanip>
using namespace std;


class Vehicle{
    protected:
        string brand, model, id, fuelType, type;
        int power, year, noOfPassengers, loadCapacity, milage, rentPerDay;
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

        Vehicle(string brand, string model, string id, string fuelType, int power, int year, int noOfPassengers, int loadCapacity, int milage, int rentPerDay, bool available, string type){
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

        void setType(string type){
            this->type = type;
        }

        string getType(){
            return type;
        }

        void setBrand(string brand){
            this->brand = brand;
        }

        string getBrand(){
            return brand;
        }

        void setModel(string model){
            this->model = model;
        }

        string getModel(){
            return model;
        }

        void setId(string id){
            this->id = id;
        }

        void setFuelType(string fuelType){
            this->fuelType = fuelType;
        }

        void setPower(int power){
            this->power = power;
        }

        void setYear(int year){
            this->year = year;
        }

        void setNoOfPassengers(int noOfPassengers){
            this->noOfPassengers = noOfPassengers;
        }

        void setLoadCapacity(int loadCapacity){
            this->loadCapacity = loadCapacity;
        }

        void setAvailable(bool available){
            this->available = available;
        }
        bool getAvailable(){
            return available;
        }
        void setRentPerDay(int rentPerDay){
            this->rentPerDay = rentPerDay;
        }
        int getRentPerDay(){
            return rentPerDay;
        }
        void setMilage(int milage){
            this->milage = milage;
        }
        int getMilage(){
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
            cout << setw(10) << id << setw(10) << type << setw(10) << brand << setw(10) << model << setw(10) << year << setw(10) << rentPerDay << setw(10) << milage << setw(10) << power << setw(10) << fuelType << setw(10) << noOfPassengers << setw(10) << loadCapacity << endl;
        }

};

#endif