#include <iostream>
using namespace std;


class Vehicle{
    protected:
        string brand, model, id, fuelType;
        int power, year;
        float milage, rentPerDay;
    
};

class Car : private Vehicle{
    int noOfPassengers;
};

class Cargo : private Vehicle{
    int loadCapacity;
};

class Bike : private Vehicle{
    int noOfPassengers;
};
