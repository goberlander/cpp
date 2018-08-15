#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class LinkedList
{
    private: 
        struct ListNode
        {
            int value;
            ListNode *next;
        };
        ListNode *head;
        int numOfNodes;

        
    public:
        LinkedList()
            {
                head = nullptr;
                numOfNodes = 0;
            } // Once the list is created, assigning this to null is important because it signifies that the list is empty.
        //~LinkedList();

        void appendNode(int);
        void displayList();
        int insertNode(int, int);
        
};
#endif