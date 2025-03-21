#include <bits/stdc++.h>
using namespace std;
// stack using array

int stk[100], n = 100, top = -1;

void push(int val)
{
    if (top >= n - 1)
    {
        cout << "Stack Overflow" << endl;
    }
    else
    {
        top++;
        stk[top] = val;
    }
}

void pop()
{
    if (top <= -1)
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        cout << "The popped element is " << stk[top] << endl;
        top--;
    }
}

bool isEmpty()
{
    if (top <= -1)
        return true;
    return false;
}

void display()
{
    if (top >= 0)
    {
        cout << "Stack elements are:";
        for (int i = top; i >= 0; i--)
        {
            cout << stk[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Stack is empty" << endl;
    }
}
int peek()
{
    if (top < 0)
    {
        cout << "Stack is empty" << endl;
        return 0;
    }
    else
    {
        return stk[top];
    }
}

int main()
{
    int ch, val;
    cout << "1) Push in stack" << endl;
    cout << "2) Pop from stack" << endl;
    cout << "3) Display stack" << endl;
    cout << "4) Peek" << endl;
    cout << "5) Exit" << endl;

    while (1)
    {
        cout << "Enter choice: " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter value to be pushed:" << endl;
            cin >> val;
            push(val);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            cout << "The top element is " << peek() << endl;
            break;
        case 5:
            exit(0);
            break;
        default:
            cout << "Invalid Choice" << endl;
        }
    }

    return 0;
}