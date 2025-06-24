#include <bits/stdc++.h>
using namespace std;

void coinChangeDP(vector<int> &coins, int amount)
{
    int n = coins.size();

    // DP table: dp[i] = minimum coins needed to make amount i
    vector<int> dp(amount + 1, INT_MAX);
    // Parent array to track which coin was used
    vector<int> parent(amount + 1, -1);

    dp[0] = 0; // Base case: 0 coins needed for amount 0

    // Fill the DP table
    for (int i = 1; i <= amount; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX)
            {
                if (dp[i - coins[j]] + 1 < dp[i])
                {
                    dp[i] = dp[i - coins[j]] + 1;
                    parent[i] = coins[j]; // Track which coin was used
                }
            }
        }
    }

    // Check if solution exists
    if (dp[amount] == INT_MAX)
    {
        cout << "No solution possible for amount " << amount << endl;
        return;
    }

    // Reconstruct the solution
    vector<int> result;
    int curr = amount;
    while (curr > 0)
    {
        result.push_back(parent[curr]);
        curr -= parent[curr];
    }

    // Sort coins for better presentation
    sort(result.begin(), result.end(), greater<int>());

    // Print results
    cout << "Minimum number of coins needed: " << dp[amount] << endl;
    cout << "Coins used: ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];
        if (i < result.size() - 1)
            cout << " + ";
    }
    cout << " = " << amount << endl;

    // Count frequency of each coin
    map<int, int> coinCount;
    for (int coin : result)
    {
        coinCount[coin]++;
    }

    cout << "\nCoin breakdown:" << endl;
    for (auto &pair : coinCount)
    {
        cout << pair.second << " coin(s) of value " << pair.first << endl;
    }
}

int main()
{
    int d, amount;

    cout << "Enter number of coin types: ";
    cin >> d;

    vector<int> coins(d);
    cout << "Enter coin values: ";
    for (int i = 0; i < d; i++)
    {
        cin >> coins[i];
    }

    cout << "Enter amount to make change for: ";
    cin >> amount;

    coinChangeDP(coins, amount);

    return 0;
}