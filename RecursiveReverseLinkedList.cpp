//Reverse a linked list using recursion

#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;

void recursiveReverse(struct Node *p)
{
    if (p->next == NULL)
    {
        head = p;
        return;
    }
    recursiveReverse(p->next);
    struct Node *q = p->next;
    q->next = p;
    p->next = NULL;
}

void recursivePrint(struct Node *p)
{
    if (p == NULL)
        return;
    printf("%d ", p->data);
    recursivePrint(p->next);
}

struct Node *Insert(Node *head, int data)
{
    struct Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
        head = newNode;
    else
    {
        Node *temp1 = head;
        while (temp1->next != NULL)
            temp1 = temp1->next;
        temp1->next = newNode;
    }
    return head;
}

int main()
{
    head = Insert(head, 2);
    head = Insert(head, 3);
    head = Insert(head, 4);
    head = Insert(head, 5);
    recursivePrint(head);

    recursiveReverse(head);
    printf("\nReverse list: \n");
    recursivePrint(head);
}