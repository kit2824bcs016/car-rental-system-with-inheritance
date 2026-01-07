#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Car {
protected:
    string carName;
    int carID;
public:
    Car(string name = "Unknown", int id = 0) {
        carName = name;
        carID = id;
    }
    virtual int calculateRent(int days) = 0;
    virtual void display() {
        cout << "Car: " << carName << " | ID: " << carID << endl;
    }
};
class Sedan : public Car {
public:
    Sedan(string n, int id) : Car(n, id) {}
    int calculateRent(int days) {
        return days * 1500;
    }
};
class SUV : public Car {
public:
    SUV(string n, int id) : Car(n, id) {}
    int calculateRent(int days) {
        return days * 2500;
    }
};
int main() {
    int choice, days;
    Car* selectedCar;
    cout << "\n===== CAR RENTAL SYSTEM =====" << endl;
    cout << "1. Rent Sedan\n2. Rent SUV\nEnter choice: ";
    cin >> choice;
    if (choice == 1)
        selectedCar = new Sedan("Honda City", 101);
    else if (choice == 2)
        selectedCar = new SUV("Toyota Fortuner", 202);
    else {
        cout << "Invalid choice!";
        return 0;
    }
    cout << "Enter number of rental days: ";
    cin >> days;
    int rent = selectedCar->calculateRent(days);
    cout << "\n=== BOOKING SUMMARY ===" << endl;
    selectedCar->display();
    cout << "Days: " << days << endl;
    cout << "Total Rent: Rs " << rent << endl;
    int finalAmount = rent + 300;
    cout << "Final Amount (+300 Service Charge): Rs " << finalAmount << endl;
    ofstream file("bookings.txt", ios::app);
    file << "Car Choice: " << (choice == 1 ? "Sedan" : "SUV")
         << ", Days: " << days
         << ", Amount: " << finalAmount << endl;
    file.close();
    cout << "\nBooking saved in bookings.txt!" << endl;
    delete selectedCar;
    return 0;
}


