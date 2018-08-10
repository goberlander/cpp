#include <iostream>
#include "LinkedList.h"
using namespace std;

void menu();

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
        cout << "Please choose an option...\n";
        cout << "1. Append\n" << "2. Display\n";
        cin >> choice;
        switch(choice)
        {
            case 1:
                cout << "What value do you want in the node? ";
                cin >> value;
                list.appendNode(value);
                break;
            case 2:
                list.displayList();
                break;
            case 3:
                cout << "Where do you want to insert the node?";
                cin >> pos;
                cout << "What value do you want the node to have?";
                cin >> value;
                list.insertNode(pos, value);
                break;
            default:
                exit(EXIT_FAILURE);
        }
    }
}