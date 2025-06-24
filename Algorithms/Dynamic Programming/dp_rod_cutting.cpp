#include <bits/stdc++.h>
using namespace std;

int rodCutting(vector<int> &prices, int n)
{
    vector<int> dp(n + 1, 0);

    // For each length from 1 to n
    for (int i = 1; i <= n; i++)
    {
        // Try all possible first cuts
        for (int j = 1; j <= i; j++)
        {
            dp[i] = max(dp[i], prices[j] + dp[i - j]);
        }
    }

    return dp[n];
}

int main()
{
    int n;
    cout << "Enter rod length: ";
    cin >> n;

    vector<int> prices(n + 1);
    prices[0] = 0;

    cout << "Enter prices for each length:" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << "Length " << i << ": ";
        cin >> prices[i];
    }

    int maxRevenue = rodCutting(prices, n);
    cout << "Maximum revenue: $" << maxRevenue << endl;

    return 0;
}