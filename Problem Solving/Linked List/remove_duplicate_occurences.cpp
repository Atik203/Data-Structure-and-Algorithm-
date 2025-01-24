#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

// Function to remove all occurrences of duplicates from a sorted linked list
void removeAllDuplicates(Node *&head)
{
    if (head == NULL)
        return;

    Node *dummy = new Node(0); // Create a dummy node to handle edge cases
    dummy->next = head;
    Node *prev = dummy;
    Node *current = head;

    while (current != NULL)
    {
        bool isDuplicate = false;
        // Check for duplicates
        while (current->next != NULL && current->data == current->next->data)
        {
            isDuplicate = true;
            Node *temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
        if (isDuplicate)
        {
            Node *temp = current;
            prev->next = current->next;
            current = current->next;
            delete temp;
        }
        else
        {
            prev = current;
            current = current->next;
        }
    }

    head = dummy->next;
    delete dummy;
}

// Function to display the linked list
void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(1);
    head->next->next = new Node(2);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(3);
    head->next->next->next->next->next = new Node(3);
    head->next->next->next->next->next->next = new Node(4);

    cout << "Original list: ";
    display(head);

    removeAllDuplicates(head);

    cout << "List after removing duplicates: ";
    display(head);

    return 0;
}