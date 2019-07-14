#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;

//insert an integer at the end of list
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

//print all elements in the list
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

//Delete node at position n
void Delete(int n)
{
    //recall head is a pointer to the 1st node
    struct Node *temp1 = head;

    if (n == 1)
    {
        head = temp1->next;
        free(temp1);
        return;
    }

    int i;
    //go up to the previous node
    for (i = 0; i < n - 2; i++)
        //deference old temp1 and set the value to the new temp1
        temp1 = temp1->next;
    struct Node *temp2 = temp1->next;
    temp1->next = temp2->next;
    //free memory of the deleting node
    free(temp2);
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

    int positionToDelete;
    while (positionToDelete > 0)
    {
        printf("Enter a postion or 0 to quit\n");
        scanf("%d", &positionToDelete);
        Delete(positionToDelete);
        Print();
    }
}
