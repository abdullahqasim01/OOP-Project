#include <iostream>
#include "users.cpp"
#include "vehicles.cpp"
using namespace std;

int main() {
    Payment p("1234567890123456", "John Doe", "Visa", 2025, 12, 123);
    int status = p.makePayment(1000);
    if(status == 0){
        cout << "Payment Successful" << endl;
    }
    else if(status == -1){
        cout << "Card Expired" << endl;
    }
    else if(status == -2){
        cout << "Invalid CVV" << endl;
    }
}