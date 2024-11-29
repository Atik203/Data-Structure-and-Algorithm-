#include <bits/stdc++.h>
using namespace std;

// Sort an Array of Strings according to length.

void insertion_sort(vector<string> &a)
{
    int n = a.size();
    for (int i = 1; i < n; i++)
    {
        string key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j].length() > key.length())
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    insertion_sort(a);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}