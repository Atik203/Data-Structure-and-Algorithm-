#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &a, int l, int mid, int h)
{
    int n1 = mid - l + 1;
    int n2 = h - mid;
    vector<int> left(n1), right(n2);
    for (int i = 0; i < n1; i++)
        left[i] = a[l + i];
    for (int i = 0; i < n2; i++)
        right[i] = a[mid + 1 + i];
    int i = 0, j = 0, k = l;
    int invCount = 0;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            a[k++] = left[i++];
        }
        else
        {
            a[k++] = right[j++];
            invCount += (n1 - i); // Count inversions
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
    return invCount;
}

int inversionCount(vector<int> &a, int l, int h)
{
    if (l >= h)
        return 0;
    int mid = (l + h) / 2;
    int invCount = inversionCount(a, l, mid);
    invCount += inversionCount(a, mid + 1, h);
    invCount += merge(a, l, mid, h);
    return invCount;
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

    int inversions = inversionCount(a, 0, n - 1);
    cout << "Number of inversions: " << inversions << endl;

    return 0;
}