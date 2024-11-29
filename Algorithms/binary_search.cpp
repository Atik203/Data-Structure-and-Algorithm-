#include <bits/stdc++.h>
using namespace std;

bool binary_search(vector<int> &a, int high, int low, int key)
{
    int n = a.size();
    while (low <= high)
    {
        int mid = low + (high - low) / 2; // avoid overflow that's why high-low
        if (a[mid] == key)
            return true;
        else if (a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}

int main()
{

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int key;
    cin >> key;

    sort(a.begin(), a.end());
    if (binary_search(a, n - 1, 0, key))
        cout << "Element found" << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}