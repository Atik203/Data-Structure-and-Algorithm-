#include <bits/stdc++.h>
using namespace std;

void coinChangeDP(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<int> dp(amount + 1, INT_MAX);
    vector<int> parent(amount + 1, -1);

    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX)
            {
                if (dp[i - coins[j]] + 1 < dp[i])
                {
                    dp[i] = dp[i - coins[j]] + 1;
                    parent[i] = coins[j];
                }
            }
        }
    }

    if (dp[amount] == INT_MAX)
    {
        cout << "Not possible" << endl;
        return;
    }

    vector<int> result;
    int curr = amount;

    while (curr > 0)
    {
        result.push_back(parent[curr]);
        curr -= parent[curr];
    }
    sort(result.begin(), result.end(), greater<int>());

    cout << "Min coin needed: " << dp[amount] << endl;
    cout << "Coins used: ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    map<int, int> coinCount;
    for (int coin : result)
    {
        coinCount[coin]++;
    }
    cout << "\nCoin breakdown: " << endl;
    for (auto pair : coinCount)
    {
        cout << pair.second << " Coins of value " << pair.first << endl;
    }
}

int main()
{
    int d, amount;
    cout << "Enter types: ";
    cin >> d;
    vector<int> coins(d);
    cout << "Enter coins: ";
    for (int i = 0; i < d; i++)
    {
        cin >> coins[i];
    }
    cout << "Enter the amount: ";
    cin >> amount;

    coinChangeDP(coins, amount);

    return 0;
}