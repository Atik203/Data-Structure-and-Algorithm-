#include <bits/stdc++.h>
using namespace std;

void solve(int case_number)
{
    long long n;
    cin >> n;

    // Pre-calculate the factorials
    vector<long long> fact(21, 0);
    fact[0] = 1;
    for (int i = 1; i <= 20; i++)
    {
        fact[i] = fact[i - 1] * i;
    }

    vector<int> ans;

    for (int i = 20; i >= 0; i--)
    {
        if (n >= fact[i])
        {
            n -= fact[i];
            ans.push_back(i);
        }
    }

    if (n != 0)
    {
        cout << "Case " << case_number << ": impossible" << endl;
        return;
    }

        sort(ans.begin(), ans.end());

    cout << "Case " << case_number << ": ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "!";
        if (i < ans.size() - 1)
            cout << "+";
    }
    cout << endl;
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