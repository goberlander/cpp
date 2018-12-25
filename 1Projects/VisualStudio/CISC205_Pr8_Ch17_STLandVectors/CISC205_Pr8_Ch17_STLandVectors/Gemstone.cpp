/*
* Glenn Oberlander
* CISC205 - Object Oriented Programming with C++
* Program 8 for Chapter 17: Using the Standard Template Library
* Due : December 13th, 2018
*
*
*	This is the implementation file for the Gemstone. It uses exception throws for low level input validation.
*	
*/

#include "pch.h"
#include "Gemstone.h"
#include <iostream>
#include <locale>	
#include <iomanip>
using namespace std;

// Initializes Gemstone objects.
Gemstone::Gemstone()
{
	id_number = 0;
	gem_name = "";
	gem_weight = 0.0;
	amt_paid = 0.0;
	rating = "";
}
//// Uncomment if you want to test program
//Gemstone::Gemstone(int id, string n, float w, float p, string r)
//{
//	id_number = id;
//	gem_name = n;
//	gem_weight = w;
//	amt_paid = p;
//	rating = r;
//}

Gemstone::~Gemstone()
{
}


								// MUTATOR FUNCTION DEFINITIONS

//******************************************************************************************
// Name:		setID
// Called by:	addGemstone
// Passed:		int, vector
// Returns:		nothing
// Calls:		Gemstone Class: checkUnique(int, vector)
//						
// If the input is less than 0 or not unique, an error will be thrown; else it will be 
// assigned to the iterated object's id_number.
//******************************************************************************************
void Gemstone::setID(int id, vector<Gemstone>&g)
{
	if (id < 0)
		throw WrongID();
	else if (checkUnique(id, g) == false) // Check for unique ID
	{
		throw NotUnique();	// If ID is false, throw error
	}
	else
		id_number = id;		// Else assign it
}

//******************************************************************************************
// Name:		setName
// Called by:	addGemstone
// Passed:		string
// Returns:		nothing
// Calls:		nothing
//						
// If the input is greater than 15, an error will be thrown; else it will be 
// assigned to the iterated object's gem_name.
//******************************************************************************************
void Gemstone::setName(string n)
{
	if (n.length() > 15)
		throw WrongName();
	else
		gem_name = n;
}

//******************************************************************************************
// Name:		setWeight
// Called by:	addGemstone
// Passed:		float
// Returns:		nothing
// Calls:		nothing
//						
// If the input is <= 0 or not unique an error will be thrown; else it will be
// assigned to the iterated object's gem_weight.
//******************************************************************************************
void Gemstone::setWeight(float w)
{
	if (w <= 0)
		throw WrongFloat();
	else
		gem_weight = w;
}

//******************************************************************************************
// Name:		setAmtPaid
// Called by:	addGemstone
// Passed:		float
// Returns:		nothing
// Calls:		nothing 
//						
// If the input is <= 0 an error will be thrown; else it will be assigned to the iterated 
// object's gem_weight.
//******************************************************************************************
void Gemstone::setAmtPaid(float p)
{
	if (p <= 0)
		throw WrongFloat();
	else
		amt_paid = p;
}

//******************************************************************************************
// Name:		setRating
// Called by:	addGemstone
// Passed:		string
// Returns:		nothing
// Calls:		nothing 
//						
// Checks if the data is from 1 to 5 star, if not, throws error; else assigns passed 
// data to iterated object's rating.
//******************************************************************************************
void Gemstone::setRating(string r)
{
	if (!(r == "*" || r == "**" || r == "***" || r == "****" || r == "*****"))
		throw WrongRating();
	else
		rating = r;
}


								// ACCESSOR FUNCTIONS

//******************************************************************************************
// Name:		getID
// Called by:	printGemInfo
// Passed:		nothing
// Returns:		int
// Calls:		nothing 
//						
// Returns the id_number of the iterated object.
//******************************************************************************************
int Gemstone::getID() const
{
	return id_number;
}

//******************************************************************************************
// Name:		getName
// Called by:	printGemInfo
// Passed:		nothing
// Returns:		string
// Calls:		nothing 
//						
// Returns the name of the iterated object.
//******************************************************************************************
string Gemstone::getName() const
{
	return gem_name;
}

//******************************************************************************************
// Name:		getWeight
// Called by:	printGemInfo
// Passed:		nothing
// Returns:		float
// Calls:		nothing 
//						
// Returns the gem_weight of the iterated object.
//******************************************************************************************
float Gemstone::getWeight() const
{
	return gem_weight;
}

//******************************************************************************************
// Name:		getWeight
// Called by:	printGemInfo
// Passed:		nothing
// Returns:		float
// Calls:		nothing 
//						
// Returns the amt_paid of the iterated object.
//******************************************************************************************
float Gemstone::getAmtPaid() const
{
	return amt_paid;
}

//******************************************************************************************
// Name:		getRating
// Called by:	printGemInfo
// Passed:		nothing
// Returns:		string
// Calls:		nothing 
//						
// Returns the rating of the iterated object.
//******************************************************************************************
string Gemstone::getRating() const
{
	return rating;
}




								// RANDOM UTILITY FUNCTIONS

//******************************************************************************************
// Name:		printGemInfo
// Called by:	findMostExpensiveGem, printAllGems, searchGemByID
// Passed:		Gemstone
// Returns:		nothing
// Calls:		Gemstone Class: getID, getName, getWeight, getRating
//						
// Prints the member variables of the Gemstone passed. Locale will print the relative
// currency symbol of the operator system.
//******************************************************************************************
void Gemstone::printGemInfo(Gemstone &g)
{
	cout << "ID: " << g.getID() << endl;
	cout << "Name: " << g.getName() << endl;
	cout << "Gemstone weight: " << setprecision(2) << fixed << showpoint << g.getWeight() << endl;
	// Print out appropriate currency symbol
	cout.imbue(std::locale(""));
	cout << "Amount paid: " << showbase << put_money(g.getAmtPaid()*100) << endl; // Multiply by 100 because put_money's argument is in cents, or 1/100.
	cout << "Gem rating: " << g.getRating() << endl << endl;
}

//******************************************************************************************
// Name:		operator+
// Called by:	printAllGems
// Passed:		float
// Returns:		float
// Calls:		nothing
//						
// Returns the value of the amt_paid of the current iterated object plus the passed data
// which is the sum of all the element's amt_paid up to that point.
//******************************************************************************************
float Gemstone::operator+(const float &right)
{
	return amt_paid + right;
}

//******************************************************************************************
// Name:		operator>
// Called by:	findMostExpensiveGem
// Passed:		float
// Returns:		bool
// Calls:		nothing
//						
// If the amt_paid of the iterated object is greater than the passed data, then return true
// else return false;
//******************************************************************************************
bool Gemstone::operator>(const float &right)
{
	if (amt_paid > right)
		return true;
	else
		return false;

}

//******************************************************************************************
// Name:		checkUnique
// Called by:	setID
// Passed:		int, vector
// Returns:		bool
// Calls:		Gemstone class: getID
//						
// Checks if the input ID is unique: If vector is empty, returns true. If it exists
// return's false.
//******************************************************************************************
bool Gemstone::checkUnique(int n, vector<Gemstone>& g)
{
	if (g.size() == 0) // If there are no items in the vector, return true because there is no ID to check.
		return true;
	int tempID;
	for (int index = 0; index < g.size(); index++)
	{
		tempID = g[index].getID();
		if (n == tempID)
		{
			return false; // Return false value if name is not unique
		}
	}
	return true; // Return true if name IS unique
}

//******************************************************************************************
// Name:		searchGemById
// Called by:	searchGemstone
// Passed:		int, vector
// Returns:		bool
// Calls:		Gemstone class: printGemInfo
//						
// Takes passed gem_id and searches for a match in the vector. If found, passes that object
// to printGemInfo to display its data.
//******************************************************************************************
bool Gemstone::searchGemByID(int gem_id, vector<Gemstone>&g)
{
	Gemstone temp;
	vector<Gemstone>::iterator it;
	for (it = g.begin(); it != g.end(); it++)
	{
		if (gem_id == it->getID())
		{
			printGemInfo(*it); // Pass the found gem ID to be printed out
			return true;		// Return true if the gem was found.
		}
	}
	throw GemNotFound(); // If the gem wasn't found, throw error
}