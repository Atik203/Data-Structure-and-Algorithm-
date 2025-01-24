#include <iostream>
using namespace std;

// Custom Queue class
class Queue
{
private:
    int *arr;
    int front;
    int rear;
    int capacity;
    int count;

public:
    Queue(int size = 1000)
    {
        arr = new int[size];
        capacity = size;
        front = 0;
        rear = -1;
        count = 0;
    }

    ~Queue() // Destructor to free memory allocated to the array
    {
        delete[] arr;
    }

    void enqueue(int x)
    {
        if (count == capacity)
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = x;
        count++;
    }

    int dequeue()
    {
        if (count == 0)
        {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        int x = arr[front];
        front = (front + 1) % capacity;
        count--;
        return x;
    }

    int peek()
    {
        if (count == 0)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    bool isEmpty()
    {
        return count == 0;
    }

    int size()
    {
        return count;
    }
};

// Stack class using two queues
class Stack
{
private:
    Queue q1;
    Queue q2;

public:
    void push(int x)
    {
        q2.enqueue(x);
        while (!q1.isEmpty())
        {
            q2.enqueue(q1.dequeue());
        }
        swap(q1, q2);
    }

    int pop()
    {
        if (q1.isEmpty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return q1.dequeue();
    }

    int top()
    {
        if (q1.isEmpty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return q1.peek();
    }

    bool isEmpty()
    {
        return q1.isEmpty();
    }

    int size()
    {
        return q1.size();
    }

    void display()
    {
        Queue temp = q1;
        while (!temp.isEmpty())
        {
            cout << temp.dequeue() << " ";
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
    s.push(4);
    s.display();
    cout << s.pop() << endl;
    s.display();
    return 0;
}