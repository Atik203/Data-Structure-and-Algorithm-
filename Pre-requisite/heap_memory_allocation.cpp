#include <bits/stdc++.h>
using namespace std;

int main()
{
    // For heap memory allocation we can't use the normal variable declaration. we have to use the pointer variable.
    int *p;
    p = new int[3]; // This will allocate the memory in heap memory.

    // for 'C language' we use malloc() function to allocate the memory in heap memory.
    // p = (int *) malloc(sizeof(int)*3);

    p[0] = 10;
    p[1] = 20;
    p[2] = 30;

    for (int i = 0; i < 3; i++)
    {
        cout << p[i] << endl;
    }

    // To delete the memory allocated in heap memory we use 'delete' keyword.
    delete[] p;

    // in 'C language' we use 'free()' function to delete the memory allocated in heap memory.
    // free(p);
}