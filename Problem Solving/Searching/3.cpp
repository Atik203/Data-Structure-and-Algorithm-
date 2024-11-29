#include <bits/stdc++.h>
using namespace std;
// Find the first element in an array of integers that is greater than a given target. If
// no such element exists, return -1.

int findElement(vector<int> a, int target)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] > target)
        {
            return a[i];
        }
    }
    return -1;
}

int main()
{
    int n, target;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> target;

    cout << findElement(a, target);

    return 0;
}