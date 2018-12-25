// Specificaiton file for Menu class
#ifndef Menu_H
#define Menu_H
#include <string>
using namespace std;
class Menu
{
private:
	//Variable to hold user choice for switch
	int choice;
public:
	//Menu operations
	int display_Menu();
	bool validate_Int(string);
	bool validate_IntMenu(string);
	void display_Exit();
	void display_Error();
};
#endif 

