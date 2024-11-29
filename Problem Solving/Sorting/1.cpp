#include <bits/stdc++.h>
using namespace std;

// Find the kth smallest element from an array.

void selection_sort(vector<int> &a)
{
    int n = a.size();
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
    int k;
    cin >> k;

    selection_sort(a);

    cout << a[k - 1] << endl;
    return 0;
}