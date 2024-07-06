#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#include "users.h"
#include "vehicles.h"
#include "utils.h"

using namespace std;

void showWelcomeScreen();
void showAllAvailiableVehicles(Vehicle vehicles[], int n);

int main() {
    Vehicle v[5];

    v[0] = Vehicle("Toyota", "Innova", "KA01 1234", "Petrol", 1500, 2019, 7, 500, 12.5, 2500, true, "Car");
    v[1] = Vehicle("Toyota", "Fortuner", "KA01 1235", "Diesel", 2000, 2018, 7, 500, 10.5, 3500, true, "Car");
    v[2] = Vehicle("Suzuki", "Access", "KA01 1236", "Petrol", 150, 2019, 2, 50, 50, 500, true, "Bike");
    v[3] = Vehicle("Honda", "Activa", "KA01 1237", "Petrol", 100, 2019, 2, 50, 60, 400, true, "Bike");
    v[4] = Vehicle("Mahindra", "Bolero", "KA01 1238", "Diesel", 1500, 2017, 9, 500, 9.5, 3000, true, "Car");

    showAllAvailiableVehicles(v, 5);
}

void showWelcomeScreen(){
    cout << "Welcome to Vehicle Rental System" << endl;
    cout << "1. Login" << endl;
    cout << "2. Register" << endl;
    cout << "3. Admin Login" << endl;
    cout << "4. Exit" << endl;
}

void showAllAvailiableVehicles(Vehicle vehicles[], int n){
    cout << "All Availiable Vehicles" << endl;
    cout << setw(10) << "ID" << setw(10) << "Brand" << setw(10) << "Model" << setw(10) << "Year" << setw(10) << "Rent/Day" << setw(10) << "Milage" << setw(10) << "Power" << setw(10) << "Fuel Type" << setw(10) << "Type" << endl;

    for(int i = 0; i < n; i++){
        if(vehicles[i].getAvailable()){
            vehicles[i].display();
        }
    }
}