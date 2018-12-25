//Implementation file for the Menu class
#include "Menu.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// ********************************************************
// functionName: display_Menu                             *
// called by:    main                                     *
// passed:       nothing                                  *
// returns:      none                                     *
// calls:        none                                     *
//                                                        *
// The display function will print out the menu prompts to* 
// the console. It will also provide a way to users to    *
// enter input. The input will be validated as well.      *
// ********************************************************
int Menu::display_Menu()
{
	string a;
	int a1;
	// Choice will always be uninitialized unless method uses a reference to change value permanantely to use in switch
	cout << "Here is the menu: " << endl;
	cout << "1. Insert Numbers" << endl;
	cout << "2. Display the Tree" << endl;
	cout << "3. Display Leaf Count" << endl;
	cout << "4. Display Tree Height" << endl;
	cout << "5. Display Tree Width" << endl;
	cout << "6. Exit" << endl;
	cout << "Please choose an option: ";
	cin >> a;

	while (validate_IntMenu(a) == false)
	{

		cout << "\nSorry, that choice is invalid. Please try again.\n" << endl;
		cout << "Here is the menu: " << endl;
		cout << "1. Insert Numbers" << endl;
		cout << "2. Display the Tree" << endl;
		cout << "3. Display Leaf Count" << endl;
		cout << "4. Display Tree Height" << endl;
		cout << "5. Display Tree Width" << endl;
		cout << "6. Exit" << endl;
		cout << "Please choose an option: ";
		cin >> a;
	}
	a1 = stoi(a);
	return a1;
}

// ********************************************************
// functionName: validate_IntMenu                         *
// called by:    getPushInput                             *
// passed:       string                                   *
// returns:      bool                                     *
// calls:        none                                     *
//                                                        *
// The validate_IntMenu function will loop through the    *
// string paramter anc check if each character is an      *
// integer. It will return false if not an integer. It    *
// will exit the program as well. Returns true if         *
// parameter is an int. Specific to menu input handling.  * 
// ********************************************************
bool Menu::validate_IntMenu(string s)
{
	// String is an array of characters 
	// Loop through input and verify each character is an integer
	for (int i = 0; i < s.length(); i++)
	{
		//If integer not found, accepts integers that are negative as well
		if (!isdigit(s[i]) == true)
		{
			return false;
		}
	}
	return true;
}


// ********************************************************
// functionName: validate_Int                             *
// called by:    getPushInput                             *
// passed:       string                                   *
// returns:      bool                                     *
// calls:        none                                     *
//                                                        *
// The validate_Int function will loop thorugh the string *
// paramter anc check if each character is a number. It   *
// will return false if not an integer. It will exit the  *
// program as well. Returns true if parameter is an int.  * 
// ********************************************************
bool Menu::validate_Int(string s)
{
	// String is an array of characters 
	// Loop through input and verify each character is an integer
	for (int i = 0; i < s.length(); i++)
	{
		//If integer not found, accepts integers that are negative as well
		if ((!isdigit(s[i]) == true) && (s[0] != '-'))
		{
			cout << "\nSorry, the input must be a INTEGER." << endl;
			cout << "\n...Program Malfunction. PLEASE RESTART.\n" << endl;
			exit(EXIT_FAILURE);
			return false;
		}
	}
	return true;
}

// ********************************************************
// functionName: display_Exit                             *
// called by:    main                                     *
// passed:       nothing                                  *
// returns:      nothing                                  *
// calls:        none                                     *
//                                                        *
// The display_Exit function will display the a message   *
// when the user exits the program.                       * 
// ********************************************************
void Menu::display_Exit()
{
	cout << "\nThanks for using the Tree Creator!" << endl;
	cout << "GoodBye.\n" << endl;

}

// ********************************************************
// functionName: display_Error                            *
// called by:    main                                     *
// passed:       nothing                                  *
// returns:      nothing                                  *
// calls:        none                                     *
//                                                        *
// The display_Error function will display a message if   *
// the wrong choice is inputted.                          *
// ********************************************************
void Menu::display_Error()
{
	cout << "\nSorry, that choice is invalid. Please try again.\n" << endl;
}