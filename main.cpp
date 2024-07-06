#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <conio.h>

#include "users.h"
#include "vehicles.h"
#include "utils.h"

using namespace std;

void showWelcomeScreen();
void showAllAvailiableVehicles(Vehicle* vehicles[], int n);
void showAdminMenu();
void showCustomerMenu();
void loadVehicles(Vehicle* vehicles[], int n);

int main() {
    int n = 1;
    Vehicle* vehicles[n];
    loadVehicles(vehicles, n);

    Admin* admin;
    Customer* customer;
    int choice = 0;
    string id;
    int status;

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
            status = customer->login();
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
        status = customer->register_(cnic, mobileNumber, drivingLincese, bikeLincese, carLincese);
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
            status = admin->login();
            if(status == 0){
                cout << "Admin logged in successfully" << endl;
                showAdminMenu();
                int adminChoice;
                cin >> adminChoice;
                switch (adminChoice)
                {
                    case 1:
                        vehicles[0] =  admin->addVehicle();
                        cout << "Vehicle added successfully" << endl;
                        break;
                    
                    case 2:
                        showAllAvailiableVehicles(vehicles, n);
                        cout << "Enter ID of vehicle to remove: ";
                        cin >> id;
                        status = admin->removeVehicle(id);
                        if(status == 0){
                            cout << "Vehicle removed successfully" << endl;
                        }
                        else{
                            cout << "Vehicle not found" << endl;
                        }
                        break;
                    
                    case 6:
                        showAllAvailiableVehicles(vehicles, n);
                        cout << "Press any key to continue" << endl;
                        getch();
                        break;

                    default:
                        break;
                }
                continue;
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

        else{
            cout << "Invalid choice" << endl;
            showWelcomeScreen();
        }

    continue;
    }

    cout << "Thank you for using Vehicle Rental System" << endl;

}

void showWelcomeScreen(){
    cout << "1. Login" << endl;
    cout << "2. Register" << endl;
    cout << "3. Admin Login" << endl;
    cout << "4. Exit" << endl;
}

void showCustomerMenu(){

}

void showAdminMenu(){
    cout << "1. Add Vehicle" << endl;
    cout << "2. Remove Vehicle" << endl;
    cout << "3. Edit Vehicle" << endl;
    cout << "4. Show All Customers" << endl;
    cout << "5. Show All Vehicles" << endl;
    cout << "6. Show All Available Vehicles" << endl;
    cout << "7. Show All Rented Vehicles" << endl;
    cout << "8. Show All Payments" << endl;
    cout << "9. Show Pending Payments" << endl;
    cout << "10. Show Completed Payments" << endl;
    cout << "11. Show History" << endl;
    cout << "12. Show History of Specific Customer" << endl;
    cout << "13. Generate Report" << endl;
}

void loadVehicles(Vehicle* vehicles[], int n){
    ifstream file("vehicles.txt");
    string temp, t;
    string brand, model, id, type, fuelType;
    int power,  year, noOfPassengers, loadCapacity, milage,  rentPerDay, available;
    // bool available;
    getline(file, temp);
    sti(temp);
    for(int i = 0; i < n; i++){
        getline(file, temp);

        stringstream ss(temp);
        getline(ss, id, ',');
        getline(ss, brand, ',');
        getline(ss, model, ',');
        getline(ss, fuelType, ',');
        getline(ss, type, ',');
        getline(ss, t, ',');
        power = sti(t);
        getline(ss, t, ',');
        year = sti(t);
        getline(ss, t, ',');
        noOfPassengers = sti(t);
        getline(ss, t, ',');
        loadCapacity = sti(t);
        getline(ss, t, ',');
        milage = sti(t);
        getline(ss, t, ',');
        rentPerDay = sti(t);
        getline(ss, t, ',');
        available = sti(t);

        if (available == 1){
            vehicles[i] = new Vehicle(brand, model, id, fuelType, power, year, noOfPassengers, loadCapacity, milage, rentPerDay, true, type);
            vehicles[i]->display();
            cout << "Vehicle added" << endl;
        }
        else{
            vehicles[i] = new Vehicle(brand, model, id, fuelType, power, year, noOfPassengers, loadCapacity, milage, rentPerDay, false, type);
            vehicles[i]->display();
            cout << "Vehicle added" << endl;
        }

    }
    file.close();
}

void showAllAvailiableVehicles(Vehicle* vehicles[], int n){
    cout << "All Availiable Vehicles" << endl;
    cout << setw(10) << "ID" << setw(10) << "Type" << setw(10) << "Brand" << setw(10) << "Model" << setw(10) << "Year" << setw(10) << "Rent/Day" << setw(10) << "Milage" << setw(10) << "Power" << setw(10) << "Fuel Type" << setw(10) << "Passengers" << setw(10) << "Load Capacity" << endl;

    for(int i = 0; i < n; i++){
        if(vehicles[i]->getAvailable()){
            vehicles[i]->display();
        }
    }
}