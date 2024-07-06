#include <iostream>
#include <fstream>
#include <string>
#include "users.h"
#include "vehicles.h"
#include "utils.h"
using namespace std;

void showWelcomeScreen(){
    cout << "Welcome to Vehicle Rental System" << endl;
    cout << "1. Login" << endl;
    cout << "2. Register" << endl;
    cout << "3. Admin Login" << endl;
    cout << "4. Exit" << endl;
}

int main() {
    Vehicle* v[10];

    v[0] = new Vehicle("Toyota", "Innova", "KA01 1234", "Petrol", 2000, 2018, 7, 500, 12.5, 2000, true, "Car");
}