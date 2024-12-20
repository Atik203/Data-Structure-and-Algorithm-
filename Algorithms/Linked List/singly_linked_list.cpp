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
void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}

void insert_at_head(Node *&head, int value)
{
    Node *new_node = new Node(value);
    new_node->next = head;
    head = new_node;
}

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

    return 0;
}