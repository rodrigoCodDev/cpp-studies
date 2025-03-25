#include <iostream>
using namespace std;

#include <string>

#include "./vehicle.h"

// g++ -Wall -Wunused-but-set-variable ./main.cpp -o main.out -lm

void showMenu() {
    cout << "----------------" << endl;
    cout << "PARKING MANAGER" << endl;
    cout << "----------------" << endl;
    cout << "[1] Park a vehicle" << endl;
    cout << "[2] Vehicle database" << endl;
    cout << "[0] Exit" << endl;
    cout << ">> ";
}

void showMenuVehicle() {
    cout << "----------------" << endl;
    cout << "1.1 VEHICLE TYPE" << endl;
    cout << "[1] Car" << endl;
    cout << "[2] Motorcycle" << endl;
    cout << "[0] Cancel" << endl;
    cout << ">> ";
}

void showMenuParkVehicle() {
    cout << "----------------" << endl;
    cout << "1.2 INSERT" << endl;
    cout << "[1] New" << endl;
    cout << "[2] From database" << endl;
    cout << "[0] Cancel" << endl;
    cout << ">> ";
}

Vehicle getNewInsertToDatabase(VehicleType vehicleType) {
    string owner;
    string plate;
    string model;
    string color;

    cout << "----------------" << endl;
    cout << "NEW INSERT" << endl;

    cout << "Insert owner's name: ";
    cin >> owner;
    cout << endl;
    
    cout << "Insert vehicle plate: ";
    cin >> plate;
    cout << endl;

    cout << "Insert model of vehicle: ";
    cin >> model;
    cout << endl;

    cout << "Insert color of vehicle: ";
    cin >> color;
    cout << endl;

    Vehicle vehicle(owner, plate, color, vehicleType);

    return vehicle;
}


int main() {
    int option = 0;

    showMenu();
    cin >> option;

    if (option == 1) {
        return 0;
    } else if (option == 2) {
        return 0;
    } else if (option == 0) {
        return 0;
    }

    return 0;
}