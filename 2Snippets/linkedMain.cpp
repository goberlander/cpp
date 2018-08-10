#include <iostream>
#include "linkedLists.h"
using namespace std;

int main()
{
    NumberList list;

    // Appending values to list
    list.appendNode(12.7);
    list.appendNode(5.8);
    list.appendNode(3.4);

    // Display the values in the list
    list.displayList();
    return 0;
}