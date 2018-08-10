#include <iostream>
#include "LinkedList.h"
using namespace std;

void LinkedList::appendNode(int v)
{
    
    ListNode *nodePtr; // Create a pointer to traverse the list; assigns to the beginning of list.
    // All components needed to create a new node.
    ListNode *newNode = new ListNode; // Allocates memory for the node
    newNode->next = nullptr; // Since I am adding a node to the end of the list, this signifies the end.
    newNode->value = v; // Assigns whatever value is passed to the data member of the node.

    // If there is no nodes in the list, make this newNode the head of the list.
    if(!head)
        head = newNode;
    else // Iterate until you find the end.
    {
        nodePtr = head;
        // While the nodePtr next still has a value, keep iterating.
        while(nodePtr->next)
            nodePtr = nodePtr->next;
        // If nodePtr->next is a null value, assign it the newNode.
        nodePtr->next = newNode;
    }
}

void LinkedList::displayList()
{
    ListNode *nodePtr = head;

    while(nodePtr)
    {
        cout << nodePtr->value << endl;
        nodePtr = nodePtr->next;
    }
}

void LinkedList::insertNode(int p, int v)
{
    ListNode *nodePtr;
    ListNode *previousNode = nullptr;


    ListNode *newNode = new ListNode;
    newNode->value = v;
    newNode->next = nodePtr->next;

    if(!head)
        newNode = 

    // Iterate to find the value.
    // Once found, assign the node at position to the next node, and the node before to prevoius node, then assign inserted node to nodePtr.
}