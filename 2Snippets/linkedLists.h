#ifndef LINKEDLISTS_H
#define LINKEDLISTS_H
#include <iostream>
using namespace std;

class NumberList
{
    private: 
        struct ListNode
        {
            double value;
            struct ListNode* next; // Not sure why I have to use "struct" in this declaration.
        };
        ListNode* head; // The node at the beginning of the list
        // *Note: this is declared in the private access specification
    public:
        // Constructor
        NumberList()
        { head = 0;} // initializes each instance of a node to nullptr
        
        // Destructor
        //~NumberList(); // Will destroy all nodes in the list.

        // Linked list operations
        void appendNode(double);
        /* void insertNode(double);
        void deleteNode(double); */
        void displayList() const;
};
#endif