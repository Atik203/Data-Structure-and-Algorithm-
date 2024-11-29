#include <bits/stdc++.h>
using namespace std;
// Sort odd indexed elements of an array in descending order and
// even indexed elements in ascending order.

void bubble_sort_asc(vector<int> &a)
{
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

void bubble_sort_dsc(vector<int> &a)
{
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] < a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> odd, even;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            even.push_back(a[i]);
        else
            odd.push_back(a[i]);
    }

    bubble_sort_asc(even);
    bubble_sort_dsc(odd);

    int j = 0, k = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            cout << even[j++] << " ";
        else
            cout << odd[k++] << " ";
    }

    return 0;
}