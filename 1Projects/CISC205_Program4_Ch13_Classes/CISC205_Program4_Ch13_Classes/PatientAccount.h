#pragma once
#ifndef PATIENTACCOUNT_H
#define PATIENTACCOUNT_H

//  - Will keep a total of the patient’s charges. 
//	- It will also keep track of the number of days spent in the hospital.
//  - The group must decide on the hospital’s daily rate.
#include <iostream>
using namespace std;

class PatientAccount
{
private:
	static int totalDays;
	float surgery_charge, pharma_charge;
	static float total_surgery_charge;
	static float total_pharma_charge;
public:
	// Initialize members
	PatientAccount();
	~PatientAccount();
	void addSurgeryCharge(float);
	void addPharmaCharge(float);

	float getCostOfStay(int days);
	float getSurgeryCharge() const;
	float getPharmaCharge() const;
	
};
#endif