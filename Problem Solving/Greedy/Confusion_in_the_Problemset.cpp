#include <bits/stdc++.h>
using namespace std;

void solve(int case_number)
{
    int n;
    cin >> n;
    vector<int> a(n), used(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    bool possible = true;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] >= n)
        {
            possible = false;
            break;
        }
        int pos1 = n - 1 - a[i];
        int pos2 = a[i];
        if (!used[pos1])
        {
            used[pos1] = 1;
        }
        else if (!used[pos2])
        {
            used[pos2] = 1;
        }
        else
        {
            possible = false;
            break;
        }
    }

    cout << "Case " << case_number << ": " << (possible ? "yes" : "no") << '\n';
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve(i);
    }
    return 0;
}