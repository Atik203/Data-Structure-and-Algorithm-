#include <bits/stdc++.h>
using namespace std;
//  linked list is palindrome or not
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

bool isPalindrome(Node *head)
{
    Node *current = head;
    stack<int> s;
    while (current != NULL)
    {
        s.push(current->data);
        current = current->next;
    }
    while (head != NULL)
    {
        int i = s.top();
        s.pop();
        if (head->data != i)
        {
            return false;
        }
        head = head->next;
    }
    return true;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);
    cout << isPalindrome(head) << endl;

    return 0;
}