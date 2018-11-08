#include "pch.h"
#include "Surgery.h"
#include "PatientAccount.h"


Surgery::Surgery()
{
	misleading_chest = 9500.00, 
	all_fat_gone = 300.00, 
	knife_removal = 1.00, 
	hand_switch = 90001.00, 
	super_brain = 1000000;
}


Surgery::~Surgery()
{
}

void Surgery::surgeryChoice(int choice)
{
	PatientAccount pa;
	switch (choice)
	{
	case 1:
		pa.addSurgeryCharge(all_fat_gone);
		break;
	case 2: // Edit the address
		pa.addSurgeryCharge(knife_removal);
		break;
	case 3: // edit the phone
		pa.addSurgeryCharge(misleading_chest);
		break;
	case 4: // Add a surgical charge 
		pa.addSurgeryCharge(super_brain);
		break;
	case 5: // Add a pharma charge
		pa.addSurgeryCharge(hand_switch);
		break;
	case 6: // Return to previous menu
		break;
	default:
		break;
	}
}