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
    Vehicle* vehicles[100];
    Admin* admin;
    Customer* customer;
    int choice = 0;

    system("cls");
    cout << "Welcome to Vehicle Rental System" << endl;
    showWelcomeScreen();
    while (choice != 4)
    {
        cin >> choice;

        if (choice == 1){
            string username, password;
            cin.ignore();
            cout << "Enter username: ";
            getline(cin, username);
            cout << "Enter password: ";
            getline(cin, password);

            customer = new Customer(username, password);
            int status = customer->login();
            if(status == 0){
                customer->load_data();
                cout << "User logged in successfully" << endl;
            }
            else if(status == -1){
                system("cls");
                cout << "Invalid password" << endl;
            }
            else if(status == -2){
                system("cls");
                cout << "User not found" << endl;
            }
            showWelcomeScreen();
        }

        else if(choice == 2){
        string cnic, mobileNumber, drivingLincese, username, password;
        bool bikeLincese, carLincese;

        cin.ignore();
        cout << "Enter username: ";
        getline(cin, username);
        cout << "Enter password: ";
        getline(cin, password);
        cout << "Enter CNIC: ";
        getline(cin, cnic);
        cout << "Enter Mobile Number: ";
        getline(cin, mobileNumber);
        cout << "Enter Driving License: ";
        getline(cin, drivingLincese);
        cout << "Do you have Bike License? (1/0): ";
        cin >> bikeLincese;
        cout << "Do you have Car License? (1/0): ";
        cin >> carLincese;

        customer = new Customer(username, password, cnic, mobileNumber, drivingLincese, bikeLincese, carLincese);
        int status = customer->register_(cnic, mobileNumber, drivingLincese, bikeLincese, carLincese);
        cout << status << endl;
        if(status == 0){
            cout << "User registered successfully" << endl;
            }
        }

        else if(choice == 3){
            string username, password;
            cin.ignore();
            cout << "Enter username: ";
            getline(cin, username);
            cout << "Enter password: ";
            getline(cin, password);

            admin = new Admin(username, password);
            int status = admin->login();
            if(status == 0){
                cout << "Admin logged in successfully" << endl;
            }
            else if(status == -1){
                system("cls");
                cout << "Invalid password" << endl;
            }
            else if(status == -2){
                system("cls");
                cout << "Admin not found" << endl;
            }
            showWelcomeScreen();
        }

        else if(choice == 4){
            cout << "Exiting..." << endl;
            break;
        }

        else{
            cout << "Invalid choice" << endl;
            showWelcomeScreen();
        }

    continue;
    }

}

void showWelcomeScreen(){
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