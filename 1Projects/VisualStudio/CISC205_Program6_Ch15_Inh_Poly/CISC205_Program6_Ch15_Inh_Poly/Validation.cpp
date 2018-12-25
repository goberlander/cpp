#include "pch.h"
#include "Validation.h"
#include "Yacht.h"

Validation::Validation()
{
	//string name = "";
}
Validation::~Validation()
{
}


// HIGH LEVEL VALIDATION - ALL OF THESE WILL RETURN ERROR MESSAGES AND CONTINUE TO PROMPT USER IF DATA IS INVALID

//******************************************************************************************
// Name:		getValidName
// Called by:	addNewYacht, addNewPowerboat, addNewSailboat
// Passed:		nothing
// Returns:		string
// Calls:		no one
//				
// This will get a valid name and return the string.
//******************************************************************************************
string HighLevelValidation::getValidName()
{
	string input;
	bool validInput = true;
	do
	{
		validInput = true;
		getline(cin, input);

		// Validates if the entry is too long or blank
		if (input.length() >= 20 || input.empty())
		{
			cout << "Too long or empty: ";
			validInput = false;
		}
		// If passed above checks, make sure only letters and no punctuation
		if (validInput)
		{
			for (int i = 0; i < input.length(); i++)
			{
				// Check for silly spacing
				if (input[0] == ' ' || (input[i] == ' ' && input[i + 1] == ' '))
				{
					cout << "Wonky spacing. Don't do that: ";
					validInput = false;
					break;
				}
				if (!(isalpha(input[i])) && !(isspace(input[i])))
				{
					cout << "Only letters please: ";
					validInput = false;
					break;
				}
				else
					validInput = true;
			}
		}
	} while (!validInput);
	return input;
}

//******************************************************************************************
// Name:		isUniqueName
// Called by:	addNewYacht, addNewPowerboat, addNewSailboat
// Passed:		name to check, array of object pointers, current boat count
// Returns:		bool
// Calls:		getBoatName
//				
// Checks if the name is unique and not already in the array of objects.
//******************************************************************************************
bool HighLevelValidation::isUniqueName(string name, Yacht *b[], int count)
{
	bool unique = true;
	for (int i = 0; i < count; i++)
	{
		if (name == b[i]->getBoatName())
		{
			cout << "That name already exists. Try again: ";
			unique = false;
			return unique;
		}
		else
			unique = true;
	}
	return unique;
}

//******************************************************************************************
// Name:		getValidLength
// Called by:	addNewYacht
// Passed:		nothing
// Returns:		float
// Calls:		no one
//				
// This will get a valid length and return the float.
//******************************************************************************************
float HighLevelValidation::getValidLength()
{
	{
		// Need to check why it's not validating if value is less than 0. Feedback from homework.
		bool validFloat = true;
		float value = 0.0;
		string floatString = "";
		do
		{
			validFloat = true;	// To reset the flag
			getline(cin, floatString);

			// If it's empty, give error
			if (floatString.empty())
			{
				cout << "Please don't submit an empty input: ";
				validFloat = false;
			}
			// Check for only floats
			for (int i = 0; i < floatString.size(); i++)
			{
				if ((!isdigit(floatString[i])) && floatString[i] != '.')
				{
					cout << "Please enter only a float value: ";
					validFloat = false;
					break;
				}
				else
					validFloat = true;
			}
			if (validFloat)
			{
				value = stof(floatString);
				if (value <= 0)
				{
					cout << "Please enter a value greater than 0: ";
					validFloat = false;
				}
			}
		} while (!validFloat);
		return value;
	}
}

//******************************************************************************************
// Name:		getValidYear
// Called by:	addNewYacht
// Passed:		nothing
// Returns:		string
// Calls:		no one
//				
// This will get a valid year and return the string
//******************************************************************************************
string HighLevelValidation::getValidYear()
{
	string input;
	bool validInput = true;
	do
	{
		validInput = true;
		getline(cin, input);

		// Validates if the entry is too long or blank
		if (input.length() > 4 || input.empty())
		{
			cout << "Too long or empty: ";
			validInput = false;
		}
		// If passed above checks, make sure only letters and no punctuation
		if (validInput)
		{
			for (int i = 0; i < input.length(); i++)
			{
				// Check for silly spacing
				if (input[0] == ' ' || (input[i] == ' ' && input[i + 1] == ' '))
				{
					cout << "Wonky spacing. Don't do that: ";
					validInput = false;
					break;
				}
				if (!(isdigit(input[i])) && !(isspace(input[i])))
				{
					cout << "Only numbers please: ";
					validInput = false;
					break;
				}
				else
					validInput = true;
			}
		}
	} while (!validInput);
	return input;
}

//******************************************************************************************
// Name:		getValidNumberOfEngines
// Called by:	addNewPowerboat
// Passed:		nothing
// Returns:		int
// Calls:		no one
//				
// This will get a valid number of engines as a string and return it as an integer
//******************************************************************************************
int HighLevelValidation::getValidNumberOfEngines()
{
	string input;
	int result;
	bool validInput = true;
	do
	{
		validInput = true;
		getline(cin, input);

		// Validates if the entry is too long or blank
		if (input.length() > 2 || input.empty())
		{
			cout << "Too long or empty: ";
			validInput = false;
		}
		// If passed above checks, make sure only letters and no punctuation
		if (validInput)
		{
			for (int i = 0; i < input.length(); i++)
			{
				// Check for silly spacing
				if (input[0] == ' ' || (input[i] == ' ' && input[i + 1] == ' '))
				{
					cout << "Wonky spacing. Don't do that: ";
					validInput = false;
					break;
				}
				if (!(isdigit(input[i])) && !(isspace(input[i])))
				{
					cout << "Only numbers please: ";
					validInput = false;
					break;
				}
				else
					validInput = true;
			}
			// Convert to int and check that greater than 0.
			if (validInput)
			{
				result = stoi(input);
				if (result > 0)
					validInput = true;
				else
				{
					cout << "You have to have at least one to be a powerboat silly!";
					validInput = false;
				}
			}
		}
	} while (!validInput);
	return result;
}

//******************************************************************************************
// Name:		getValidHorsePower
// Called by:	addNewPowerboat
// Passed:		nothing
// Returns:		float
// Calls:		no one
//				
// This will get a valid horsepower as a string and return it as an float
//******************************************************************************************
float HighLevelValidation::getValidHorsePower()
{
	// Need to check why it's not validating if value is less than 0. Feedback from homework.
	bool validFloat = true;
	float value = 0.0;
	string floatString = "";
	do
	{
		validFloat = true;	// To reset the flag
		getline(cin, floatString);

		// If it's empty, give error
		if (floatString.empty())
		{
			cout << "Please don't submit an empty input: ";
			validFloat = false;
		}
		// Check for only floats
		for (int i = 0; i < floatString.size(); i++)
		{
			if ((!isdigit(floatString[i])) && floatString[i] != '.')
			{
				cout << "Please enter only a float value: ";
				validFloat = false;
				break;
			}
			else
				validFloat = true;
		}
		if (validFloat)
		{
			value = stof(floatString);
			if (value <= 0)
			{
				cout << "Please enter a value greater than 0: ";
				validFloat = false;
			}
			else
				return value;
		}
	} while (!validFloat);
	return value;
}

//******************************************************************************************
// Name:		getValidSailArea
// Called by:	addNewSailboat
// Passed:		nothing
// Returns:		float
// Calls:		no one
//				
// This will get a valid sail boat area as a string and return it as an float
//******************************************************************************************
float HighLevelValidation::getValidSailArea()
{
	bool validFloat = true;
	float value = 0.0;
	string floatString = "";
	do
	{
		validFloat = true;	// To reset the flag
		getline(cin, floatString);

		// If it's empty, give error
		if (floatString.empty())
		{
			cout << "Please don't submit an empty input: ";
			validFloat = false;
		}
		// Check for only floats
		for (int i = 0; i < floatString.size(); i++)
		{
			if ((!isdigit(floatString[i])) && floatString[i] != '.')
			{
				cout << "Please enter only a float value: ";
				validFloat = false;
				break;
			}
			else
				validFloat = true;
		}
		// convert string to float and check if greater than 0.
		if (validFloat)
		{
			value = stof(floatString);
			if (value <= 0)
			{
				cout << "Please enter a value greater than 0: ";
				validFloat = false;
			}
			else
				return value;
		}
	} while (!validFloat);
	return value;
}


// LOW LEVEL VALIDATION - ALL OF THESE WILL RETURN ERROR MESSAGES AND EXIT THE PROGRAM IF DATA IS INVALID

//******************************************************************************************
// Name:		getValidName
// Called by:	addNewYacht, addNewPowerboat, addNewSailboat
// Passed:		nothing
// Returns:		string
// Calls:		no one
//				
// This will get a valid name and return the string.
//******************************************************************************************
string LowLevelValidation::getValidName()
{
	string input;
	bool validInput = true;
	do
	{
		validInput = true;
		getline(cin, input);

		// Validates if the entry is too long or blank
		if (input.length() >= 20 || input.empty())
		{
			cout << "Too long or empty.";
			exit(EXIT_FAILURE);
		}
		// If passed above checks, make sure only letters and no punctuation
		if (validInput)
		{
			for (int i = 0; i < input.length(); i++)
			{
				// Check for silly spacing
				if (input[0] == ' ' || (input[i] == ' ' && input[i + 1] == ' '))
				{
					cout << "Wonky spacing. Don't do that.";
					exit(EXIT_FAILURE);
					break;
				}
				// Check for only letters
				if (!(isalpha(input[i])) && !(isspace(input[i])))
				{
					cout << "Only letters please.";
					exit(EXIT_FAILURE);
					break;
				}
				else
					validInput = true;
			}
		}
	} while (!validInput);
	return input;
}

//******************************************************************************************
// Name:		getValidLength
// Called by:	addNewYacht
// Passed:		nothing
// Returns:		float
// Calls:		no one
//				
// This will get a valid length and return the float.
//******************************************************************************************
float LowLevelValidation::getValidLength()
{
	{
		// Need to check why it's not validating if value is less than 0. Feedback from homework.
		bool validFloat = true;
		float value = 0.0;
		string floatString = "";
		do
		{
			validFloat = true;	// To reset the flag
			getline(cin, floatString);

			// If it's empty, give error
			if (floatString.empty())
			{
				cout << "Please don't submit an empty input.";
				exit(EXIT_FAILURE);
			}
			// Check for only floats
			for (int i = 0; i < floatString.size(); i++)
			{
				if ((!isdigit(floatString[i])) && floatString[i] != '.')
				{
					cout << "Please enter only a float value.";
					exit(EXIT_FAILURE);
					break;
				}
				else
					validFloat = true;
			}
			// Convert to float and check that is greater than 0.
			if (validFloat)
			{
				value = stof(floatString);
				if (value <= 0)
				{
					cout << "Please enter a value greater than 0.";
					exit(EXIT_FAILURE);
				}
			}
		} while (!validFloat);
		return value;
	}
}

//******************************************************************************************
// Name:		getValidYear
// Called by:	addNewYacht
// Passed:		nothing
// Returns:		string
// Calls:		no one
//				
// This will get a valid year and return the string
//******************************************************************************************
string LowLevelValidation::getValidYear()
{
	string input;
	bool validInput = true;
	do
	{
		validInput = true;
		getline(cin, input);

		// Validates if the entry is too long or blank
		if (input.length() != 4 || input.empty())
		{
			cout << "Needs to be 4 numbers long, or submitted an empty line.";
			exit(EXIT_FAILURE);
		}
		// Make sure only letters and no punctuation or weird spacing
		if (validInput)
		{
			for (int i = 0; i < input.length(); i++)
			{
				// Check for silly spacing
				if (input[0] == ' ' || (input[i] == ' ' && input[i + 1] == ' '))
				{
					cout << "Wonky spacing. Don't do that.";
					exit(EXIT_FAILURE);
					break;
				}
				if (!(isdigit(input[i])) && !(isspace(input[i])))
				{
					cout << "Only numbers please.";
					exit(EXIT_FAILURE);
					break;
				}
				else
					validInput = true;
			}
		}
	} while (!validInput);
	return input;
}

//******************************************************************************************
// Name:		getValidNumberOfEngines
// Called by:	addNewPowerboat
// Passed:		nothing
// Returns:		int
// Calls:		no one
//				
// This will get a valid number of engines as a string and return it as an integer
//******************************************************************************************
int LowLevelValidation::getValidNumberOfEngines()
{
	string input;
	int result;
	bool validInput = true;
	do
	{
		validInput = true;
		getline(cin, input);

		// Validates if the entry is too long or blank
		if (input.length() > 2 || input.empty())
		{
			cout << "Too long or empty.";
			exit(EXIT_FAILURE);
		}

		// If passed above checks, make sure only letters and no punctuation
		if (validInput)
		{
			for (int i = 0; i < input.length(); i++)
			{
				// Check for silly spacing
				if (input[0] == ' ' || (input[i] == ' ' && input[i + 1] == ' '))
				{
					cout << "Wonky spacing. Don't do that.";
					exit(EXIT_FAILURE);
					break;
				}
				// Check if only numbers
				if (!(isdigit(input[i])) && !(isspace(input[i])))
				{
					cout << "Only numbers please.";
					exit(EXIT_FAILURE);
					break;
				}
				else
					validInput = true;
			}
			// Convert to integer if all passed for final check.
			if (validInput)
			{
				result = stoi(input);
				if (result > 0)
					validInput = true;
				else
				{
					cout << "You have to have at least one to be a powerboat silly!";
					exit(EXIT_FAILURE);
				}
			}
		}
	} while (!validInput);
	return result;
}

//******************************************************************************************
// Name:		getValidHorsePower
// Called by:	addNewPowerboat
// Passed:		nothing
// Returns:		float
// Calls:		no one
//				
// This will get a valid horsepower as a string and return it as an float
//******************************************************************************************
float LowLevelValidation::getValidHorsePower()
{
	// Need to check why it's not validating if value is less than 0. Feedback from homework.
	bool validFloat = true;
	float value = 0.0;
	string floatString = "";
	do
	{
		validFloat = true;	// To reset the flag
		getline(cin, floatString);

		// If it's empty, give error
		if (floatString.empty())
		{
			cout << "Please don't submit an empty input.";
			exit(EXIT_FAILURE);
		}
		// Check for only floats
		for (int i = 0; i < floatString.size(); i++)
		{
			if ((!isdigit(floatString[i])) && floatString[i] != '.')
			{
				cout << "Please enter only a float value.";
				exit(EXIT_FAILURE);
				break;
			}
			else
				validFloat = true;
		}
		if (validFloat)
		{
			value = stof(floatString);
			if (value <= 0)
			{
				cout << "Please enter a value greater than 0.";
				exit(EXIT_FAILURE);
			}
			else
				return value;
		}
	} while (!validFloat);
	return value;
}

//******************************************************************************************
// Name:		getValidSailArea
// Called by:	addNewSailboat
// Passed:		nothing
// Returns:		float
// Calls:		no one
//				
// This will get a valid sail boat area as a string and return it as an float
//******************************************************************************************
float LowLevelValidation::getValidSailArea()
{
	bool validFloat = true;
	float value = 0.0;
	string floatString = "";
	do
	{
		validFloat = true;	// To reset the flag
		getline(cin, floatString);

		// If it's empty, give error
		if (floatString.empty())
		{
			cout << "Please don't submit an empty input.";
			exit(EXIT_FAILURE);
		}
		// Check for only floats
		for (int i = 0; i < floatString.size(); i++)
		{
			if ((!isdigit(floatString[i])) && floatString[i] != '.')
			{
				cout << "Please enter only a float value.";
				exit(EXIT_FAILURE);
				break;
			}
			else
				validFloat = true;
		}
		// convert to float and make sure greater than 0
		if (validFloat)
		{
			value = stof(floatString);
			if (value <= 0)
			{
				cout << "Please enter a value greater than 0.";
				exit(EXIT_FAILURE);
			}
			else
				return value;
		}
	} while (!validFloat);
	return value;
}