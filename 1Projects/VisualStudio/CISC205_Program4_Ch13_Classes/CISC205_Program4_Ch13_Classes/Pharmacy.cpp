#include "pch.h"
#include "Pharmacy.h"
#include "PatientAccount.h"


Pharmacy::Pharmacy()
{
	aspirin = 50.00;
	morphine = .99;
	cureall = 500.59;
	notroubles = 77777.777;
	forgetnot = 11111.111;
}


Pharmacy::~Pharmacy()
{
}

float Pharmacy::medicineChoice(int choice)
{
	PatientAccount pa;
	switch (choice)
	{
	case 1:
		pa.addPharmaCharge(aspirin);
		//return aspirin;
		break;
	case 2: // Edit the address
		pa.addPharmaCharge(morphine);
		//return morphine;
		break;
	case 3: // edit the phone
		pa.addPharmaCharge(cureall);
		//return cureall;
		break;
	case 4: // Add a surgical charge 
		pa.addPharmaCharge(notroubles);
		//return notroubles;
		break;
	case 5: // Add a pharma charge
		pa.addPharmaCharge(forgetnot);
		return forgetnot;
		break;
	case 6: // Return to previous menu
		break;
	default:
		break;
	}
}
