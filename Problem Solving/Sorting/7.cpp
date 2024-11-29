#include <bits/stdc++.h>
using namespace std;
// Find the Longest Consecutive Subsequence after sorting an array.

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

    selection_sort(a);

    // Find the longest consecutive subsequence

    int max_length = 1;
    int current_length = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == a[i - 1] + 1)
        {
            current_length++;
        }
        else if (a[i] != a[i - 1])
        {
            max_length = max(max_length, current_length);
            current_length = 1;
        }
    }

    max_length = max(max_length, current_length);

    cout << max_length << endl;

    return 0;
}