#include "pch.h"
#include "PatientAccount.h"
#include <iostream>
#include <string>

using namespace std;

// Static variables to keep track of values
float PatientAccount::total_surgery_charge = 0.0;
float PatientAccount::total_pharma_charge = 0.0;

PatientAccount::PatientAccount()
{
	surgery_charge = 0.0;
	pharma_charge = 0.0;
	total_surgery_charge = 0.0;
	total_pharma_charge = 0.0;
}
PatientAccount::~PatientAccount()
{}

void PatientAccount::addSurgeryCharge(float surgery_charge)
{
	total_surgery_charge += surgery_charge;
}
void PatientAccount::addPharmaCharge(float pharma_charge)
{
	total_pharma_charge += pharma_charge;
}

// Total cost for stay
float PatientAccount::getCostOfStay(int days)
{
	return 50 * days;
}

float PatientAccount::getPharmaCharge() const
{
	return total_pharma_charge;
}

float PatientAccount::getSurgeryCharge() const
{
	return total_surgery_charge;
}
