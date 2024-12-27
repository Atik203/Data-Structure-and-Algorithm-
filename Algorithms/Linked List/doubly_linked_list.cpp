#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node *prev;
    Node(int value)
    {
        this->value = value;
        this->next = NULL;
        this->prev = NULL;
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
    if (head == NULL)
    {
        head = new_node;
        return;
    }
    head->prev = new_node;
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
    new_node->prev = temp;
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
    new_node->prev = temp;
    temp->next->prev = new_node;
    temp->next = new_node;
}

void delete_by_value(Node *&head, int value)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    if (head->value == value)
    {
        delete_at_head(head);
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->value == value)
        {
            Node *to_delete = temp->next;
            temp->next = temp->next->next;
            if (temp->next != NULL)
            {
                temp->next->prev = temp;
            }
            delete to_delete;
            return;
        }
        temp = temp->next;
    }
    cout << "Element not found" << endl;
}

void delete_at_head(Node *&head)
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
    head = head->next;
    head->prev = NULL;
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
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    delete temp;
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
    for (int i = 0; i < position; i++)
    {
        temp = temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
}

void reverse(Node *&head)
{
    Node *temp = NULL;
    Node *current = head;
    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL)
    {
        head = temp->prev;
    }
}

void search(Node *head, int key)
{
    int position = 0;
    while (head != NULL)
    {
        if (head->value == key)
        {
            cout << "Element found at position " << position << endl;
            return;
        }
        head = head->next;
        position++;
    }
    cout << "Element not found" << endl;
}

void insert_after_element(Node *&head, int element, int value)
{
    Node *new_node = new Node(value);
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->value == element)
        {
            new_node->next = temp->next;
            new_node->prev = temp;
            if (temp->next != NULL)
            {
                temp->next->prev = new_node;
            }
            temp->next = new_node;
            return;
        }
        temp = temp->next;
    }
    cout << "Element not found" << endl;
}

void insert_before_element(Node *&head, int element, int value)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    if (head->value == element)
    {
        insert_at_head(head, value);
        return;
    }
    Node *new_node = new Node(value);
    Node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->value == element)
        {
            new_node->next = temp->next;
            new_node->prev = temp;
            temp->next->prev = new_node;
            temp->next = new_node;
            return;
        }
        temp = temp->next;
    }
    cout << "Element not found" << endl;
}

int main()
{
    Node *head = new Node(10);
    insert_at_tail(head, 20);
    insert_at_tail(head, 30);
    insert_at_position(head, 25, 2);

    print(head);

    reverse(head);

    print(head);

    return 0;
}