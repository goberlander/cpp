#ifndef OCEAN_H
#define OCEAN_H

#pragma once
#include <iostream>
#include <string>
using namespace std;


//	Appropriate constructors
//	A print function that displays the oceans name, volume and pollution area.
//
//	Create overloaded operators for + , -, > , < .Use the surface area attribute to do the arithmetic or comparisons.


class Ocean
{
private:
	string ocean_name;
	float surface_area, // sq km
		pollution_area, // sq km
		salinity_level, // %
		volume;

public:
	Ocean();
	Ocean(string, float, float, float);
	~Ocean();

	// MUTATOR FUNCTIONS
	void setName(string);
	void setSurfArea(float);
	void setPolArea(float);
	void setSalLevel(float);
	void setVolume(float);

	// ACCESSOR FUNCTIONS
	string getName() const;
	float getSurfArea() const;
	float getPolArea() const;
	float getSalLvl() const;
	float getVolume() const;
	void displayOceanInfo(Ocean *, int) const;

	// OVERLOADED OPERATORS
	bool operator>(const Ocean &);
	bool operator<(const Ocean &);
	Ocean operator+(const Ocean &);
	Ocean operator-(const Ocean &);
};
#endif

