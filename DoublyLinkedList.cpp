//Doubly linked Link
//includes InsertAtHead(), InsertAtTail(), ForwardPrint() and ReversePrint()

#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head;
struct Node *tail;

struct Node *getNewNode(int x)
{
    //create a temp pointer to a new Node
    //a new Node will be created and stored in heap
    //temp is a local variable which will be deleted once the function is completed
    struct Node *newNodePtr = new Node;
    newNodePtr->data = x;
    newNodePtr->prev = NULL;
    newNodePtr->next = NULL;
    return newNodePtr;
}

void InsertAtHead(int x)
{
    struct Node *newNodePtr = getNewNode(x);
    if (head == NULL)
    {
        head = newNodePtr;
        return;
    }
    head->prev = newNodePtr;
    newNodePtr->next = head;
    head = newNodePtr;

    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    tail = temp;
}

void InsertAtTail(int x)
{
    struct Node *newNodePtr = getNewNode(x);
    if (tail == NULL)
    {
        tail = newNodePtr;
        return;
    }
    tail->next = newNodePtr;
    newNodePtr->prev = tail;
    tail = newNodePtr;

    struct Node *temp = tail;
    while (temp->prev != NULL)
    {
        temp = temp->prev;
    }
    head = temp;
}

void ForwardPrint(struct Node *p)
{
    if (p == NULL)
        return;
    printf("%d ", p->data);
    Print(p->next);
}

void ReversePrint(struct Node *p)
{
    struct Node *temp = tail;

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
}

int main()
{

    InsertAtHead(5);
    InsertAtHead(4);
    InsertAtHead(3);
    InsertAtHead(2);
    InsertAtHead(1);

    InsertAtTail(6);
    InsertAtTail(7);
    InsertAtTail(8);
    InsertAtTail(9);
    InsertAtTail(10);

    printf("\nPrint from head:\n");
    ForwardPrint(head);

    printf("\nReverse Print from tail: \n");
    ReversePrint(tail);
}