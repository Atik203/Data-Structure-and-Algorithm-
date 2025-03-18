#include <bits/stdc++.h>
using namespace std;

pair<int, int> findMinMax(vector<int> a, int l, int h)
{
    if (l == h)
        return {a[l], a[l]};
    if (l == h - 1)
        return {min(a[l], a[h]), max(a[l], a[h])};
    else
    {
        int mid = (l + h) / 2;
        pair<int, int> left = findMinMax(a, l, mid);
        pair<int, int> right = findMinMax(a, mid + 1, h);
        return {min(left.first, right.first), max(left.second, right.second)};
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    pair<int, int> result = findMinMax(a, 0, n - 1);
    cout << "Minimum: " << result.first << endl;
    cout << "Maximum: " << result.second << endl;

    return 0;
}