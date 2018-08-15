#include <iostream>
#include "LinkedList.h"
using namespace std;

void LinkedList::appendNode(int value)
{
    ListNode *nodePtr; // Create a pointer to traverse the list; assigns to the beginning of list.
    
    // All components needed to create a new node.
    ListNode *newNode = new ListNode; // Allocates memory for the node
    newNode->next = nullptr; // Since I am adding a node to the end of the list, this signifies the end.
    newNode->value = value; // Assigns whatever value is passed to the data member of the node.

    // If there is no nodes in the list, make this newNode the head of the list.
    if(!head)
    {
        head = newNode;
        numOfNodes++;
    }
       
    else // Iterate until you find the end.
    {
        nodePtr = head;
        // While the nodePtr next still has a value, keep iterating.
        while(nodePtr->next)
            nodePtr = nodePtr->next;
        // If nodePtr->next is a null value, assign it the newNode.
        nodePtr->next = newNode;
        numOfNodes++; // increases the value of node count
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

int LinkedList::insertNode(int pos, int v)
{
    // Create tools for newNode
    ListNode *nodePtr;
    ListNode *previousNode = nullptr;
    int i;

    // Create memory for a new node of data.
    ListNode *newNode = new ListNode;
    newNode->value = v;
    newNode->next = nodePtr->next;

    // If list is empty, assign this new node to the first of the list
    if(head == nullptr)
        return -1;
    if (pos > numOfNodes)
        return -2;
    else 
    { 
        nodePtr = head; // start node at front of list

        // Iterate to insert position
        while (nodePtr != nullptr && i <= pos)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
            i++;
        }
        previousNode->next = newNode;
        newNode->next = nodePtr; 
    }
    return 0;
}