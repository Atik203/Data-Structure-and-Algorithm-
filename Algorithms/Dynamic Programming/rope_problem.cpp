#include <bits/stdc++.h>
using namespace std;

void ropeDP(vector<int> &ropes, int M, int X)
{
    int n = ropes.size();

    // DP table: dp[i] = minimum cost to make rope of length i
    vector<int> dp(M + 1, INT_MAX);
    // Parent array to track which rope was used
    vector<int> parent(M + 1, -1);

    dp[0] = 0; // Base case: 0 cost for length 0

    // Fill the DP table
    for (int i = 1; i <= M; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (ropes[j] <= i && dp[i - ropes[j]] != INT_MAX)
            {
                // Cost = previous cost + joining cost X (if not the first piece)
                int newCost;
                if (i == ropes[j]) // First piece, no joining cost
                {
                    newCost = 0;
                }
                else // Additional piece, add joining cost
                {
                    newCost = dp[i - ropes[j]] + X;
                }

                if (newCost < dp[i])
                {
                    dp[i] = newCost;
                    parent[i] = ropes[j]; // Track which rope was used
                }
            }
        }
    }

    // Check if solution exists
    if (dp[M] == INT_MAX)
    {
        cout << "No solution possible for length " << M << " meters" << endl;
        return;
    }

    // Reconstruct the solution
    vector<int> result;
    int curr = M;
    while (curr > 0)
    {
        result.push_back(parent[curr]);
        curr -= parent[curr];
    }

    // Sort ropes for better presentation
    sort(result.begin(), result.end(), greater<int>());

    // Calculate total cost
    int totalCost = (result.size() - 1) * X; // (number of pieces - 1) * joining cost

    // Print results
    cout << "\n=== ROPE MAKING SOLUTION ===" << endl;
    cout << "Target length: " << M << " meters" << endl;
    cout << "Joining cost: " << X << " dollars per join" << endl;
    cout << "Minimum total cost: " << totalCost << " dollars" << endl;
    cout << "Number of rope pieces used: " << result.size() << endl;
    cout << "Number of joins needed: " << (result.size() - 1) << endl;

    cout << "\nRope pieces used: ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << "m";
        if (i < result.size() - 1)
            cout << " + ";
    }
    cout << " = " << M << "m" << endl;

    // Count frequency of each rope type
    map<int, int> ropeCount;
    for (int rope : result)
    {
        ropeCount[rope]++;
    }

    cout << "\nRope breakdown:" << endl;
    for (auto &pair : ropeCount)
    {
        cout << pair.second << " rope(s) of length " << pair.first << "m" << endl;
    }

    cout << "\nCost breakdown:" << endl;
    cout << "Rope cost: 0 dollars (infinite supply)" << endl;
    cout << "Joining cost: " << (result.size() - 1) << " joins × " << X << " dollars = " << totalCost << " dollars" << endl;
    cout << "Total cost: " << totalCost << " dollars" << endl;
}

int main()
{
    int d, M, X;

    cout << "=== ROPE MAKING PROBLEM ===" << endl;
    cout << "Enter number of rope types: ";
    cin >> d;

    vector<int> ropes(d);
    cout << "Enter rope lengths: ";
    for (int i = 0; i < d; i++)
    {
        cin >> ropes[i];
    }

    cout << "Enter target rope length (M): ";
    cin >> M;

    cout << "Enter joining cost (X): ";
    cin >> X;

    ropeDP(ropes, M, X);

    return 0;
}
