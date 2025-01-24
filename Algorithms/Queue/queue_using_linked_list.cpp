#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

Node *front = NULL;
Node *rear = NULL;

void enqueue(int val)
{
    Node *newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;
    if (front == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue()
{
    if (front == NULL)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "The dequeued element is " << front->data << endl;
        Node *temp = front;
        front = front->next;
        delete temp;
    }
}

int peek()
{
    if (front == NULL)
    {
        cout << "Queue is empty" << endl;
        return 0;
    }
    else
    {
        return front->data;
    }
}

bool isEmpty()
{
    if (front == NULL)
        return true;
    return false;
}

void display()
{
    if (front == NULL)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        Node *temp = front;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    display();
    dequeue();
    display();

    return 0;
}