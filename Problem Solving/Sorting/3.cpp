#include <bits/stdc++.h>
using namespace std;

// Find the kth smallest difference element from an array.

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
            j--;
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
        cin >> a[i];

    insertion_sort(a);

    vector<int> diff;
    for (int i = 0; i < n - 1; i++)
        diff.push_back(a[i + 1] - a[i]);

    insertion_sort(diff);

    cout << diff[0] << endl;

    return 0;
}