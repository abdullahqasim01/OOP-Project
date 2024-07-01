#include <iostream>
using namespace std;


class Vehicle{
    protected:
        string brand, model, id, fuelType;
        int power, year;
        float milage, rentPerDay;
        bool available;
    
    public:
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
        int getNoOfPassengers(){
            return noOfPassengers;
        }
};

class Cargo : private Vehicle{
    private:
        int loadCapacity;

    public:
        int getLoadCapacity(){
            return loadCapacity;
        }
};

class Bike : private Vehicle{
    private:
        int noOfPassengers;
    
    public:
        int getNoOfPassengers(){
            return noOfPassengers;
        }

};
