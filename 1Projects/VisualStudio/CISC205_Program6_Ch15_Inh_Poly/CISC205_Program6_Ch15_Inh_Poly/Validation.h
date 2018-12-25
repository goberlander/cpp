#pragma once

#include <iostream>
#include <string>
#include "Yacht.h"
#include <sstream>
#include <stdio.h>
using namespace std;

class Validation
{
public:
	Validation();
	~Validation();
	
	virtual string getValidName()
	{
		return "";
	}
	virtual bool isUniqueName(string, Yacht *[], int)
	{
		return true;
	}
	virtual float getValidLength()
	{
		return 0.0f;
	}
	virtual string getValidYear()
	{
		return "";
	}
	virtual int getValidNumberOfEngines()
	{
		return 0;
	}
	virtual float getValidHorsePower()
	{
		return 0.0f;
	}
	virtual float getValidSailArea()
	{
		return 0.0f;
	}
	
};

class HighLevelValidation : public Validation {
protected:
	string getValidName();
	bool isUniqueName(string, Yacht *[], int);
	float getValidLength();
	string getValidYear();
	int getValidNumberOfEngines();
	float getValidHorsePower();
	float getValidSailArea();
};

class LowLevelValidation : public Validation {
protected:	
	string getValidName();
	float getValidLength();
	string getValidYear();
	int getValidNumberOfEngines();
	float getValidHorsePower();
	float getValidSailArea();
};


