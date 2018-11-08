#include "pch.h"
#include "Patient.h"
#include <iostream>
#include <string>

using namespace std;

Patient::~Patient()
{

}

void Patient::setID(int patientID)
{
	ID = patientID;
}
void Patient::setName(string patientName)
{
	name = patientName;
}
void Patient::setAddress(string patientAddress)
{
	address = patientAddress;
}
void Patient::setPhone(string patientPhone)
{
	phone = patientPhone;
}