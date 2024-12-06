#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool flag = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                flag = true;
            }
            if (!flag)
            {
                break;
            }
        }
    }
}

int main()
{
    int a[5] = {5, 4, 3, 2, 1};
    int n = sizeof(a) / sizeof(a[0]);

    bubble_sort(a, n);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}