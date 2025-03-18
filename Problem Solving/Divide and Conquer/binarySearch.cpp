#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &a, int l, int r, int x)
{
    if (l > r)
        return -1;
    int mid = (l + r) / 2;
    if (a[mid] == x)
        return mid;
    else if (a[mid] < x)
        return binarySearch(a, mid + 1, r, x);
    else
        return binarySearch(a, l, mid - 1, x);
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
    int x;
    cin >> x;
    int result = binarySearch(a, 0, n - 1, x);
    if (result == -1)
        cout << "Element not found";
    else
        cout << "Element found at index " << result;
    return 0;
}