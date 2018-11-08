#pragma once
#pragma once

#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <string>
using namespace std;

class Patient
{
private:
	int ID;
	string name, address, phone;
	static float total_surgery_charges;
	static float total_pharma_charges;

public:
	// Initialize members
	Patient();
	// Initialize with passed data (if adding new patient)
	Patient(int newID, string newName, string newAddress, string newPhone);
	
	void setID(int patientID);
	void setName(string patientName);
	void setAddress(string patientAddress);
	void setPhone(string patientPhone);

	void addSurgicalCharge(float);
	float getTotalSurgical();

	int getID() const
	{ return ID; }
	string getName() const
	{ return name; }
	string getAddress() const
	{ return address; }
	string getPhone() const
	{ return phone; }
	int checkID() const
	{ return ID; }

	~Patient();
};
#endif