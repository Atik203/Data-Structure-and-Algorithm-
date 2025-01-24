
#include <bits/stdc++.h>
using namespace std;

int q[100], front = -1, rear = -1;

void enqueue(int x)
{
    if (rear == 99)
    {
        cout << "Queue is full\n";
        return;
    }
    if (front == -1)
        front = 0;
    rear++;
    q[rear] = x;
}

void dequeue()
{
    if (front == -1)
    {
        cout << "Queue is empty\n";
        return;
    }
    front++;
    if (front > rear)
        front = rear = -1;
}

int peek()
{
    if (front == -1)
    {
        cout << "Queue is empty\n";
        return -1;
    }
    return q[front];
}

bool isEmpty()
{
    if (front == -1)
        return true;
    return false;
}

void display()
{
    if (front == -1)
    {
        cout << "Queue is empty\n";
        return;
    }
    for (int i = front; i <= rear; i++)
        cout << q[i] << " ";
    cout << endl;
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    display();

    return 0;
}