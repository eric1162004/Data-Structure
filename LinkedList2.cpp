#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;

void Print()
{
    //note that temp is a local variable
    struct Node *temp = head;

    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

void Insert(int data, int atPosition)
{
    struct Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    if (atPosition == 1)
    {
        newNode->next = head;
        head = newNode;
        return;
    }
    //inserting nodes at n th positon
    struct Node *previousNode = head;
    for (int i = 1; i < atPosition - 1; i++)
    {
        previousNode = previousNode->next;
    }
    //must first save the link to the next node
    //then link the previous node to the new node
    newNode->next = previousNode->next;
    previousNode->next = newNode;
}

int main()
{
    head = NULL;

    Insert(2, 1);
    Print();
    Insert(3, 1);
    Print();
    Insert(4, 2);
    Print();
    Insert(5, 2);
    Print();
}