#include <iostream>
using namespace std;

#include <sstream>
#include <string>
#include <map>

enum VehicleType {
    CAR,
    MOTORCYCLE
};

std::map<VehicleType, std::string> vehicleTypeToString = {
    {CAR, "Car"},
    {MOTORCYCLE, "Motorcycle"}
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

    string getOwner() const { return owner; }
    string getPlate() const { return plate; }
    string getColor() const { return color; }
    VehicleType getVehicleType() const { return vehicleType; }

    string toString() {
        ostringstream output;
        output << "Vehicle: {\n"
            << "\tType: " << vehicleTypeToString[this->vehicleType] << "\n"
            << "\tOwner: " << this->owner << "\n"
            << "\tPlate: " << this->plate << "\n"
            << "\tColor: " << this->color << "\n"
            << "}";
        
        return output.str();
    }
};