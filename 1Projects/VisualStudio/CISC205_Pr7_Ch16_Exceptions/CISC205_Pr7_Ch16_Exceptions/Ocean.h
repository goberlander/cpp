/*
* Glenn Oberlander
* CISC205 - Object Oriented Programming with C++
* Program 7 for Chapter 16: Exceptions, Templates, and the STL
* Due : November 29th, 2018
*
*	Header file for including in CISC205_Pr7_Ch16_Exceptions.cpp
*	This has throw exceptions that will be handled in main
*/

#ifndef OCEAN_H
#define OCEAN_H

#pragma once
#include <iostream>
#include <string>
using namespace std;

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

	class LongName {}; // Will throw an exception if name too big
	class NegativeFloat {}; // Will throw exception if input negative

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


