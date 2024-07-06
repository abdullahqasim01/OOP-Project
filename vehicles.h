
#ifndef VEHICLES_H
#define VEHICLES_H

#include <iostream>
using namespace std;


class Vehicle{
    protected:
        string brand, model, id, fuelType, type;
        int power, year, noOfPassengers, loadCapacity;
        float milage, rentPerDay;
        bool available;
    
    public:
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

};

#endif