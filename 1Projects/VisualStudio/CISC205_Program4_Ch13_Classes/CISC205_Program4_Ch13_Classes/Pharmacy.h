#pragma once
class Pharmacy
{
private:
	float aspirin, morphine, cureall, notroubles, forgetnot;
public:
	Pharmacy();
	~Pharmacy();
	float medicineChoice(int days);
	// price of at least five types of medication. It will update the charges variable of the PatientAccount class.
};

