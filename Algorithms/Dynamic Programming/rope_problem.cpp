#include <bits/stdc++.h>
using namespace std;

int ropeDP(vector<int> &ropes, int M, int X)
{
    vector<int> dp(M + 1, INT_MAX);
    dp[0] = 0; // Base case: 0 cost for length 0

    for (int i = 1; i <= M; i++)
    {
        for (int rope : ropes)
        {
            if (rope <= i && dp[i - rope] != INT_MAX)
            {
                int newCost;
                if (i == rope)
                {
                    newCost = 0; // First piece, no joining cost
                }
                else
                {
                    newCost = dp[i - rope] + X; // Add joining cost
                }
                dp[i] = min(dp[i], newCost);
            }
        }
    }

    return dp[M] == INT_MAX ? -1 : dp[M];
}

int main()
{
    int d, M, X;

    cout << "Enter number of rope types: ";
    cin >> d;

    vector<int> ropes(d);
    cout << "Enter rope lengths: ";
    for (int i = 0; i < d; i++)
    {
        cin >> ropes[i];
    }

    cout << "Enter target length: ";
    cin >> M;

    cout << "Enter joining cost: ";
    cin >> X;

    int result = ropeDP(ropes, M, X);

    if (result == -1)
    {
        cout << "No solution possible" << endl;
    }
    else
    {
        cout << "Minimum cost: " << result << " dollars" << endl;
    }

    return 0;
}