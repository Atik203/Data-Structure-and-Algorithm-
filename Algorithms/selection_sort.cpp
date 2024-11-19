#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n); // or int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // selection sort

    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min_index])
            {
                min_index = j;
            }
        }
        swap(a[i], a[min_index]);
    }

    // print the sorted array

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}