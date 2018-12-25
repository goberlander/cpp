#pragma once
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Yacht
{
protected:
	string name;
	float length;
	string year_built;
public:
	Yacht();
	Yacht(string n, float l, string y)
	{
		name = n;
		length = l;
		year_built = y;
	}
	~Yacht();

	void setBoatName(string);
	void setYachtLength(float);
	void setYearBuilt(string);
	virtual void printBoats();

	string getBoatName()
	{
		return name;
	}
	float getBoatLength()
	{
		return length;
	}
	string getYearBuilt()
	{
		return year_built;
	}
};

class Powerboat : public Yacht
{
public:
	int number_of_engines;  //(int > 0)
	float total_horsepower; //(float > 0)
	Powerboat() {
		number_of_engines = 0;
		total_horsepower = 0.0;
	}
	Powerboat(string n, float e, float th)
	{
		name = n;
		number_of_engines = e;
		total_horsepower = th;
	}
	~Powerboat() {}
	
	void setNumberOfEngines(int);
	int getNumberOfEngines();
	void setTotalHorsePower(float);
	float getTotalHorsePower();
	void printBoats();
};

class Sailboat : public Yacht
{
public:
	float sail_area;
	Sailboat() 
	{
		sail_area = 0.0;
	}
	Sailboat(string n, float sa)
	{
		name = n;
		sail_area = sa;
	}
	~Sailboat() {}
	
	void setSailArea(float area);
	float getSailArea();
	void printBoats();
};

