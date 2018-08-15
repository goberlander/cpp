#include <iostream>
#include "LinkedList.h"
#include <limits>
using namespace std;

void menu();
int validateInput();

int main()
{
    menu();
}

void menu()
{
    LinkedList list;
    int choice;
    int value;
    int pos;

    while(true)
    {
        cout 
        << "1. Append\n" 
        << "2. Display\n"
        << "3. Insert\n"
        << "4. Reverse\n"
        << "5. Search\n";
        cout << "Please choose a menu option...\n";
        choice = validateInput();
        switch(choice)
        {
            case 1:
                cout << "What value do you want in the node? ";
                value = validateInput();
                list.appendNode(value);
                break;
            case 2:
                list.displayList();
                break;
            case 3:
                cout << "Where do you want to insert the node? ";
                cin >> pos;
                cout << "What value do you want the node to have? ";
                value = validateInput();
                if(list.insertNode(pos, value) == -1)
                    cout << "The list is empty, please append a node first.\n";
                if(list.insertNode(pos, value) == -2)
                    cout << "That is greater than the # of nodes in the list.\n;";
                break;
            default:
                exit(EXIT_FAILURE);
        }
    }
}

int validateInput()
{
    int input;
    // While the input is not an int
    while (!(cin >> input)) 
    {
        cout << "Inavlid input, please try again.\n";
        cin.clear(); // Clears the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore all characters up to new line character.
    }
    return input;
}