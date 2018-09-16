#include <iostream>
#include <iomanip>
#include "Car.h"
#include "Truck.h"
#include "SUV.h"
using namespace std;

int main()
{
    // Creates a car object passing these attributes.
    Car car("BMW", 2007, 50000, 15000.0, 4);
    //Creates a truck object passing these attributes
    Truck truck("Toyota", 2006, 30000, 12000.0, "4WD");
    //Creates an SUV object passing these attributes
    SUV suv("Volvo", 2005, 30000, 18000.0, 5);

    // Display inventory
    cout << fixed << showpoint << setprecision(2);
    cout << "We have the follow car in inventory:\n"
         << car.getModel() << " " << car.getMake()
         << " with " << car.getDoors() << " doors and " << car.getMiles() << " miles.\nPrice: $" << car.getPrice() << endl << endl;
 
    cout << "We have the following truck in inventory:\n" << truck.getModel() << " " << truck.getMake()
        << " with " << truck.getDriveType()
        << " drive type and " << truck.getMiles()
        << " miles.\nPrice: $" << truck.getPrice() << endl << endl;

    cout << "We have the follow SUV in inventory:\n" << suv.getModel() << " " << suv.getMake()
         << " with " << suv.getPassengers() << " passenger capacity and " << suv.getMiles() << " miles.\nPrice: $" << suv.getPrice() << endl << endl;

    return 0;


}