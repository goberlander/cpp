/* 
Program Name: Better Chance For Lightning Strike
Author: Glenn Oberlander
Date: 4.6.2018
*/

/* This program will prompt user for input, validate if input is an integer, and call
a linear search algorithm to check if the users input is in the array of lottery numbers*/


#include <iostream>
#include <string>
#include <sstream>
#include <cstring> //gives you strlen in the std namespace, while #include<string.h> will give it to you in global namespace
using namespace std;

int ticketArray[10] = {13579, 26791, 26792, 33445, 55555, 62483, 77777, 79422, 85647, 93121};
bool linearSearch(int ticketArray[10], int ticketNumber);
string input = ""; // Holds the input
int ticketNumber;

void validateInput();


int main()
{
	// Also prompts
	validateInput();
	
	// If linear search finds the value, they win, if not, they lose.
	if(linearSearch(ticketArray, ticketNumber) == true)
		cout << "You win!\n";
	else
		cout << "You lose!\n";
}

bool linearSearch(int ticketArray[10], int ticketNumber)
{
	for(int i = 0; i < 10; i++)
	{
		if(ticketArray[i] == ticketNumber)
		{
			return true;
		}
	}
	return false;
}

void validateInput()
{
	// Declines input if not an integer
	while(true)
	{
		cout << "Enter your 5-digit lucky number!\n";
		getline(cin, input);
		stringstream ticketStream(input);
		if(ticketStream >> ticketNumber)
			break;
		cout << "Needs to be a number.\n";			
	}
	if(input.size() != 5)
	{
		cout << "Your input is either too long or too short.\n";
		validateInput();
	}
}
