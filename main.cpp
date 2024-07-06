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