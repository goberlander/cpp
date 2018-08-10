#include <iostream>
#include "linkedLists.h"
using namespace std;

// This will add a node to the end of the list
void NumberList::appendNode(double num)
{
    ListNode* newNode; // To point to a new node
    ListNode* nodePtr; // To move through the list (traversing) This holds the current node that is being pointed to.

    // Allocate a new node and store nullptr there.
    newNode = new ListNode; // Dynamically allocates a new node in memory of the ListNode type
    newNode->value = num; // Assigns num to value member variable (in linkedLists.h)
    newNode->next = nullptr; // Assigns nullptr to the next node (because you don't want it pointing to garbage).

    //If there are no nodes in the list, make newNode the first node.
    if(!head) // head is being accessed from the linkedLists.h file
        head = newNode;
    else // Otherwise, if head does not point to nullptr, it means there are nodes in the list--find the last node to append newNode to.
    {
        // Initialize nodePtr to head of list
        nodePtr = head;

        // Find the last node in the list
        while(nodePtr->next) // While this is true. Assign the next ptr to the current pointer.
            nodePtr = nodePtr->next; 

        // Insert newNode as the last node.
        nodePtr->next = newNode;
    }
}

/* PSEUDOCODE
Assign List head to node pointer. 
While node pointer is not null
    Display the value member of the node pointed to by node pointer.
    Assign node pointer to its own next member. 
End While. */

void NumberList::displayList() const
{
    ListNode* nodePtr;
    nodePtr = head;
    while(nodePtr) 
    {// while this is not null (which is true. Got it. nodePtr will point to null once it reaches the end of the list.)
        cout << nodePtr->value << endl;

        // Move to next node
        nodePtr = nodePtr->next;
    }
}

/* void NumberList::insertNode(double num)
{

}
void NumberList::deleteNode(double num)
{

} */