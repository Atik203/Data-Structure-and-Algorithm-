#include <bits/stdc++.h>
using namespace std;

// Node class to represent each element in the queue
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

// Function to add an element to the queue
void enqueue(int val)
{
    Node *newNode = new Node(val);
    if (front == NULL && rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

// Function to remove an element from the queue
void dequeue()
{
    if (front == NULL)
    {
        cout << "Queue is empty" << endl;
        return;
    }
    Node *temp = front;
    cout << "The dequeued element is " << front->data << endl;
    front = front->next;
    if (front == NULL)
    {
        rear = NULL;
    }
    delete temp;
}

// Function to get the front element of the queue
int peek()
{
    if (front == NULL)
    {
        cout << "Queue is empty" << endl;
        return -1;
    }
    return front->data;
}

// Function to check if the queue is empty
bool isEmpty()
{
    return front == NULL;
}

// Function to display the elements of the queue
void display()
{
    Node *temp = front;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    dequeue();
    dequeue();
    dequeue(); // Attempt to dequeue from an empty queue
    display();
    return 0;
}