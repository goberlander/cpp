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

void Ocean::setName(string name)
{
	if (name.length() >= 20 || name.empty())
		exit(EXIT_FAILURE);
	else
		ocean_name = name;
}

void Ocean::setSurfArea(float sa)
{
	// sq km
	if (sa < 0)
		exit(EXIT_FAILURE);
	else
		surface_area = sa;
}

void Ocean::setPolArea(float pa)
{
	// sq km
	if (pa < 0)
		exit(EXIT_FAILURE);
	else
		pollution_area = pa;
}

void Ocean::setSalLevel(float sl)
{
	// %
	if (sl < 0)
		exit(EXIT_FAILURE);
	else
		salinity_level = sl;
}

void Ocean::setVolume(float vol)
{
	if (vol < 0)
	{
		exit(EXIT_FAILURE);
	}
	else
		volume = vol;
}

string Ocean::getName() const
{
	return ocean_name;
}

float Ocean::getSurfArea() const
{
	return surface_area;
}

float Ocean::getPolArea() const
{
	return pollution_area;
}

float Ocean::getSalLvl() const
{
	return salinity_level;
}

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
// This will subtract the right ocean object from the left one.
//******************************************************************************************
Ocean Ocean::operator-(const Ocean &right)
{
	Ocean temp;
	temp.surface_area = surface_area - right.surface_area;
	return temp;
}