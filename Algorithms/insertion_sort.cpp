#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {

        int j = i - 1;
        int key = a[i];

        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int main()
{
    int a[] = {5, 4, 3, 2, 1};
    int n = sizeof(a) / sizeof(a[0]);

    insertion_sort(a, n);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}