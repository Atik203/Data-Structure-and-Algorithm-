#include <bits/stdc++.h>
using namespace std;

int countEven(vector<int> a, int l, int h)
{
    if (l == h)
    {
        if (a[l] % 2)
            return 0;
        else
            return 1;
    }
    else
    {
        int mid = (l + h) / 2;
        int c1 = countEven(a, l, mid);
        int c2 = countEven(a, mid + 1, h);

        return c1 + c2;
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

    cout << "Even: " << countEven(a, 0, n - 1);

    return 0;
}