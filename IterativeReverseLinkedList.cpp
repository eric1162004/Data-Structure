//Reverse a linked list - Iterative method

#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;

void Reverse()
{
    struct Node *current, *prev, *next;
    current = head;
    prev = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
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

    struct Node *previousNode = head;
    for (int i = 1; i < atPosition - 1; i++)
    {
        previousNode = previousNode->next;
    }

    newNode->next = previousNode->next;
    previousNode->next = newNode;
}

void Print()
{
    struct Node *temp = head;

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    head = NULL; //empty list

    Insert(11, 1);
    Insert(22, 2);
    Insert(33, 3);
    Insert(44, 4);
    Insert(55, 5); //List: 2,3,4,5
    Print();

    Reverse();
    printf("List in reverse:\n");
    Print();
}
