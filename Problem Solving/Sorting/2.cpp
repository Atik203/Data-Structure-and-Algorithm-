#include <bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int> &a)
{
    int n = a.size();
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    insertion_sort(a);

    // median  if n is odd then n/2th element is median else n/2th and n/2-1th element average is median

    if (n % 2 == 0)
    {
        int median = (a[n / 2] + a[n / 2 - 1]) / 2;
        cout << median << endl;
    }
    else
    {
        cout << a[n / 2] << endl;
    }

    return 0;
}