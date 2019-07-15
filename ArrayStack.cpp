#include <stdio.h>
#define MAX_SIZE 3

int array[MAX_SIZE];
int top = -1;

void Push(int x)
{
    if (top == MAX_SIZE - 1)
    {
        printf("stack overflow\n");
        return;
    }
    array[++top] = x;
}

void Pop()
{
    if (top == -1)
    {
        printf("No element to pop\n");
        return;
    }
    top--;
}

int Top()
{
    return array[top];
}

void Print()
{
    int i;
    printf("Stack: \n");
    for (i = 0; i <= top; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main()
{
    Push(2);
    Print();
    Push(3);
    Print();
    Push(4);
    Print();

    //StackOverFlow
    Push(5);

    //Remove one element
    Pop();

    Push(5);
    Print();
}