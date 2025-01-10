#include <bits/stdc++.h>
using namespace std;

// stack with singly linked list using insertion at tail and deletion from tail

class Node
{
public:
    int data;
    Node *next;
};
Node *top = NULL;
Node *tail = NULL;

void push(int val)
{
    Node *newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;
    if (tail == NULL)
    {
        top = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

void pop()
{
    if (top == NULL)
    {
        cout << "Stack Underflow" << endl;
    }
    else if (top == tail)
    {
        cout << "The popped element is " << top->data << endl;
        delete top;
        top = NULL;
        tail = NULL;
    }
    else
    {
        Node *temp = top;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        cout << "The popped element is " << tail->data << endl;
        delete tail;
        tail = temp;
        tail->next = NULL;
    }
}
void displayReverse(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    displayReverse(node->next);
    cout << node->data << " ";
}
void display2()
{
    if (top == NULL)
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        displayReverse(top);
        cout << endl;
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
    if (tail == NULL)
    {
        cout << "Stack is empty" << endl;
        return 0;
    }
    else
    {
        return tail->data;
    }
}

int main()
{
    push(10);
    push(20);
    push(30);
    display2();
    cout << "Top element is " << peek() << endl;
    pop();
    display2();
    cout << "Top element is " << peek() << endl;
    return 0;
}