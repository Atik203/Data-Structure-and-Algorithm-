#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node(int value)
    {
        this->value = value;
        this->next = NULL;
    }
};

// Function to calculate the size of the linked list
int size(Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

// Function to print the linked list
void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to insert a node at the head of the linked list
void insert_at_head(Node *&head, int value)
{
    Node *new_node = new Node(value);
    new_node->next = head;
    head = new_node;
}

// Function to insert a node at the tail of the linked list
void insert_at_tail(Node *&head, int value)
{
    Node *new_node = new Node(value);
    if (head == NULL)
    {
        head = new_node;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Function to insert a node at a specific position in the linked list
void insert_at_position(Node *&head, int value, int position)
{
    if (position < 0 || position > size(head))
    {
        cout << "Invalid position" << endl;
        return;
    }
    if (position == 0)
    {
        insert_at_head(head, value);
        return;
    }
    if (position == size(head))
    {
        insert_at_tail(head, value);
        return;
    }
    Node *new_node = new Node(value);
    Node *temp = head;
    for (int i = 0; i < position - 1; i++)
    {
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

// Function to search for a key in the linked list
void search(Node *head, int key)
{
    int pos = 0;
    while (head != NULL)
    {
        if (head->value == key)
        {
            cout << "Element found at position " << pos << endl;
            return;
        }
        pos++;
        head = head->next;
    }
    cout << "Element not found" << endl;
}

// Function to insert a node after a specific element in the linked list
void insert_after_element(Node *&head, int key, int value)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->value == key)
        {
            Node *new_node = new Node(value);
            new_node->next = temp->next;
            temp->next = new_node;
            return;
        }
        temp = temp->next;
    }
    cout << "Element not found" << endl;
}

// Function to insert a node before a specific element in the linked list
void insert_before_element(Node *&head, int key, int value)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    if (head->value == key)
    {
        insert_at_head(head, value);
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->value == key)
        {
            Node *new_node = new Node(value);
            new_node->next = temp->next;
            temp->next = new_node;
            return;
        }
        temp = temp->next;
    }
    cout << "Element not found" << endl;
}

// Function to delete the head node of the linked list
void delete_at_head(Node *&head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
}

// Function to delete the tail node of the linked list
void delete_at_tail(Node *&head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }
    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}

// Function to delete a node at a specific position in the linked list
void delete_at_position(Node *&head, int position)
{
    if (position < 0 || position >= size(head))
    {
        cout << "Invalid position" << endl;
        return;
    }
    if (position == 0)
    {
        delete_at_head(head);
        return;
    }
    if (position == size(head) - 1)
    {
        delete_at_tail(head);
        return;
    }
    Node *temp = head;
    for (int i = 0; i < position - 1; i++)
    {
        temp = temp->next;
    }
    Node *temp1 = temp->next;
    temp->next = temp1->next;
    delete temp1;
}

// Function to delete a node by value in the linked list
void delete_by_value(Node *&head, int key)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    if (head->value == key)
    {
        delete_at_head(head);
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->value == key)
        {
            Node *temp1 = temp->next;
            temp->next = temp1->next;
            delete temp1;
            return;
        }
        temp = temp->next;
    }
    cout << "Element not found" << endl;
}

// Function to reverse the linked list
void reverse(Node *&head)
{
    Node *prev = NULL;
    Node *current = head;
    Node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

int main()
{
    Node *head = new Node(10);
    insert_at_tail(head, 20);
    insert_at_head(head, 5);
    insert_at_position(head, 15, 2);
    print(head);
    delete_at_position(head, 2);
    print(head);
    delete_by_value(head, 20);
    print(head);
    reverse(head);
    print(head);
    return 0;
}