#include <bits/stdc++.h>
using namespace std;

class Stack
{
    queue<int> q1;
    queue<int> q2;
    int n;

public:
    Stack()
    {
        n = 0;
    }
    void push(int val)
    {
        q2.push(val);
        n++;
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }
    void pop()
    {
        if (q1.empty())
        {
            cout << "Stack is empty" << endl;
            return;
        }
        q1.pop();
        n--;
    }
    int top()
    {
        if (q1.empty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return q1.front();
    }
    int size()
    {
        return n;
    }
    bool empty()
    {
        return n == 0;
    }

    void display()
    {
        queue<int> temp = q1;
        while (!temp.empty())
        {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};
int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.display();

    return 0;
}