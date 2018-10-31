#include <iostream>
using namespace std;

//Function prototypes
void traverseList();


struct ListNode
{
    int value;
    struct ListNode *next;
};
ListNode *head;

int main()
{
    traverseList();
    return 0;
}

//Function definitions

// Traversing the List
ListNode *nodePtr = head; // Assigns nodePtr to beginning of list

if (nodePtr != nullptr)
{
    nodePtr = nodePtr->next;
}