#include "pch.h"
#include "Patient.h"
#include <iostream>
#include <string>

using namespace std;

float Patient::total_surgery_charges = 0.0;

// When new object created, initialize values
Patient::Patient()
{
	ID = 0;
	name, address, phone = "";
}

// Initialize with passed data (if adding new patient)
Patient::Patient(int newID, string newName, string newAddress, string newPhone)
{
	ID = newID;
	name = newName;
	address = newAddress;
	phone = newPhone;
}
// Destructor
Patient::~Patient()
{}

//******************************************************************************************
// Name:		setID
// Called by:	addNewPatient
// Passed:		int
// Returns:		nothing
// Calls:		nothing
// 
// Validates and sets the ID to current iteration of Patient object, else exits
//******************************************************************************************
void Patient::setID(int patientID)
{
	if (patientID >= 0)
	{
		ID = patientID;
	}
	else
		exit(EXIT_FAILURE);
}

//******************************************************************************************
// Name:		setName
// Called by:	addNewPatient, editPatient
// Passed:		string
// Returns:		nothing
// Calls:		nothing
// 
// Validates and sets the name to current iteration of Patient object, else exits
//******************************************************************************************
void Patient::setName(string patientName)
{
	if (patientName.length() < 25)
	{
		name = patientName;
	}
	else
		exit(EXIT_FAILURE);
}

//******************************************************************************************
// Name:		setAddress
// Called by:	addNewPatient, editPatient
// Passed:		string
// Returns:		nothing
// Calls:		nothing
// 
// Validates and sets the address to current iteration of Patient object, else exits
//******************************************************************************************
void Patient::setAddress(string patientAddress)
{
	// If length less than 50 chars, assign
	if (patientAddress.length() < 50)
	{
		address = patientAddress;
	}
	else
		exit(EXIT_FAILURE);
}

//******************************************************************************************
// Name:		setPhone
// Called by:	addNewPatient, editPatient
// Passed:		string
// Returns:		nothing
// Calls:		nothing
// 
// Validates and sets the phone number to the current iteration of the Patient class, else
// exits
//******************************************************************************************
void Patient::setPhone(string patientPhone)
{
	if (patientPhone.length() < 11)
	{
		phone = patientPhone;
	}
	else
		exit(EXIT_FAILURE);
}

//******************************************************************************************
// Name:		addSurgicalCharge
// Called by:	addToSurgery
// Passed:		string
// Returns:		nothing
// Calls:		nothing
// 
// Validates and adds surgical input to the total surgery charges, else exits
//******************************************************************************************
void Patient::addSurgicalCharge(float charge)
{
	if (charge >= 0)
	{
		total_surgery_charges += charge;
	}
	else
		exit(EXIT_FAILURE);
}

//******************************************************************************************
// Name:		getTotalSurgical
// Called by:	displayPatientInfo
// Passed:		nothing
// Returns:		float
// Calls:		nothing
// 
// Returns the total surgery charges
//******************************************************************************************
float Patient::getTotalSurgical()
{
	return total_surgery_charges;
}