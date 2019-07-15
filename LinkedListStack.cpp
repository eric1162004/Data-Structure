//Linked List Stack

#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *link;
};

struct Node *top = NULL;

void Push(int x)
{
    struct Node *newNode = new Node;
    newNode->data = x;
    newNode->link = top;
    top = newNode;
}

void Pop()
{
    struct Node *temp = top;
    if (top == NULL)
        return;
    top = top->link;
    free(temp);
}

int isEmpty()
{
    if (top == NULL)
        return 1;
    return 0;
}

void PrintStack()
{
    struct Node *temp = top;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main()
{
    Push(1);
    Push(2);
    Push(3);
    PrintStack();

    Pop();
    PrintStack();
}
