#include <bits/stdc++.h>
using namespace std;

int calcSum(vector<int> a, int l, int h)
{
    if (l == h)
    {
        return a[l];
    }
    else
    {
        int mid = (l + h) / 2;
        int left = calcSum(a, l, mid);
        int right = calcSum(a, mid + 1, h);
        return left + right;
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

    int sum = calcSum(a, 0, n - 1);
    cout << "Sum of the array is: " << sum << endl;

    return 0;
}