#pragma once
class Surgery
{
private:
	float misleading_chest, all_fat_gone, knife_removal, hand_switch, super_brain;
public:
	Surgery();
	~Surgery();

	void surgeryChoice(int);
	//have stored within it the charges for at least five types
	//of surgery.It can update the charges variable of the PatientAccount class.
};

