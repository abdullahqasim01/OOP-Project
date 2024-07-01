#include <iostream>
using namespace std;


class Vehicle{
    protected:
        string brand, model, id, fuelType;
        int power, year;
        float milage, rentPerDay;
        bool available;
    
    public:
        Vehicle(string brand, string model, string id, string fuelType, int power, int year, float milage, float rentPerDay, bool available){
            this->brand = brand;
            this->model = model;
            this->id = id;
            this->fuelType = fuelType;
            this->power = power;
            this->year = year;
            this->milage = milage;
            this->rentPerDay =  rentPerDay;
            this->available = available;
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


};

class Car : private Vehicle{
    private:
        int noOfPassengers;
    
    public:
        Car(string brand, string model, string id, string fuelType, int power, int year, float milage, float rentPerDay, bool available, int noOfPassengers): Vehicle(brand, model, id, fuelType, power, year, milage, rentPerDay, available){
            this->noOfPassengers = noOfPassengers;
        }
        int getNoOfPassengers(){
            return noOfPassengers;
        }
};

class Cargo : private Vehicle{
    private:
        int loadCapacity;

    public:
        Cargo(string brand, string model, string id, string fuelType, int power, int year, float milage, float rentPerDay, bool available, int loadCapacity) : Vehicle(brand, model, id, fuelType, power, year, milage, rentPerDay, available){
            this->loadCapacity = loadCapacity;
        }
        int getLoadCapacity(){
            return loadCapacity;
        }
};

class Bike : private Vehicle{
    private:
        int noOfPassengers;
    
    public:
        Bike(string brand, string model, string id, string fuelType, int power, int year, float milage, float rentPerDay, bool available, int noOfPassengers) : Vehicle(brand, model, id, fuelType, power, year, milage, rentPerDay, available){
            this->noOfPassengers = noOfPassengers;
        }
        int getNoOfPassengers(){
            return noOfPassengers;
        }

};
