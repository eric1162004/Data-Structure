//Code for a LinkedList

#include <cstdio>
#include <cstdlib>

//Set up a node structure
//a node contains two parts: data and next
struct Node
{
    int data;
    Node *next;
};

//create a head pointer
struct Node *head;

void Insert(int x)
{
    Node *temp = (Node *)malloc(sizeof(struct Node));
    //remember temp is simply a pointer to the new node, not the node itself
    (*temp).data = x;
    //same thing: temp -> data = x;
    (*temp).next = NULL;
    temp->next = head;
    //because head pointer was previously holding the addr of the next node
    head = temp;
}

void Print()
{
    Node *temp = head;
    printf("List is: \n");
    while (temp != NULL)
    {
        printf(" %d", temp->data);
        temp = temp->next;
    }
}

int main()
{
    head = NULL;
    printf("How many numbers?\n");
    int n, i, x;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nEnter the number \n");
        scanf("%d", &x);
        Insert(x);
        Print();
    }
}
