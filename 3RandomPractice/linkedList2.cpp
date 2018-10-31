#include <iostream>
using namespace std;

class LinkedList
{
private:
    struct ListNode
    {
        int value;
        ListNode *next;
    };
    ListNode *head;
public:
    LinkedList()
    {head = nullptr;}

    ~LinkedList();
   
    void appendNode(int);
    void insertNode(int)
}

//Function prototypes

int main()
{
    
    return 0;
}

//Function definitions
void LinkedList::appendNode(int num)
{
    ListNode *newNode;
    ListNode *nodePtr;

    newNode = new ListNode;
    // These occur after creating a newNode.
    newNode->value = num;
    newNode->next = nullptr;

    if (!head)
    {
        head = newNode;
    }
    else   // Iterate to end of the list, add node to list
    {
        nodePtr = head;
        while(nodePtr->next)
        {
            nodePtr = nodePtr->next;
        }

        nodePtr->next = newNode;
    }
}

void LinkedList::instertNode(int num)
{
    /* Traverse the list to location via nodePtr
    To not break the chainAssign previousNode->next to nodePtr
    node point to newNode, and nodePtr->
}