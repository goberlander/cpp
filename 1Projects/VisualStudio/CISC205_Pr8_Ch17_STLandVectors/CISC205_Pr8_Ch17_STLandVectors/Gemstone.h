/*
* Glenn Oberlander
* CISC205 - Object Oriented Programming with C++
* Program 8 for Chapter 17: Using the Standard Template Library
* Due : December 13th, 2018
*
*	- This is the specification file for the Gemstone. 
*	- It uses exception throws for low level input validation.
*	- Private Member variables for each Gemstone: ID, name, weight, cost, and rating
*
*/

#pragma once
#include <string>
#include <vector>
using namespace std;

class Gemstone
{
private:
	int id_number;
	string gem_name;
	float gem_weight;
	float amt_paid;
	string rating;
public:
	Gemstone();
	//Gemstone(int, string, float, float, string); // Uncomment if want to test program.
	~Gemstone();

// EXCEPTION THROWERS
	class WrongID {};		// Object to throw if wrong ID.
	class NotUnique {};		// If not unique
	class WrongName {};		// Name is too long
	class WrongFloat {};	// <= 0
	class WrongRating {};	// Not proper star rating
	class GemNotFound {};	// Couldn't find the gem
	

// MUTATOR FUNCTIONS
	void setID(int, vector<Gemstone>&);
	void setName(string);
	void setWeight(float);
	void setAmtPaid(float);
	void setRating(string);
	void printGemInfo(Gemstone &);
	

// ACCESSOR FUNCTIONS
	int getID() const;
	string getName() const;
	float getWeight() const;
	float getAmtPaid() const;
	string getRating() const;


// RANDOM UTILITY FUNCTIONS
	bool checkUnique(int, vector<Gemstone>&);
	bool searchGemByID(int, vector<Gemstone>&);
	float operator+(const float&);
	bool operator>(const float&);
};


