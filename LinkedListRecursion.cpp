//Print elements of a linked list in forward and reverse order using recursion

#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

void Print(struct Node *p)
{
    if (p == NULL)
        return;
    printf("%d ", p->data);
    Print(p->next);
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
    struct Node *head = NULL;
    head = Insert(head, 2);
    Print(head);
    printf("\n");
    head = Insert(head, 3);
    Print(head);
    printf("\n");
    head = Insert(head, 4);
    Print(head);
    printf("\n");
    head = Insert(head, 5);
    Print(head);
    printf("\n");
}