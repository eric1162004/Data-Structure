// Circular ArrayQueue

#include <iostream>
#include <stdio.h>
#include <string>
#define MAX_SIZE 10
using namespace std;

class Queue
{
private:
    int array[MAX_SIZE];
    int front;
    int rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    bool isEmpty()
    {
        return (front == -1 && rear == -1);
    }

    bool isFull()
    {
        return ((rear + 1) % MAX_SIZE == front ? true : false);
    }

    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "Queue is full.\n";
            return;
        }
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAX_SIZE;
        }
        array[rear] = x;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty.\n";
            return;
        }
        else if (front == rear)
        {
            front = rear = -1;
            return;
        }
        else
        {
            front = (front + 1) % MAX_SIZE;
        }
    }

    int getfront()
    {
        if (front == -1)
        {
            cout << "the queue is empty \n";
            return -1;
        }
        return array[front];
    }

    void Print()
    {
        if (front == -1)
        {
            cout << "Quene is empty. \n";
            return;
        }

        int count = (rear + MAX_SIZE - front) % MAX_SIZE + 1;
        cout << "Queue: ";
        for (int i = 0; i < count; i++)
        {
            int index = (front + i) % MAX_SIZE;
            cout << array[index] << " ";
        }
        cout << "\n";
    }
};

int main()
{
    Queue q;
    q.Print();

    q.enqueue(1);
    q.Print();
    q.enqueue(2);
    q.Print();
    q.enqueue(3);
    q.Print();
    q.enqueue(4);
    q.Print();

    q.dequeue();
    q.Print();
    q.dequeue();
    q.Print();
    q.dequeue();
    q.Print();
    q.dequeue();
    q.Print();
}
