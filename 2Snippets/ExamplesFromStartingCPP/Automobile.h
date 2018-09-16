#ifndef AUTOMOBILE_H
#define AUTOMOBILE_H
#include <string>
using namespace std;

class Automobile {
private:
    string make;
    int model;
    int miles;
    double price;
public:
    // Default constructor
    Automobile()
    {
        make = "";
        model = 0;
        miles = 0;
        price = 0.0;
    }
    // Constructor
    Automobile(string autoMake, int autoModel, int autoMiles, double autoPrice)
    {
        make = autoMake;
        model = autoModel;
        miles = autoMiles;
        price = autoPrice;
    }
    // Accessor
    string getMake() const
    {return make;}
    int getModel() const
    {return model;}
    int getMiles() const
    {return miles;}
    double getPrice() const
    {return price;}
};
#endif