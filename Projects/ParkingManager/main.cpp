#include <iostream>
using namespace std;

#include <string>

#include "./vehicle.h"

// g++ -Wall -Wunused-but-set-variable ./main.cpp -o main.out -lm

void showMenu() {
    system("clear");
    cout << "----------------" << endl;
    cout << "PARKING MANAGER" << endl;
    cout << "----------------" << endl;
    cout << "[1] Park a vehicle" << endl;
    cout << "[2] Vehicle database" << endl;
    cout << "[0] Exit" << endl;
    cout << ">> ";
}

void showMenuVehicle() {
    system("clear");
    cout << "----------------" << endl;
    cout << "1.1 VEHICLE TYPE" << endl;
    cout << "[1] Car" << endl;
    cout << "[2] Motorcycle" << endl;
    cout << "[0] Cancel" << endl;
    cout << ">> ";
}

void showMenuParkVehicle() {
    system("clear");
    cout << "----------------" << endl;
    cout << "1.2 INSERT" << endl;
    cout << "[1] New" << endl;
    cout << "[2] From database" << endl;
    cout << "[0] Cancel" << endl;
    cout << ">> ";
}

Vehicle createNewVehicle(VehicleType vehicleType) {
    string owner;
    string plate;
    string model;
    string color;

    cout << "----------------" << endl;
    cout << "NEW VEHICLE" << endl;

    cout << "Insert owner's name: ";
    cin >> owner;
    
    cout << "Insert vehicle plate: ";
    cin >> plate;

    cout << "Insert model of vehicle: ";
    cin >> model;

    cout << "Insert color of vehicle: ";
    cin >> color;

    Vehicle vehicle(owner, plate, color, vehicleType);

    return vehicle;
}


int main() {
    int option = 0;

    showMenu();
    cin >> option;

    if (option == 1) {
        VehicleType vehicleType;

        system("clear");
        showMenuVehicle();
        cin >> option;

        if (option == 1) {
            vehicleType = CAR;
        } else if (option == 2) {
            vehicleType = MOTORCYCLE;
        } else {
            return 0;
        }

        showMenuParkVehicle();
        cin >> option;

        if (option == 1) {
            Vehicle vehicle = createNewVehicle(vehicleType);
            cout << vehicle.toString() << endl;
        }
        
        
    } else if (option == 2) {
        return 0;
    } else if (option == 0) {
        return 0;
    }

    return 0;
}