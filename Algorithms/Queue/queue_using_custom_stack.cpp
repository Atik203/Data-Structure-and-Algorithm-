#include <bits/stdc++.h>
using namespace std;

// Custom Stack class
class Stack
{
private:
    int *arr;
    int top;
    int capacity;

public:
    Stack(int size = 1000)
    {
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    ~Stack()
    {
        delete[] arr;
    }

    void push(int x)
    {
        if (top == capacity - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = x;
    }

    int pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return arr[top--];
    }

    int peek()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty()
    {
        return top == -1;
    }

    int size()
    {
        return top + 1;
    }
};

// Queue class using two stacks
class Queue
{
private:
    Stack s1;
    Stack s2;

public:
    void enqueue(int x)
    {
        s1.push(x);
    }

    int dequeue()
    {
        if (s1.isEmpty() && s2.isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        if (s2.isEmpty())
        {
            while (!s1.isEmpty())
            {
                s2.push(s1.pop());
            }
        }
        return s2.pop();
    }

    bool empty()
    {
        return s1.isEmpty() && s2.isEmpty();
    }

    int size()
    {
        return s1.size() + s2.size();
    }

    int front()
    {
        if (s1.isEmpty() && s2.isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        if (s2.isEmpty())
        {
            while (!s1.isEmpty())
            {
                s2.push(s1.pop());
            }
        }
        return s2.peek();
    }

    int rear()
    {
        if (s1.isEmpty() && s2.isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        if (s1.isEmpty())
        {
            while (!s2.isEmpty())
            {
                s1.push(s2.pop());
            }
        }
        return s1.peek();
    }

    void display()
    {
        if (s1.isEmpty() && s2.isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        if (s2.isEmpty())
        {
            while (!s1.isEmpty())
            {
                s2.push(s1.pop());
            }
        }
        Stack temp = s2;
        while (!temp.isEmpty())
        {
            cout << temp.pop() << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.display();
    cout << q.dequeue() << endl;
    q.display();
    return 0;
}