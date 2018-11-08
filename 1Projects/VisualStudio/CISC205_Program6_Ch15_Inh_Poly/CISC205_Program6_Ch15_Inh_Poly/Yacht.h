#pragma once
#include <string>
#include <iostream>
using namespace std;

class Yacht
{
private:
	string name;
	float length;
	string year_built;
public:
	Yacht();
	~Yacht();

	void setYachtName(string);
	//void setYachtLength(float);
	//void setYearBuilt(string)

	string getYachtName()
	{
		return name;
	}

};

