#include <bits/stdc++.h>
using namespace std;
// stack using linked list

class Node
{
public:
    int data;
    Node *next;
};

Node *top = NULL;

void push(int val)
{
    Node *newNode = new Node();
    newNode->data = val;
    newNode->next = top;
    top = newNode;
}

void pop()
{
    if (top == NULL)
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        cout << "The popped element is " << top->data << endl;
        top = top->next;
    }
}

void display()
{
    if (top == NULL)
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        Node *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int peek()
{
    if (top == NULL)
    {
        cout << "Stack is empty" << endl;
        return 0;
    }
    else
    {
        return top->data;
    }
}

int main()
{
    push(10);
    push(20);
    push(30);
    display();
    cout << "Top element is " << peek() << endl;
    pop();
    display();
    cout << "Top element is " << peek() << endl;

    return 0;
}