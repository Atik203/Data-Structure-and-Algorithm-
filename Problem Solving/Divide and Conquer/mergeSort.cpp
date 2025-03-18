#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &a, int l, int mid, int h)
{
    int n1 = mid - l + 1;
    int n2 = h - mid;
    vector<int> left(n1), right(n2);
    for (int i = 0; i < n1; i++)
        left[i] = a[l + i];
    for (int i = 0; i < n2; i++)
        right[i] = a[mid + 1 + i];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            a[k++] = left[i++];
        }
        else
        {
            a[k++] = right[j++];
        }
    }
    while (i < n1)
    {
        a[k++] = left[i++];
    }
    while (j < n2)
    {
        a[k++] = right[j++];
    }
}

void mergeSort(vector<int> &a, int l, int h)
{
    if (l < h)
    {
        int mid = (l + h) / 2;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, h);
        merge(a, l, mid, h);
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
    mergeSort(a, 0, n - 1);
    cout << "Sorted array: ";

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}