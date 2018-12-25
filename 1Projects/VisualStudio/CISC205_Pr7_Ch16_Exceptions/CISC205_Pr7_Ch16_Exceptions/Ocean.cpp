/*
* Glenn Oberlander
* CISC205 - Object Oriented Programming with C++
* Program 7 for Chapter 16: Exceptions, Templates, and the STL
* Due : November 29th, 2018
*
*	- The specification file for Ocean.h
*	- These are the defintions for the members of the Ocean class. 
*	- There are low level throw exceptions in the mutator functions that will be "caught" in CISC205_Pr7_Ch16_Exceptions.cpp
*/

#include "pch.h"
#include "Ocean.h"

Ocean::Ocean()
{
	ocean_name = "";
	surface_area = 0.0; // sq km
	pollution_area = 0.0; // sq km
	salinity_level = 0.0; // %
}

Ocean::Ocean(string name, float sa, float pa, float sl)
{
	setName(name);
	setSurfArea(sa);
	setPolArea(pa);
	setSalLevel(sl);
}

Ocean::~Ocean()
{
}

//******************************************************************************************
// Name:	setName
// This will set the name to the iterated object. If the name is empty or too long, then
// it will throw an exception
//******************************************************************************************
void Ocean::setName(string name)
{
	if (name.length() >= 20 || name.empty())
		throw LongName();
	else
		ocean_name = name;
}

//******************************************************************************************
// Name:	setSurfArea
// This will set the surface area of the iterated ocean object. If the value is negative,
// it will throw an exception.
//******************************************************************************************
void Ocean::setSurfArea(float sa)
{
	// sq km
	if (sa < 0)
		throw NegativeFloat();
	else
		surface_area = sa;
}

//******************************************************************************************
// Name:	setPolArea
// This will set the pollution area of the iterated ocean object. If the value is negative,
// it will throw an exception.
//******************************************************************************************
void Ocean::setPolArea(float pa)
{
	// sq km
	if (pa < 0)
		throw NegativeFloat();
	else
		pollution_area = pa;
}

//******************************************************************************************
// Name:	setSalLevel
// This will set the salination level of the iterated ocean object. If the value is 
// negative, it will throw an exception.
//******************************************************************************************
void Ocean::setSalLevel(float sl)
{
	// %
	if (sl < 0)
		throw NegativeFloat();
	else
		salinity_level = sl;
}

//******************************************************************************************
// Name:	setVolume
// This will set the volume level of the iterated ocean object. If the value is 
// negative, it will throw an exception.
//******************************************************************************************
void Ocean::setVolume(float vol)
{
	if (vol < 0)
	{
		throw NegativeFloat();
	}
	else
		volume = vol;
}

//******************************************************************************************
// This will return the ocean_name of the iterated Ocean object from main
//******************************************************************************************
string Ocean::getName() const
{
	return ocean_name;
}

//******************************************************************************************
// This will return the surface_area of the iterated Ocean object from main
//******************************************************************************************
float Ocean::getSurfArea() const
{
	return surface_area;
}

//******************************************************************************************
// This will return the pollution_area of the iterated Ocean object from main
//******************************************************************************************
float Ocean::getPolArea() const
{
	return pollution_area;
}

//******************************************************************************************
// This will return the salinity_level of the iterated Ocean object from main
//******************************************************************************************
float Ocean::getSalLvl() const
{
	return salinity_level;
}

//******************************************************************************************
// This will return the volume of the iterated Ocean object from main
//******************************************************************************************
float Ocean::getVolume() const
{
	return volume;
}

//******************************************************************************************
// Name:		displayOceanInfo
// Called by:	searchOcean
// Passed:		op, ocean_index
// Returns:		nothing
// Calls:		Ocean Class: getName, getSurfArea, getPolArea
//				
// This will display name, volume, and pollution area given by the user.
//******************************************************************************************
void Ocean::displayOceanInfo(Ocean *op, int ocean_index) const
{
	cout << "Name: " << ocean_name << endl;
	cout << "Volume: " << volume << "km^3" << endl;
	cout << "Pollution area: " << pollution_area << "km^2" << endl << endl;
}


// OVERLOADED OPERATORS //

//******************************************************************************************
// Name:		operator>
// Called by:	compareTwoOceans
// Passed:		Ocean object
// Returns:		bool
// Calls:		nothing
//						
// This will determine if the passed surface area is greater than the selected surface area.
//******************************************************************************************
bool Ocean::operator>(const Ocean &right)
{
	bool status;

	if (surface_area > right.surface_area)
		status = true;
	else
		status = false;
	return status;
}

//******************************************************************************************
// Name:		operator<
// Called by:	compareTwoOceans
// Passed:		Ocean object
// Returns:		bool
// Calls:		nothing
//						
// This will determine if the passed surface area is less than the selected surface area.
//******************************************************************************************
bool Ocean::operator<(const Ocean &right)
{
	bool status;

	if (surface_area < right.surface_area)
		status = true;
	else
		status = false;
	return status;
}

//******************************************************************************************
// Name:		operator+
// Called by:	computeTwoOceans
// Passed:		Ocean object
// Returns:		an Ocean object
// Calls:		nothing
//						
// This will add the right ocean object to the left one.
//******************************************************************************************
Ocean Ocean::operator+(const Ocean &right)
{
	Ocean temp;
	temp.surface_area = surface_area + right.surface_area;
	return temp;
}

//******************************************************************************************
// Name:		operator-
// Called by:	computeTwoOceans
// Passed:		Ocean object
// Returns:		an Ocean object
// Calls:		nothing
//						
// This will subtract the right ocean object from the left one. And, throw an exception
// if the value is negative.
//******************************************************************************************
Ocean Ocean::operator-(const Ocean &right)
{
	Ocean temp;
	temp.surface_area = surface_area - right.surface_area;
	if (temp.surface_area < 0)
		throw NegativeFloat();
	else
		return temp;
}
