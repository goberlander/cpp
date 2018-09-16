#ifndef CAR_H
#define CAR_H
#include "Automobile.h"
#include <string>
using namespace std;

class Car : public Automobile // This allows Car to access all (but private) members of Automobile
{
private:
    int doors;
public:
    Car() : Automobile()
    {doors = 0;}
    // Constructor #2: Automobile constructor is initialized with the values from Car Class.
    Car(string carMake, int carModel, int carMiles, double carPrice, int carDoors) : Automobile (carMake, carModel, carMiles, carPrice) // These are arguments being passed (which is why no data type in context)
    { doors = carDoors; }
        
    int getDoors()
    {return doors;}
};
#endif