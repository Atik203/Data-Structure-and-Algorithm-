// Remove duplicates from an unsorted linked list
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

void remove_duplicates(Node *head)
{
    unordered_set<int> s;
    Node *curr = head;
    Node *prev = NULL;
    while (curr != NULL)
    {
        if (s.find(curr->data) != s.end())
        {
            prev->next = curr->next;
            delete (curr);
        }
        else
        {
            s.insert(curr->data);
            prev = curr;
        }
        curr = prev->next;
    }
}

void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(12);
    head->next->next = new Node(11);
    head->next->next->next = new Node(11);
    head->next->next->next->next = new Node(12);
    head->next->next->next->next->next = new Node(11);
    head->next->next->next->next->next->next = new Node(10);
    cout << "Linked list before removing duplicates" << endl;
    display(head);
    remove_duplicates(head);
    cout << endl;
    cout << "Linked list after removing duplicates" << endl;
    display(head);

    return 0;
}