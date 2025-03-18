#include <bits/stdc++.h>
using namespace std;

vector<int> printOdd(vector<int> a, int l, int h)
{
    if (l == h)
    {
        if (a[l] % 2)
            return {a[l]};
        else
            return {};
    }
    else
    {
        int mid = (l + h) / 2;
        vector<int> c1 = printOdd(a, l, mid);
        vector<int> c2 = printOdd(a, mid + 1, h);
        vector<int> c3;
        c3.insert(c3.end(), c1.begin(), c1.end());
        c3.insert(c3.end(), c2.begin(), c2.end());
        return c3;
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
    vector<int> result = printOdd(a, 0, n - 1);
    cout << "Odd: ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}