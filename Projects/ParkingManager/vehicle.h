#include <iostream>
using namespace std;

#include <string>

enum VehicleType {
    CAR,
    MOTORCYCLE
};

class Vehicle {
private:
    string owner;
    string plate;
    string color;
    VehicleType vehicleType;

public:
    Vehicle(string owner, string plate, string color, VehicleType vehicleType) {
        this->owner = owner;
        this->plate = plate;
        this->color = color;
        this->vehicleType = vehicleType;
    }
};