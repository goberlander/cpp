#include "pch.h"
#include "Yacht.h"


Yacht::Yacht()
{
	name = "";
	length = 0.0;
	year_built = "";
}


Yacht::~Yacht()
{
}

void Yacht::setYachtName(string n)
{
	name = n;
}
//void Yacht::setYachtLength(float l)
//{
//
//}
