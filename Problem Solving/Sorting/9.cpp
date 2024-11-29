#include <bits/stdc++.h>
using namespace std;
// You are given two arrays a and b. Merge a and b into a single array
// sorted in non - decreasing order.

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

vector<int> merge_arrays(vector<int> &a, vector<int> &b)
{
    vector<int> result;
    int i = 0, j = 0;
    int n = a.size(), m = b.size();

    // Sort the input arrays first
    selection_sort(a);
    selection_sort(b);

    // Merge the two sorted arrays
    while (i < n && j < m)
    {
        if (a[i] <= b[j])
        {
            result.push_back(a[i]);
            i++;
        }
        else
        {
            result.push_back(b[j]);
            j++;
        }
    }

    // Add remaining elements of a
    while (i < n)
    {
        result.push_back(a[i]);
        i++;
    }

    // Add remaining elements of b
    while (j < m)
    {
        result.push_back(b[j]);
        j++;
    }

    return result;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < m; i++)
        cin >> b[i];

    vector<int> result = merge_arrays(a, b);

    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";

    return 0;
}