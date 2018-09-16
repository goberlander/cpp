#ifndef SUV_H
#define SUV_H
#include "Automobile.h"
#include <string>
using namespace std;

class SUV : public Automobile
{
private:
    int passengers;
public:
    SUV() : Automobile()
    {passengers = 0;}

    SUV(string SUVMake, int SUVModel, int SUVMiles, double SUVPrice, int SUVPassengers) : Automobile(SUVMake, SUVModel, SUVMiles, SUVPrice)
    {passengers = SUVPassengers;}

    int getPassengers()
    {return passengers;}
};
#endif