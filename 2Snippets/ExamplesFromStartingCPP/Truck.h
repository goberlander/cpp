#ifndef TRUCK_H
#define TRUCK_H
#include "Automobile.h"
#include <string>
using namespace std;

class Truck : public Automobile
{
private: 
    string driveType;
public:
    // Initializes driveType. Not sure why I am call Automobile. If maybe I have to...? It is because, it initializes the Automobiles default attributes (that are still needed for the derived class because a Truck is a sub-class of Automobile with attributes of an automobile)
    Truck() : Automobile() // Use to initialize Automobile's constructor variables.
    {driveType = "";}
    // Constructor #2; aka Overloaded Constructor
    Truck(string truckMake, int truckModel, int truckMiles, double truckPrice, string truckDriveType) : Automobile (truckMake, truckModel, truckMiles, truckPrice)
    {driveType = truckDriveType;}

    string getDriveType()
    { return driveType; }
};
#endif