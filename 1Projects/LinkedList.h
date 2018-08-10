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
    public:
        LinkedList()
            {head = nullptr;} // Once the list is created, assigning this to null is important because it signifies that the list is empty.
        //~LinkedList();

        void appendNode(int);
        void displayList();
        void insertNode(int, int);
};
#endif