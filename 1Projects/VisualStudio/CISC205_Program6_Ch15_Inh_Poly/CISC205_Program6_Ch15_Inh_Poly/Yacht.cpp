#include "pch.h"
#include "Yacht.h"


Yacht::Yacht()
{
	name = "";
	length = 0.0;
	year_built = "";
}

Yacht::~Yacht()
{
}

// YACHT BASE CLASS

//******************************************************************************************
// Name:		setBoatName
// Called by:	addNewYacht, addNewPowerboat, addNewSailboat
// Passed:		string
// Returns:		nothing
// Calls:		no one
//				
// This sets the passed name to the iterated Yacht object's name.
//******************************************************************************************
void Yacht::setBoatName(string n)
{
	name = n;
}

//******************************************************************************************
// Name:		setYachtLength
// Called by:	addNewYacht
// Passed:		float
// Returns:		nothing
// Calls:		no one
//				
// This sets the passed float to the iterated Yacht object's length.
//******************************************************************************************
void Yacht::setYachtLength(float l)
{
	length = l;
}

//******************************************************************************************
// Name:		setYearBuild
// Called by:	addNewYacht
// Passed:		string
// Returns:		nothing
// Calls:		no one
//				
// This sets the passed string to the iterated Yacht object's year built.
//******************************************************************************************
void Yacht::setYearBuilt(string y)
{
	year_built = y;
}

//******************************************************************************************
// Name:		printBoats
// Called by:	menu
// Passed:		nothing
// Returns:		nothing
// Calls:		no one
//				
// This will display the information of the iterated Yacht object.
//******************************************************************************************
void Yacht::printBoats()
{
	cout << "Yacht Name: " << getBoatName() << endl;
	cout << "Yacht length: " << setprecision(2) << fixed << showpoint << getBoatLength() << endl;
	cout << "Yacht year: " << getYearBuilt() << endl << endl;
}


// POWERBOAT CHILD CLASS

//******************************************************************************************
// Name:		setNumberOfEngines
// Called by:	addNewPowerboat
// Passed:		validated integer
// Returns:		nothing
// Calls:		no one
//				
// Sets the passed data to the # of engines associated with the iterated powerboat object.
//******************************************************************************************
void Powerboat::setNumberOfEngines(int engines)
{
	number_of_engines = engines;
}

//******************************************************************************************
// Name:		getNumberOfEngines
// Called by:	printBoats
// Passed:		validated integer
// Returns:		the # of engines
// Calls:		no one
//				
// Returns the # of engines associated with the iterated Powerboat object.
//******************************************************************************************
int Powerboat::getNumberOfEngines()
{
	return number_of_engines;
}

//******************************************************************************************
// Name:		setTotalHorsePower
// Called by:	addNewPowerBoat
// Passed:		validated float
// Returns:		nothing
// Calls:		no one
//				
// Sets the total horse power of the iterated Powerboat object with the passed float.
//******************************************************************************************
void Powerboat::setTotalHorsePower(float power)
{
	total_horsepower = power;
}

//******************************************************************************************
// Name:		getTotalHorsePower
// Called by:	printBoats
// Passed:		nothing
// Returns:		float
// Calls:		no one
//				
// Returns the the total horsepower associated with the iterated Powerboat object
//******************************************************************************************
float Powerboat::getTotalHorsePower()
{
	return total_horsepower;
}

//******************************************************************************************
// Name:		printBoats
// Called by:	menu
// Passed:		nothing
// Returns:		nothing
// Calls:		no one
//				
// This will display the information of the iterated Powerboat object.
//******************************************************************************************
void Powerboat::printBoats()
{
	cout << "Powerboat Name: " << getBoatName() << endl;
	cout << "Number of engines: " << getNumberOfEngines() << endl;
	cout << "Total horsepower: " << setprecision(2) << fixed << showpoint << getTotalHorsePower() << endl << endl;
}


// SAILBOAT CHILD CLASS

//******************************************************************************************
// Name:		setSailArea
// Called by:	addNewSailboat
// Passed:		validated float
// Returns:		nothing
// Calls:		no one
//				
// This will set the sail area of the iterated Sailboat object with the passed float.
//******************************************************************************************
void Sailboat::setSailArea(float area)
{
	sail_area = area;
}

//******************************************************************************************
// Name:		getSailArea
// Called by:	printBoats
// Passed:		nothing
// Returns:		float
// Calls:		no one
//				
// This will return the sail area associated with the iterated Sailboat object.
//******************************************************************************************
float Sailboat::getSailArea()
{
	return sail_area;
}

//******************************************************************************************
// Name:		printBoats
// Called by:	menu
// Passed:		nothing
// Returns:		nothing
// Calls:		no one
//				
// This will display the information of the iterated Sailboat object.
//******************************************************************************************
void Sailboat::printBoats()
{
	cout << "Sailboat Name: " << getBoatName() << endl;
	cout << "Sailboat area: " << setprecision(2) << fixed << showpoint << getSailArea() << endl << endl;
}